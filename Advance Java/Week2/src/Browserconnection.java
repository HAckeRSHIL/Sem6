import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException; 
import java.net.ServerSocket; 
import java.net.Socket; 
import java.util.Date;
 public class Browserconnection 
 { 
	 public static void main(String args[]) throws IOException
	 { 
	 ServerSocket server2 = new ServerSocket(4488);
	 System.out.println("Listening for connection on port "+server2.getLocalPort());
	 	while (true) 
	 	{ 
	 		try (Socket socket = server2.accept()) 
	 		{ 
	 			 File file = new File("C:\\CODING\\SEM 6 IT\\WTP\\WT\\Practical 1\\Practical_1.html"); 
	 			  BufferedReader br = new BufferedReader(new FileReader(file)); 
	 			  String st;
	 			  String forward=new String();
	 			  while ((st = br.readLine()) != null) 
	 				  forward=forward+ st;
	 			String httpResponse = "HTTP/1.1 200 OK\r\n\r\n" + forward; 
	 			socket.getOutputStream().write(httpResponse.getBytes("UTF-8"));
	 		}
	 	}	 
	 }	 	
}


