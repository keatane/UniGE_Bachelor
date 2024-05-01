import java.awt.event.*;

public class MyListenerVar implements ActionListener {
    private GUIVar frame;
    private ThreadWorker worker;
    
    public MyListenerVar(GUIVar frame) {
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

        worker = new ThreadWorker(frame);
        worker.execute();
    }
}