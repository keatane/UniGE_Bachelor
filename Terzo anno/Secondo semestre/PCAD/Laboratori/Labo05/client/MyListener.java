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
        int operation = -1; 
        if(command.equals("CREATE")){
            operation = 0;
        } else if(command.equals("ADD")){
            operation = 1;
        } else if(command.equals("BOOK")){
            operation = 2;
        } else if(command.equals("DELETE")){
            operation = 3;
        } else if(command.equals("PRINT")){
            operation = 4;
        } else{
            return;
        }
        toWork(operation);
    }
    
    private void toWork(int id) { // eseguito da EDT

        worker = new StepWorker(frame, id, frame.eventField.getText(), frame.seatField.getText());
        frame.eventField.setText("Nome_evento");
        frame.seatField.setText("Numero_posti");
        worker.execute();
    }
}