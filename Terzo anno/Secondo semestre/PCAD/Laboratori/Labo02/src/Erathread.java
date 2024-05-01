import java.util.Vector;
import java.util.concurrent.*;

public class Erathread implements Runnable{
    
    private int prime; // primo divisore proprio al thread
    private Vector<Integer> v; // vettore dei risultati
    private BlockingQueue<Integer> prevQueue;
    private BlockingQueue<Integer> nextQueue;
    private int N; // max dimension

    public static ExecutorService executor;

    public Erathread(int p, Vector<Integer> v, BlockingQueue<Integer> prevQueue, int N){
        this.prime = p;
        this.v = v;
        this.prevQueue = prevQueue;
        this.nextQueue = null;
        this.N = N;
    }
    
    public void run(){
        while(true){
            int num = -1;
            try {
                num = prevQueue.take();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if(num == -1){
                try {
                    if(nextQueue != null){
                        nextQueue.put(num);
                    }
                    else{
                        executor.shutdown(); // l'ultimo thread (definitivo) determina la chiusura 'graceful'
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                return; // questo thread termina, avendo incontrato il 'terminatore' -1
            }
            
            // Controllo se prime è divisore di num -> in caso rigettiamo (continue) il valore in quanto non primo
            if(num % prime == 0) continue;

            if(nextQueue == null){
                // num è primo
                
                // Non è necessario synchronized perché è sempre al massimo un thread che tocca il vettore dei risultati,
                // ovvero l'ultimo della serie di thread creati (da cui potrebbero generarsene di nuovi)
                v.add(num);

                // Non creo altri thread se ho superato sqrt(N)
                if(num >= Math.sqrt(N)) continue;

                nextQueue = new LinkedBlockingQueue<Integer>();
                executor.execute(new Erathread(num, v, nextQueue, N));
            }
            else{
                try {
                    nextQueue.put(num);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
