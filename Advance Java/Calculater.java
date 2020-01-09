import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JEditorPane;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.border.BevelBorder;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.border.MatteBorder;
import javax.swing.border.SoftBevelBorder;
import javax.swing.border.TitledBorder;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.SystemColor;

public class Calculater {

	private JFrame frame;
	private JTextField textField;
	private JTextField textField_1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Calculater window = new Calculater();
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
	public Calculater() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 258, 321);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		textField_1 = new JTextField();
		textField_1.setFont(new Font("Tahoma", Font.PLAIN, 19));
		textField_1.setHorizontalAlignment(SwingConstants.RIGHT);
		textField_1.setBorder(null);
		textField_1.setColumns(10);
		textField_1.setBounds(15, 14, 209, 31);
		frame.getContentPane().add(textField_1);
		
		textField = new JTextField();
		textField.setText("0");
		textField.setHorizontalAlignment(SwingConstants.RIGHT);
		textField.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textField.setBorder(null);
		textField.setColumns(10);
		textField.setBounds(15, 47, 209, 36);
		frame.getContentPane().add(textField);
		
		JEditorPane editorPane = new JEditorPane();
		editorPane.setBorder(new LineBorder(new Color(0, 0, 0)));
		editorPane.setBounds(10, 11, 222, 75);
		frame.getContentPane().add(editorPane);
		
		JButton btnNewButton = new JButton("9");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+9);
			}
		});
		btnNewButton.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		btnNewButton.setBounds(127, 108, 48, 31);
		frame.getContentPane().add(btnNewButton);
		
		JButton button = new JButton("6");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+6);
			}
		});
		button.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button.setBounds(126, 150, 48, 31);
		frame.getContentPane().add(button);
		
		JButton button_1 = new JButton("3");
		button_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+3);
			}
		});
		button_1.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_1.setBounds(126, 192, 48, 31);
		frame.getContentPane().add(button_1);
		
		JButton button_2 = new JButton("0");
		button_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+0);
			}
		});
		button_2.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_2.setBounds(10, 234, 48, 31);
		frame.getContentPane().add(button_2);
		
		JButton button_3 = new JButton("8");
		button_3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+8);
			}
		});
		button_3.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_3.setBounds(68, 108, 48, 31);
		frame.getContentPane().add(button_3);
		
		JButton button_4 = new JButton("5");
		button_4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+5);
			}
		});
		button_4.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_4.setBounds(68, 150, 48, 31);
		frame.getContentPane().add(button_4);
		
		JButton button_5 = new JButton("2");
		button_5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+2);
			}
		});
		button_5.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_5.setBounds(68, 192, 48, 31);
		frame.getContentPane().add(button_5);
		
		JButton button_7 = new JButton("7");
		button_7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+7);
			}
		});
		button_7.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_7.setBounds(10, 108, 48, 31);
		frame.getContentPane().add(button_7);
		
		JButton button_8 = new JButton("4");
		button_8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+4);
			}
		});
		button_8.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_8.setBounds(10, 150, 48, 31);
		frame.getContentPane().add(button_8);
		
		JButton button_9 = new JButton("1");
		button_9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText(textField.getText()+1);
			}
		});
		button_9.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_9.setBounds(10, 192, 48, 31);
		frame.getContentPane().add(button_9);
		
		JButton button_10 = new JButton("=");
		button_10.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				double second=Double.parseDouble(textField.getText());
				double first=Double.parseDouble(textField_1.getText());
				
				if(actionRecived.getText().equals("Sub")) {
					double sub=first-second;
					textField_1.setText(first+" - "+second);
					textField.setText(Double.toString(sub));
				}
				else if(actionRecived.getText().equals("Sum")) {
					double sum=first+second;
					textField_1.setText(first+" + "+second);
					textField.setText(Double.toString(sum));
				}
				else if(actionRecived.getText().equals("Div")) {
					double div=first/second;
					textField_1.setText(first+" / "+second);
					textField.setText(Double.toString(div));
				}
				else if(actionRecived.getText().equals("Mul")) {
					double mul=first*second;
					textField_1.setText(first+" * "+second);
					textField.setText(Double.toString(mul));
				}
			
			}
		});
		button_10.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_10.setBounds(126, 234, 48, 31);
		frame.getContentPane().add(button_10);
		
		JButton button_11 = new JButton("-");
		button_11.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField_1.setText(textField.getText());
				actionRecived.setText("Sub");
				textField.setText("0");
			}
		});
		button_11.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_11.setBounds(184, 108, 48, 31);
		frame.getContentPane().add(button_11);
		
		JButton button_12 = new JButton("+");
		button_12.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField_1.setText(textField.getText());
				actionRecived.setText("Sum");
				textField.setText("0");
			}
		});
		button_12.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_12.setBounds(184, 150, 48, 31);
		frame.getContentPane().add(button_12);
		
		JButton button_13 = new JButton("/");
		button_13.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField_1.setText(textField.getText());
				actionRecived.setText("Div");
				textField.setText("0");
			}
		});
		button_13.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_13.setBounds(184, 192, 48, 31);
		frame.getContentPane().add(button_13);
		
		JButton button_14 = new JButton("*");
		button_14.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField_1.setText(textField.getText());
				actionRecived.setText("Mul");
				textField.setText("0");
			}
		});
		button_14.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		button_14.setBounds(184, 234, 48, 31);
		frame.getContentPane().add(button_14);
		
		JButton btnC = new JButton("C");
		btnC.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textField.setText("0");
				textField_1.setText(null);
				actionRecived.setText(null);
			}
		});
		btnC.setBorder(new BevelBorder(BevelBorder.RAISED, null, null, null, null));
		btnC.setBounds(68, 234, 48, 31);
		frame.getContentPane().add(btnC);
		
		actionRecived = new JLabel("");
		actionRecived.setForeground(SystemColor.control);
		actionRecived.setBounds(44, 94, 26, 10);
		frame.getContentPane().add(actionRecived);
	}
	private JLabel actionRecived;
}
