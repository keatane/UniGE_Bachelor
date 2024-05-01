import java.util.concurrent.*;

public class Eventi{
    
    private ConcurrentHashMap<String, Integer> ListaEventi; // sincronizza a livello di 'segmento' (bucket): lock in scrittura, non in lettura/retrieving'

    public Eventi(){
        ListaEventi = new ConcurrentHashMap<String, Integer>();
    }

    // Dichiarazione di funzioni ausiliarie
    private void checkPosti(Integer Posti) throws Exception{
        if(Posti < 0){
            throw new Exception("Posti di numero negativo");
        }
    }

    /* Creazione di un evento */
    public void Crea(String Nome, Integer Posti) throws Exception{ // synchronized può essere omesso perchè Posti è locale e putIfAbsent è thread-safe sulla ConcurrentHashMap
        checkPosti(Posti);
        ListaEventi.putIfAbsent(new String(Nome),Posti); // creiamo nuove stringhe per ovviare al problema dello String caching (same reference)
    }

    /* Aggiunta posti ad un evento */
    public void Aggiungi(String Nome, Integer Posti) throws Exception{
        checkPosti(Posti);

        synchronized(ListaEventi.get(Nome)){
            if (!ListaEventi.containsKey(Nome)){
                throw new Exception("Evento non esistente");
            }

            Posti += ListaEventi.get(Nome);
            ListaEventi.put(Nome,Posti).notifyAll();
        }
    }

    /* Prenotazione (rimozione posti) ad un evento */
    public void Prenota(String Nome, Integer Posti) throws Exception{
        checkPosti(Posti);
        int newPosti = 0;
        synchronized(ListaEventi.get(Nome)){
            if (!ListaEventi.containsKey(Nome)) return;

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
    public void ListaEventi(){
        synchronized(ListaEventi){ // lock su tutti i segmenti, per permettere una stampa consistente
            System.out.println("\n--- Stampa eventi ancora aperti ---");
            System.out.println("*Nome evento*" + " --- " + "*Posti disponibili*");
            for(String evento : ListaEventi.keySet()){
                System.out.println(evento + " --- " + ListaEventi.get(evento));
            }
        }
    }

    /* Chiusura evento e rilascio thread in attesa */
    public void Chiudi(String Nome) throws Exception{
        synchronized(ListaEventi.get(Nome)){
            if (!ListaEventi.containsKey(Nome)){
                throw new Exception("Evento non esistente");
            }
            
            ListaEventi.remove(Nome).notifyAll(); // chi è in attesa viene risvegliato
        }
    }
}