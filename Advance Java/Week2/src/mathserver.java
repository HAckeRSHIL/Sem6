import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JRadioButton;
import javax.swing.JButton;

public class mathserver {

	private JFrame frame;
	private JTextField input;
	private JTextField output;
	private JLabel lblNewLabel_1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					mathserver window = new mathserver();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public mathserver() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		frame.getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);
		
		input = new JTextField();
		input.setBounds(198, 57, 153, 22);
		panel.add(input);
		input.setColumns(10);
		
		output = new JTextField();
		output.setBounds(178, 174, 187, 31);
		panel.add(output);
		output.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Math Server Created by Harshil");
		lblNewLabel.setFont(new Font("Georgia Pro Cond Black", Font.PLAIN, 13));
		lblNewLabel.setBounds(104, 13, 212, 31);
		panel.add(lblNewLabel);
		
		lblNewLabel_1 = new JLabel("Input");
		lblNewLabel_1.setBounds(130, 53, 77, 31);
		panel.add(lblNewLabel_1);
		
		JRadioButton factbtn = new JRadioButton("Factorial");
		factbtn.setBounds(61, 93, 127, 25);
		panel.add(factbtn);
		
		JRadioButton palibtn = new JRadioButton("Palindrome");
		palibtn.setBounds(61, 123, 127, 25);
		panel.add(palibtn);
		
		JRadioButton fibobtn = new JRadioButton("Fibonacci");
		fibobtn.setBounds(205, 88, 98, 25);
		panel.add(fibobtn);
		
		JRadioButton primebtn = new JRadioButton("Prime");
		primebtn.setBounds(205, 123, 98, 25);
		panel.add(primebtn);
		
		JButton runbtn = new JButton("RUN!");
		runbtn.setBounds(311, 106, 109, 25);
		panel.add(runbtn);
		
		JLabel lblNewLabel_2 = new JLabel("Result");
		lblNewLabel_2.setBounds(104, 175, 67, 28);
		panel.add(lblNewLabel_2);
		
		runbtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				// TODO Auto-generated method stub
				String str;
				str=input.getText();
				if(str.isEmpty())
				{
					output.setText("Enter Text First");
				}
				else
				{
				int data=Integer.parseInt(str);
				if(primebtn.isSelected())
				{
					int flag=0;
					for(int i=2;i<data/2;i++)
					{
						if(data%i==0)
						{
							flag=1;
							output.setText(data+" is not Prime.");
							break;
						}
					}
					if(flag==0)
					{
						output.setText(data+" is Prime.");
					}
				}
				else if(palibtn.isSelected())
				{
					StringBuilder rev;
			//		rev=str;
				}
				//	if(rev==rev.reverse())
							{
								output.setText(str+" is Palidrome.");
							}
				//	else
						output.setText(str+" is not Palidrome.");
				}
				
			//	else if(factbtn.isSelected())
				{
					int fact=1;
				//	for(int i=data;i>0;i--)
					{
				//*=i;
					}
				}
			//	else if(fibobtn.isSelected())
				{
					
				}
				}
			
		});
	
	}
}
