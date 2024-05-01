import java.util.concurrent.TimeUnit;

public class Server{
    
    public static void admin(Eventi eventi){
        try{
            eventi.Aggiungi("Torneo", 1);
            eventi.Aggiungi("Assemblea", 2);
            TimeUnit.SECONDS.sleep(2);
            eventi.Chiudi("Torneo");
            eventi.Chiudi("Riunione");
            eventi.Chiudi("Appuntamento");

        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void client(Eventi eventi){
        try{
            eventi.Prenota("Torneo", 5);
            eventi.Prenota("Appuntamento", 5);
            eventi.Prenota("Lavoro", 5);
            
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void main(String[] args){
        Eventi eventi = new Eventi();

        // Forziamo la creazione (e la rispettiva partenza dei thread) rispetto ai thread che elaborano gli eventi
        // questo evita il caso in cui vengono modificati eventi non ancora esistenti (ovvero venga schedula prima la seconda coppia thread)
        Thread t1 = new Thread(() -> {
            try{
                eventi.Crea("Torneo", 55);
                eventi.Crea("Riunione", 10);
                TimeUnit.SECONDS.sleep(2);
                eventi.Crea("Assemblea", 25);
            }catch(Exception e){
                e.printStackTrace();
            }
            
        });
        Thread t2 = new Thread(() -> {
            try{
                eventi.Crea("Partita", 15);
                eventi.Crea("Lavoro", 13);
                eventi.Crea("Appuntamento", 22);
            }catch(Exception e){
                e.printStackTrace();
            }
            
        });
        t1.start();
        t2.start();

        /* Attendo la terminazione dei thread */
        try{
            t1.join();
            t2.join();
            
        } catch(Exception e){
            e.printStackTrace();
        }

        Thread t3 = new Thread(() -> admin(eventi));
        Thread t4 = new Thread(() -> client(eventi));
        t3.start();
        t4.start();
        
        /* Attendo la terminazione dei thread */
        try{
            t3.join();
            t4.join();
            
        } catch(Exception e){
            e.printStackTrace();
        }

        /* Infine stampo gli eventi ancora aperti, con i rispettivi posti disponibili */
        eventi.ListaEventi(); // mi aspetto Assemblea con 7 posti, Lavoro con 8 posti e Partita con 15
    }
}