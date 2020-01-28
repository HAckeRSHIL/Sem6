import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JTextField;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.border.BevelBorder;
import java.awt.Component;
import javax.swing.SwingConstants;
import javax.swing.UIManager;

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
		frame.setBounds(100, 100, 518, 341);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		frame.getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);
		
		input = new JTextField();
		input.setBounds(177, 79, 153, 22);
		panel.add(input);
		input.setColumns(10);
		
		output = new JTextField();
		output.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		output.setBounds(96, 205, 316, 41);
		panel.add(output);
		output.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("Math Server Created by Harshil");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		lblNewLabel.setFont(new Font("Segoe UI", Font.PLAIN, 20));
		lblNewLabel.setBounds(107, 13, 305, 41);
		panel.add(lblNewLabel);
		ButtonGroup G1 = new ButtonGroup();
		lblNewLabel_1 = new JLabel("Input");
		lblNewLabel_1.setBounds(112, 75, 77, 31);
		panel.add(lblNewLabel_1);
		
		JRadioButton factbtn = new JRadioButton("Factorial");
		factbtn.setBounds(108, 122, 127, 25);
		panel.add(factbtn);
		G1.add(factbtn);
		JRadioButton palibtn = new JRadioButton("Palindrome");
		palibtn.setBounds(108, 154, 127, 25);
		panel.add(palibtn);
		G1.add(palibtn);
		JRadioButton fibobtn = new JRadioButton("Fibonacci");
		fibobtn.setBounds(239, 122, 98, 25);
		panel.add(fibobtn);
		G1.add(fibobtn);
		JRadioButton primebtn = new JRadioButton("Prime");
		primebtn.setBounds(239, 154, 98, 25);
		panel.add(primebtn);
		G1.add(primebtn);
		JButton runbtn = new JButton("RUN!");
		runbtn.setBounds(368, 78, 109, 25);
		panel.add(runbtn);
		
		JLabel lblNewLabel_2 = new JLabel("Result");
		lblNewLabel_2.setBounds(46, 216, 67, 28);
		panel.add(lblNewLabel_2);
		
		runbtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				String str;
				String option=new String();
				try
				{
				Socket s=new Socket("localhost",8004);
				DataInputStream dis = new DataInputStream(s.getInputStream());
				DataOutputStream dout = new DataOutputStream(s.getOutputStream());
				str=input.getText();
				if(primebtn.isSelected())
					option="1";
				else if(palibtn.isSelected())
					option="2";
				else if(factbtn.isSelected())
					option="3";
				else if(fibobtn.isSelected())
					option="4";	
				str=str+"#"+option;
				dout.writeUTF(str);
				String s2=new String();
				s2 = (String)dis.readUTF();
				output.setText(s2);
				s.close();
				}
				catch(Exception e)
				{
					e.printStackTrace();
				}
				}
				
			});}}
	
	
