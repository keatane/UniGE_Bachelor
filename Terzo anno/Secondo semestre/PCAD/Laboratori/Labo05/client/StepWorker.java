import java.io.*;
import java.util.concurrent.ExecutionException;
import javax.swing.*;
import java.util.concurrent.TimeUnit;

/*
* SwingWorker che ritorna una stringa come risultato finale
* e non produce risultati intermedi (Void)
*/
public class StepWorker extends SwingWorker<String, Void> {
    private GUI frame;
    private int id = -1;
    String field1 = "";
    String field2 = "";
    String response = "";
    DataInputStream is;
    
    public StepWorker(GUI frame, int id, String field1, String field2) {
        this.frame = frame;
        this.id = id;
        this.field1 = field1;
        this.field2 = field2;
    }
    
    @Override
    protected String doInBackground() throws Exception {
        System.out.println("Ciao, sono " + Thread.currentThread().getName() + " ed eseguo doInBackground()");
        
        String message;
        try {
            // TimeUnit.SECONDS.sleep(2);
            switch(id){
                case 0: // crea
                    message = "CREATE " + field1 + " " + field2;
                    break;
                case 1: // aggiungi
                    message = "ADD " + field1 + " " + field2;
                    break;
                case 2: // prenota
                    message = "BOOK " + field1 + " " + field2;
                    break;
                case 3: // rimuovi
                    message = "DELETE " + field1;
                    break;
                case 4: // stampa
                    message = "PRINT";
                    break;
                default:
                    return "error in stepworker";
            }

            DataInputStream is = frame.client.contactServer(message);

            String response_ok = "";

            char ch = 0;

            // Request handled
            for(short i = 0; i < 30; i++){
                try{
                    ch = (char)is.readByte();
                } catch(IOException e){
                    e.printStackTrace();
                }

                if(ch == '\n' || ch == '\u0000' || ch == '\r'){
                    i++; 
                    break;
                }
                response_ok += ch;
            }
            String handled = response_ok;
            SwingUtilities.invokeAndWait(new Runnable(){
                @Override
                public void run(){
                    frame.responseText.setText(handled);
                }
            });

            ch = 0;
            if(id == 4) {
                String copy = "";
                try{ch = (char)is.readByte();}catch(IOException e){} // per rimuovere white space precedenti
                while(true){
                    try{
                        ch = (char)is.readByte();
                    } catch(IOException e){
                        break;
                    }

                    if(ch == '#'){ // per forzare il ritorno a capo (ma non la fine lettura)
                        copy += '\n';
                        continue;        
                    }

                    if(ch == '\n' || ch == '\u0000' || ch == '\r'){
                        break;
                    }

                    copy += ch;
                }

                String listaEventi = copy;
                SwingUtilities.invokeAndWait(new Runnable(){
                    @Override
                    public void run(){
                        frame.eventTable.setEditable(true);
                        frame.eventTable.setText(listaEventi);
                        frame.eventTable.setEditable(false);
                    }
                });
            }

        // Request executed
        ch = 0;
        response_ok = "";
        for(short i = 0; i < 30; i++){
            try{
                ch = (char)is.readByte();
            } catch(IOException e){
                e.printStackTrace();
            }

            if(ch == '\n' || ch == '\u0000' || ch == '\r'){
                break;
            }
            response_ok += ch;
        }

        
        response = String.valueOf(response_ok);

        } catch(Exception e){
            e.printStackTrace();
        }
        return "";
    }

    @Override
    protected void done() { // chiamato dopo doInBackground ed eseguito dall’EDT
        frame.responseText.setText(response);
        return;
    }
}