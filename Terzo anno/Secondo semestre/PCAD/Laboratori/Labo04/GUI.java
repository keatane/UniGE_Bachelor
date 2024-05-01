import java.awt.*;
import javax.swing.*;

public class GUI extends JFrame {
    JButton step;
    JLabel fase;
    int counter;

    public GUI(){
        super("Titolo");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        counter = 1;

        JPanel pannelloSuperiore = new JPanel();
        fase = new JLabel("Fase 1");

        JPanel pannelloInferiore = new JPanel();
        step = new JButton("STEP");
        step.setEnabled(true);

        MyListener listener = new MyListener(this); 
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
            new GUI();
        }
        };
        // creo la GUI nell’EDT
        SwingUtilities.invokeLater(init);
        }
    }