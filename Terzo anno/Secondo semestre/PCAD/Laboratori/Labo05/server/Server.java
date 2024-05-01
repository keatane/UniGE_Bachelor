import java.util.*;
import java.net.*;
import java.io.*;

public class Server{
    
    public Server(int port){

        Eventi eventi = new Eventi();
        ServerSocket listener;
        Socket connection;

        try {
            listener = new ServerSocket(port);
            while (true) {
                connection = listener.accept();
                RequestHandler handler = new RequestHandler(connection, eventi);
                handler.start();
            } 
        } catch (Exception e) {e.printStackTrace();}

    }

    public static void main(String[] args){
        new Server(5555);
    }
}