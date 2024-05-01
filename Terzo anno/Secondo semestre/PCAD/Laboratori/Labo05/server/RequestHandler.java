import java.util.*;
import java.net.*;
import java.io.*;

public class RequestHandler extends Thread {
    
    PrintWriter outgoing; // Stream for sending data.
    Eventi eventHandler;
    Socket socket;
    short _operation = -1;
    String _event;
    Integer _seats;


    public RequestHandler(Socket socket, Eventi eventHandler){
        this.socket = socket;
        this.eventHandler = eventHandler;
    }

    private void readInput(DataInputStream input) throws Exception{
        
            // Dichiaro gli argomenti dell'input, terminatori di stringa inclusi
            String param1 = ""; // 7 max size
            String param2 = "";
            String param3 = ""; // 5 max size

            char ch = 0;

            // Controlliamo il comando passato
            for(short i = 0; i < 7; i++){
                try{
                    ch = (char)input.readByte();
                } catch(IOException e){
                    e.printStackTrace();
                }

                if(ch == ' ' || ch == '\n' || ch == '\u0000' || ch == '\r'){
                    break;
                }
                param1 += ch;
            }

            // Controlliamo se la stringa passata è uno dei comandi noti
            if(param1.equals("CREATE")){
                _operation = 0;
            } else if(param1.equals("ADD")){
                _operation = 1;
            } else if(param1.equals("BOOK")){
                _operation = 2;
            } else if(param1.equals("DELETE")){
                _operation = 3;
            } else if(param1.equals("PRINT")){
                _operation = 4;
                return; // non raccogliamo ulteriori input in caso di stampa
            } else{
                System.out.println("ERROR: Bad command");
            }
            
            // Raccogliamo il nome dell'evento
            while (true){
                try{
                    ch = (char)input.readByte();
                } catch(IOException e){
                    e.printStackTrace();
                }

                if(ch == ' ' || ch == '\n' || ch == '\u0000' || ch == '\r'){
                    break;
                }
                param2 += ch;
            }

            _event = param2;

            // Controlliamo se l'operazione era la cancellazione, il numero posti non interessa
            if(_operation == 3) return;

            // Raccogliamo il numero di posti
            for(short i = 0; i < 5; i++){
                try{
                    ch = (char)input.readByte();
                } catch(IOException e){
                    e.printStackTrace();
                }

                if(ch == ' ' || ch == '\n' || ch == '\u0000' || ch == '\r'){ 
                    break;
                }
                param3 += ch;
            }

            try{
                _seats = Integer.valueOf(param3);
            } catch(NumberFormatException e){
                System.out.println("ERROR: Bad type seat variable");
            }
    }

    @Override
    public void run() {
        PrintWriter outgoing;
        try{
            // Stream for sending data.
            outgoing = new PrintWriter(socket.getOutputStream());
            outgoing.println("Server: Request handled");
            outgoing.flush(); // Make sure the data is actually sent!
        } catch(Exception e) {e.printStackTrace();}
        
        DataInputStream input = null;
        try{
            input = new DataInputStream(socket.getInputStream());
        } catch(IOException e){
            e.printStackTrace();
        }
        
        try{
            readInput(input);
        } catch(Exception e){
            e.printStackTrace();
        }

        // Controlliamo l'operazione da fare
        try{
            switch(_operation){
                case 0:
                    crea();
                    break;
                case 1:
                    aggiungi();
                    break;
                case 2:
                    prenota();
                    break;
                case 3:
                    rimuovi();
                    break;
                case 4:
                    stampa();
                    break;
            }

        outgoing = new PrintWriter(socket.getOutputStream());
        outgoing.println("Server: Request executed");
        outgoing.flush();
        System.out.println("DEBUG socket closing\n");
        socket.close();
        } catch(Exception e) {e.printStackTrace();}
    }

    // protocollo: CREATE, ADD, BOOK, DELETE

    private void crea() throws Exception{
        eventHandler.Crea(_event, _seats);
    }

    private void aggiungi() throws Exception{
        eventHandler.Aggiungi(_event, _seats);
    }

    private void prenota() throws Exception{
        eventHandler.Prenota(_event, _seats);
    }

    private void rimuovi() throws Exception{
        eventHandler.Chiudi(_event);
    }

    private void stampa() throws Exception{
        outgoing = new PrintWriter(socket.getOutputStream());
        eventHandler.stampaListaEventi(outgoing);
    }
}
