import java.util.concurrent.*;

public class Eventi{
    
    private ConcurrentHashMap<String, Integer> ListaEventi; // da testare se fare concurrent visti i synchronized

    public Eventi(){
        ListaEventi = new ConcurrentHashMap<String, Integer>();
    }

    // Dichiarazione di funzioni ausiliarie
    private void checkNome(String Nome) throws Exception{
        if(!ListaEventi.containsKey(Nome)){
            throw new Exception("Evento non esistente");
        }
    }

    private void checkPosti(Integer Posti) throws Exception{
        if(Posti < 0){
            throw new Exception("Posti di numero negativo");
        }
    }

    /* Creazione di un evento */
    public void Crea(String Nome, Integer Posti) throws Exception{ // synchronized può essere omesso perchè Posti è locale e putIfAbsent è thread-safe sulla ConcurrentHashMap
        checkPosti(Posti);
        ListaEventi.putIfAbsent(Nome,Posti);
    }

    /* Aggiunta posti ad un evento */
    public synchronized void Aggiungi(String Nome, Integer Posti) throws Exception{
        checkNome(Nome);
        checkPosti(Posti);
        Posti += ListaEventi.get(Nome);
        ListaEventi.put(Nome,Posti);
        this.notifyAll();
    }

    /* Prenotazione (rimozione posti) ad un evento */
    public synchronized void Prenota(String Nome, Integer Posti) throws Exception{
        checkNome(Nome);
        checkPosti(Posti);

        int newPosti = ListaEventi.get(Nome) - Posti;

        while(newPosti < 0){
            this.wait();
            if(!ListaEventi.containsKey(Nome))
                return; // nel caso in cui l'evento fosse stato chiuso nel frattempo
            newPosti = ListaEventi.get(Nome) - Posti;
        }
        ListaEventi.put(Nome,newPosti);
    }

    /* Stampa eventi e numero posti disponibili */
    public synchronized void ListaEventi(){
        System.out.println("--- Stampa eventi ancora aperti ---");
        System.out.println("*Nome evento*" + "---" + "*Posti disponibili*");
        for(String evento : ListaEventi.keySet()){
            System.out.println(evento + " --- " + ListaEventi.get(evento));
        }
    }

    /* Chiusura evento e rilascio thread in attesa */
    public synchronized void Chiudi(String Nome) throws Exception{
        checkNome(Nome);
        ListaEventi.remove(Nome);
        this.notifyAll(); // chi è in attesa viene risvegliato
    }
}