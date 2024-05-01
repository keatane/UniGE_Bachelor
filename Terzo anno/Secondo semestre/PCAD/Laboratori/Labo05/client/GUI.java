import java.awt.*;
import javax.swing.*;

public class GUI extends JFrame {
    
    int counter;
    Client client;

    JTextField eventField;
    JTextField seatField;
    JLabel responseText;
    JTextArea eventTable;

    public GUI(Client client){
        super("Gestore eventi");

        this.client = client;

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        
        JPanel buttonPanel = new JPanel();

        JButton createButton = new JButton("CREATE");
        buttonPanel.add(createButton);

        JButton addButton = new JButton("ADD");
        buttonPanel.add(addButton);

        JButton bookButton = new JButton("BOOK");
        buttonPanel.add(bookButton);

        JButton deleteButton = new JButton("DELETE");
        buttonPanel.add(deleteButton);

        JButton printButton = new JButton("PRINT");
        buttonPanel.add(printButton);

        JPanel textPanel = new JPanel();
        eventField = new JTextField("Nome_evento");
        seatField = new JTextField("Numero_posti");
        responseText = new JLabel("Server response");
        textPanel.add(eventField);
        textPanel.add(seatField);
        textPanel.add(responseText);

        JPanel eventPanel = new JPanel();
        eventTable = new JTextArea(5,25);
        eventTable.setText("Nome evento --- Posti disponibili");
        eventTable.setEditable(false);
        eventPanel.add(eventTable);
        
        

        // Gestione listener 
        MyListener listener = new MyListener(this); 
        createButton.setActionCommand("CREATE");
        addButton.setActionCommand("ADD");
        bookButton.setActionCommand("BOOK");
        deleteButton.setActionCommand("DELETE");
        printButton.setActionCommand("PRINT");

        createButton.addActionListener(listener);
        addButton.addActionListener(listener);
        bookButton.addActionListener(listener);
        deleteButton.addActionListener(listener);
        printButton.addActionListener(listener);
        
        getContentPane().add(buttonPanel, BorderLayout.NORTH);
        getContentPane().add(responseText, BorderLayout.SOUTH);
        getContentPane().add(textPanel, BorderLayout.WEST);
        getContentPane().add(eventPanel, BorderLayout.EAST);
        
        setMinimumSize(new Dimension(600, 400));
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
    }