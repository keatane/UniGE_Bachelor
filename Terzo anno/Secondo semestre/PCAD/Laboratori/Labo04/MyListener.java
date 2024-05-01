import java.awt.event.*;

public class MyListener implements ActionListener {
    private GUI frame;
    private StepWorker worker;
    
    public MyListener(GUI frame) {
        this.frame = frame;
    }

    @Override
    public void actionPerformed(ActionEvent e) { // eseguito da EDT
        String command = e.getActionCommand();
        if (command != "step") return;
        step();
    }
    
    private void step() { // eseguito da EDT
        frame.step.setEnabled(false);
        // creo ed avvio SwingWorker che eseguira’ la ricerca
        worker = new StepWorker(frame);
        worker.execute();
    }
}