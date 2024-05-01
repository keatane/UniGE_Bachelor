import java.util.Vector;
import java.util.concurrent.*;

public class Eratostene {

    int N;
    Vector<Integer> res;
    ExecutorService executor;

    public Eratostene(int N){
        this.N = N;
        res = new Vector<Integer>();
        executor = Executors.newCachedThreadPool();
    }

    public void findPrimes(){
        if(N < 2) return;
        Erathread.executor = executor;
        res.add(2);

        BlockingQueue<Integer> firstQueue = new LinkedBlockingQueue<Integer>();

        executor.execute(new Erathread(2, res, firstQueue, N));
        for(int i = 3; i <= N; i++){
            try {
                firstQueue.put(i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Mettiamo il 'terminatore' di thread
        try {
            firstQueue.put(-1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Aspettiamo la terminazione di tutti i thread (e l'esecuzione dei corrispondenti task)
        try {
            while(!executor.awaitTermination(2, TimeUnit.MINUTES)){
                System.out.println("Thread pool did not terminate, repeating await");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Qui siamo sicuri di avere il vettore di risultati completo (e i precedentemente creati thread chiusi)
        System.out.println("Numeri primi trovati: "  + res.size());
        for(int i = 0; i < res.size(); i++){
            System.out.print(res.get(i));
            System.out.print(" ");
        }
    }

    public static void main(String[] args) throws Exception {
        if(args.length < 1){
            System.out.println("Please, pass a number!");
            System.exit(1);
            return;
        }

        int N = Integer.parseInt(args[0]);
        
        Eratostene era = new Eratostene(N);
        era.findPrimes();
    }
}
