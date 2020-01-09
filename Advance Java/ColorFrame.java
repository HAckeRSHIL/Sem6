
import javax.swing.*; 
import java.awt.*; 

public class ColorFrame {

	public static void main(String[] args) {
		
		JFrame f= new JFrame("Panel Example");    
        JPanel panel=new JPanel();  
        panel.setBounds(0,0,400,200);    
        panel.setBackground(Color.gray);  
        JPanel b1=new JPanel();     
        b1.setBounds(0,200,400,200);    
        b1.setBackground(Color.yellow);   
        JPanel b2=new JPanel();   
        b2.setBounds(0,400,400,200);    
        b2.setBackground(Color.green);   
        f.add(panel);
        f.add(b1);
        f.add(b2);
        f.setSize(400,600);    
        f.setLayout(null);    
        f.setVisible(true);    
		

	}

}
