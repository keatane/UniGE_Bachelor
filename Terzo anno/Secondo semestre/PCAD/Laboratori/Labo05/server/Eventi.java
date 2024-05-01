import java.io.PrintWriter;
import java.util.concurrent.*;

public class Eventi{
    
    private ConcurrentHashMap<String, Integer> ListaEventi; // sincronizza a livello di 'segmento' (bucket): lock in scrittura, non in lettura/retrieving'

    public Eventi(){
        ListaEventi = new ConcurrentHashMap<String, Integer>();
    }

    // Dichiarazione di funzioni ausiliarie
    private void checkPosti(Integer Posti){
        if(Posti == null){
            System.out.println("ERROR: Posti non pervenuti");
        } else if(Posti != (int)Posti){
            System.out.println("ERROR: Posti non numerici");
        } else if(Posti < 0){
            System.out.println("ERROR: Posti di numero negativo");
        }
    }

    /* Creazione di un evento */
    public void Crea(String Nome, Integer Posti) throws Exception{ // synchronized può essere omesso perchè Posti è locale e putIfAbsent è thread-safe sulla ConcurrentHashMap
        checkPosti(Posti);
        ListaEventi.putIfAbsent(new String(Nome),Posti); // creiamo nuove stringhe per ovviare al problema dello String caching (same reference)
    }

    /* Aggiunta posti ad un evento */
    public void Aggiungi(String Nome, Integer Posti){
        checkPosti(Posti);

        if (!ListaEventi.containsKey(Nome)){
            System.out.println("Evento non esistente");
        }

        synchronized(ListaEventi.get(Nome)){

            Posti += ListaEventi.get(Nome);
            ListaEventi.put(Nome,Posti).notifyAll();
        }
    }

    /* Prenotazione (rimozione posti) ad un evento */
    public void Prenota(String Nome, Integer Posti) throws Exception{
        checkPosti(Posti);
        int newPosti = 0;
        if (!ListaEventi.containsKey(Nome)) return;
        synchronized(ListaEventi.get(Nome)){

            newPosti = ListaEventi.get(Nome) - Posti;
            while(newPosti < 0){
                ListaEventi.get(Nome).wait();
                if(!ListaEventi.containsKey(Nome)) return; // nel caso in cui l'evento fosse stato chiuso nel frattempo (e quindi è stato notificato -> risvegliato)
                newPosti = ListaEventi.get(Nome) - Posti;
            }

            // Teniamo il lock sul segmento, onde evitare che l'evento venga chiuso poco prima della modifica (Nome == null)
            ListaEventi.put(Nome, newPosti);
        }
    }

    /* Stampa eventi e numero posti disponibili */
    public void stampaListaEventi(PrintWriter outgoing){
         synchronized(ListaEventi){ // lock su tutti i segmenti, per permettere una stampa consistente
                for(String evento : ListaEventi.keySet()){
                    outgoing.print(evento + " --- " + ListaEventi.get(evento) + "#");
                }
            outgoing.print("\n");
            outgoing.flush();
        }
    }

    /* Chiusura evento e rilascio thread in attesa */
    public void Chiudi(String Nome) throws Exception{
        if (!ListaEventi.containsKey(Nome)){
            System.out.println("Evento non esistente");
        }
        
        synchronized(ListaEventi.get(Nome)){
            ListaEventi.remove(Nome).notifyAll(); // chi è in attesa viene risvegliato
        }
    }
}