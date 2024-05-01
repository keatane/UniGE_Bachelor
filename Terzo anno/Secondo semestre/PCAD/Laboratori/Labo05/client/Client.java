import javax.swing.*;
import java.net.*;
import java.io.*;

public class Client {

    final static String IP_ADDRESS = "192.168.88.179";
    Socket socket;

    public Client(){
        Client client = this;
        Runnable init = new Runnable() {
            public void run() {
                new GUI(client);
            }
        };
        // creo la GUI nell’EDT
        SwingUtilities.invokeLater(init);
    }

    public DataInputStream contactServer(String message){
        try {
            socket = new Socket(IP_ADDRESS, 5555);

            PrintWriter outgoing;
            
            InputStream is = socket.getInputStream();
            DataInputStream netIn = new DataInputStream(is);

            outgoing = new PrintWriter(socket.getOutputStream());
            outgoing.println(message);
            outgoing.flush();

            return netIn;
            
        } catch (Exception e) {e.printStackTrace(); return null;}
    }

    public static void main(String[] args){
        new Client();
    }
}
