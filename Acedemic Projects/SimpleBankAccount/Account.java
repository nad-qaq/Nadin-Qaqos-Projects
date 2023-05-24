import java.io.*;

import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Account extends JFrame implements ActionListener {

    ImageIcon saveIMG = new ImageIcon("save.gif");
    ImageIcon clearIMG = new ImageIcon("clear.png");
    JButton save = new JButton("Save", saveIMG);
    JButton clear = new JButton("Clear", clearIMG);

    JTextField fNameTXT = new JTextField(9); 
    JTextField lNameTXT = new JTextField(9); 
    JTextField acctNumTXT = new JTextField(9); 
    JTextField acctBalTXT = new JTextField(9);

    JRadioButton  savings = new JRadioButton("Savings");
    JRadioButton  checking = new JRadioButton("Checking");

    public Account(String FirstName, String LastName, String AccountNumber, String AccountBalance) {
        super("Created by Nadin Qaqos");
        setSize(700, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel pane = new JPanel();
        JLabel fName = new JLabel("First Name: ");
        JLabel lName = new JLabel("Last Name: ");
        JLabel acctNum = new JLabel("Account Number: ");
        JLabel acctType = new JLabel("Account Type: ");
        JLabel acctBal = new JLabel("Account Balance: ");

        ButtonGroup group = new ButtonGroup(); 
        group.add(savings); 
        group.add(checking);

        savings.addActionListener(this);
        checking.addActionListener(this);
        
        
        save.addActionListener(this);
        clear.addActionListener(this);
        
        pane.add(fName);  pane.add(fNameTXT); 
        pane.add(lName);  pane.add(lNameTXT);
        pane.add(acctType); pane.add(savings); pane.add(checking);
        pane.add(acctNum);  pane.add(acctNumTXT);
        pane.add(acctBal);  pane.add(acctBalTXT);
        pane.add(save);     pane.add(clear);

        fNameTXT.setText(FirstName);
        lNameTXT.setText(LastName);
        acctNumTXT.setText(AccountNumber);
        acctBalTXT.setText(AccountBalance);

        add(pane); 
        setVisible(true);
   }

   @Override
   public void actionPerformed(ActionEvent event) {
       Object source = event.getSource();
       if (source == save && checking.isSelected()) {
            String fn = fNameTXT.getText();
            String ln = lNameTXT.getText();
            String at = checking.getText(); 
            String an = acctNumTXT.getText();
            String ab = acctBalTXT.getText();
          //   System.out.print(fn);
            writeInfo(fn,ln, at, an, ab);
       } else if (source == save && savings.isSelected()) {
            String fn = fNameTXT.getText();
            String ln = lNameTXT.getText();
            String at = savings.getText(); 
            String an = acctNumTXT.getText();
            String ab = acctBalTXT.getText();
          //   System.out.print(fn);
            writeInfo(fn,ln, at, an, ab);
       } else if (source == clear) {
            fNameTXT.setText(null);
            lNameTXT.setText(null);
            acctNumTXT.setText(null);
            acctBalTXT.setText(null);
       }
       repaint();
   }

   void writeInfo(String FirstName, String LastName, String AccountType, String AccountNumber, String AccountBalance) {
    try{ 
       FileWriter wr = new FileWriter("customerinfo_2.txt", true); 
       wr.write("Created by Nadin Qaqos \n");            
       wr.write("Name: "); 
       wr.write(FirstName);
       wr.write(" "); 
       wr.write(LastName); 
       wr.write("\nAccount Type: "); 
       wr.write(AccountType);   
       wr.write("\nAccount Number: "); 
       wr.write(AccountNumber);   
       wr.write("\nAccount Balance: "); 
       wr.write(AccountBalance); 
       wr.write("\n\n");
       
       wr.close();
     }
     catch(IOException e){
     }
  }

   private static void setLookAndFeel() {
       try {
            UIManager.setLookAndFeel(
                "javax.swing.plaf.nimbus.NimbusLookAndFeel"
            );
       } catch (Exception exc) {
            System.out.println(exc.getMessage());
       }
   }

   public static void main(String[] arguments) {
       setLookAndFeel();
       Account v2 = new Account("Nadin", "Qaqos", "123456789", "$125453.45");
   }
}
