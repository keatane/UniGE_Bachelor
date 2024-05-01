import java.awt.*;
import javax.swing.*;

public class GUIVar extends JFrame {
    JButton step;
    JLabel fase;
    int counter;

    public GUIVar(){
        super("Titolo");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        counter = 1;

        JPanel pannelloSuperiore = new JPanel();
        fase = new JLabel("Fase 1");

        JPanel pannelloInferiore = new JPanel();
        step = new JButton("STEP");
        step.setEnabled(true);

        MyListenerVar listener = new MyListenerVar(this); 
        step.setActionCommand("step");
        step.addActionListener(listener);

        pannelloSuperiore.add(fase);
        pannelloInferiore.add(step);
        
        getContentPane().add(pannelloSuperiore, BorderLayout.PAGE_START);
        getContentPane().add(pannelloInferiore, BorderLayout.PAGE_END);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
    public static void main(String[] args) {
        Runnable init = new Runnable() {
        public void run() {
            new GUIVar();
        }
        };
        // creo la GUI nell’EDT
        SwingUtilities.invokeLater(init);
        }
    }