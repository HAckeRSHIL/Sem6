import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

import javax.swing.JTextField;
import javax.swing.JButton;

public class sortingclient1 {

	private JFrame frame;
	private JTextField input;
	private JTextField output;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					sortingclient1 window = new sortingclient1();
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
	public sortingclient1() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Bubble Sort by Harshil ");
		lblNewLabel.setFont(new Font("Segoe UI", Font.BOLD, 16));
		lblNewLabel.setBounds(120, 13, 178, 33);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Input : ");
		lblNewLabel_1.setBounds(25, 66, 56, 16);
		frame.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("Output : ");
		lblNewLabel_2.setBounds(25, 112, 56, 16);
		frame.getContentPane().add(lblNewLabel_2);
		
		input = new JTextField();
		input.setBounds(93, 63, 210, 22);
		frame.getContentPane().add(input);
		input.setColumns(10);
		
		output = new JTextField();
		output.setBounds(93, 109, 210, 22);
		frame.getContentPane().add(output);
		output.setColumns(10);
		
		JButton sortbtn = new JButton("SORT!");
		sortbtn.setBounds(323, 62, 97, 25);
		frame.getContentPane().add(sortbtn);
		sortbtn.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				try
				{
				String str;
				Socket s=new Socket("localhost",8004);
				DataInputStream dis = new DataInputStream(s.getInputStream());
				DataOutputStream dout = new DataOutputStream(s.getOutputStream());
				str=input.getText();
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
			});
			}
	}
