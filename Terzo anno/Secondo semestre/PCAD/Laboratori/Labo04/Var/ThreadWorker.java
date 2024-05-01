import java.util.concurrent.TimeUnit;

import javax.swing.SwingUtilities;

public class ThreadWorker extends Thread{
    private GUIVar frame;
    
    public ThreadWorker(GUIVar frame) {
        this.frame = frame;
    }
    
    public void execute(){
        new Thread(new Runnable(){
            @Override
            public void run(){
                // doInBackground()
                try{
                    System.out.println("Ciao, sono " + Thread.currentThread().getName() + " ed eseguo doInBackground()");
                    TimeUnit.SECONDS.sleep(2);
                    SwingUtilities.invokeLater(new Runnable() {
                        @Override
                        public void run(){
                            // done(), lanciato da EDT grazie a invokeLater
                            System.out.println("Ciao, sono " + Thread.currentThread().getName() + " ed eseguo done()");
                            frame.step.setEnabled(true);
                            frame.counter += 1;
                            frame.fase.setText("Fase: " + frame.counter);
                        }
                    });
                } catch(InterruptedException e){
                    e.printStackTrace();
                }
            }
        }).start();
    }
}