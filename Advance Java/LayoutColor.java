import javax.swing.*; 
import java.awt.*; 

public class LayoutColor {

	public static void main(String[] args) {
		JFrame f= new JFrame();    
        JPanel panel=new JPanel();      
        panel.setBackground(Color.orange);  
        JPanel b1=new JPanel();         
        b1.setBackground(Color.white);   
        JPanel b2=new JPanel();       
        b2.setBackground(Color.green);   
        f.add(panel);
        f.add(b1);
        f.add(b2);
        f.setLayout(new GridLayout(3,1));  
        f.setSize(400,600);   
        f.setVisible(true);    

	}

}
