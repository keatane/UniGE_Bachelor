import java.util.concurrent.ExecutionException;
import javax.swing.*;
import javax.swing.tree.ExpandVetoException;
import java.util.concurrent.TimeUnit;

/*
* SwingWorker che ritorna una stringa come risultato finale
* e non produce risultati intermedi (Void)
*/
public class StepWorker extends SwingWorker<String, Void> {
    private GUI frame;
    
    public StepWorker(GUI frame) {
        this.frame = frame;
    }
    
    @Override
    protected String doInBackground() throws Exception {
        System.out.println("Ciao, sono " + Thread.currentThread().getName()
        + " ed eseguo doInBackground()");
        try {
            TimeUnit.SECONDS.sleep(2);
        } catch(Exception e){
            e.printStackTrace();
        }

        return "";
    }

    @Override
    protected void done() { // chiamato dopo doInBackground ed eseguito dall’EDT
        System.out.println("Ciao, sono " + Thread.currentThread().getName()
        + " ed eseguo done()");
        frame.step.setEnabled(true);
        frame.counter += 1;
        frame.fase.setText("Fase " + frame.counter);
    }
}