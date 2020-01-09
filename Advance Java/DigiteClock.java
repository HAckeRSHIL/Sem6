import javax.swing.*;  
import java.awt.*;  
import java.text.*;  
import java.util.*; 

public class DigiteClock implements Runnable{  
	JFrame f;  
	Thread t=null;  
	int hours=0, minutes=0, seconds=0;  
	String timeString = "";  
	JButton b;  
	  
	DigiteClock(){  
	    f=new JFrame();    
	    t=new Thread(this);  
	    t.start();  
	      
	    b=new JButton();  
	    b.setBounds(100,100,100,50);  
	      
	    f.add(b);  
	    f.setSize(300,400);  
	    f.setLayout(null);  
	    f.setVisible(true);  
	}  
  
	public void run() {  
		try {  
			while (true) {  
				Calendar cal = Calendar.getInstance();  
				hours = cal.get( Calendar.HOUR_OF_DAY );  
	
				minutes = cal.get( Calendar.MINUTE );  
				seconds = cal.get( Calendar.SECOND );  
  
				SimpleDateFormat formatter = new SimpleDateFormat("hh:mm:ss");  
				Date date = cal.getTime();  
				timeString = formatter.format( date );  
				b.setText(timeString);    
			}  
		}  
		catch (Exception e) { }  
	}  
  
	public static void main(String[] args) {  
    	new DigiteClock();  
	}  
} 
