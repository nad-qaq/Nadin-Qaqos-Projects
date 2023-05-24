import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;
 
public class MentorGui extends JFrame implements ActionListener {
 
    JPanel cardPanel = new JPanel();
    CardLayout cards = new CardLayout();
   
    
    //authentication page
    JLabel userNameLabel = new JLabel("Username: ");
    JTextField userName = new JTextField();
    JLabel passwordLabel = new JLabel("Password: ");
    JTextField password = new JTextField();
    JButton login = new JButton("Login");

    //mentor form page
    JLabel fNameLabel = new JLabel("First Name: ");
    JTextField fName = new JTextField();
    JLabel lNameLabel = new JLabel("LastName: ");
    JTextField lName = new JTextField();
    JLabel emailLabel = new JLabel("Email: ");
    JTextField email = new JTextField();
    JLabel phoneLabel = new JLabel("Phone: ");
    JTextField phone = new JTextField();
    JLabel addressLabel = new JLabel("Address: ");
    JTextField address = new JTextField();
    JLabel highDegLabel = new JLabel("Highest Degree: ");
    JComboBox degreeBox = new JComboBox();
    JLabel gradYearLabel = new JLabel("Graduation Year: ");
    JComboBox gradYearBox = new JComboBox();
    JLabel mentorInterestLabel = new JLabel("Mentoring Interest: ");
    JRadioButton[] interests = new JRadioButton[4];
    ButtonGroup group = new ButtonGroup();
    JButton save = new JButton("Save");
    JButton reset = new JButton("Reset");
    
    

    public MentorGui() {
        super("Mentor Profile GUI created by Nadin Qaqos");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel loginPanel = new JPanel();
        JPanel formPanel = new JPanel();
        cardPanel.setLayout(cards);
        loginPanel.setLayout(new GridBagLayout());
        formPanel.setLayout(new GridBagLayout());
    
        cardPanel.add(loginPanel, "login");
        cardPanel.add(formPanel, "form");

        // authentication page 
        JLabel userNameLabel = new JLabel("Username: ");
        JLabel passwordLabel = new JLabel("Password: ");

        userName.addActionListener(this);
        password.addActionListener(this);
        login.addActionListener(this);

        addComponent(loginPanel, userNameLabel, 3, 0, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(loginPanel, userName, 4, 0, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(loginPanel, passwordLabel, 3, 1, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(loginPanel, password, 4, 1, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(loginPanel, login, 5, 2, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.WEST);

        // mentor form page
        String[] degreesOptions = { "(choose degree)", "High School", "Associate Degree",
                                    "Bachelor's Degree", "Master's Degree", "Doctorate degree" };
        String[] gradYearOptions = {"(choose year)", "2023", "2022", "2020", "2021", "2019", "2018", "2017", "2016", "2015", "2014", "2013", "2012"};
        
        mentorInterestLabel.setToolTipText("Select a major that you are interested in mentoring");

        interests[0] = new JRadioButton("Computer Science");
        interests[1] = new JRadioButton("Cybersecurity");
        interests[2] = new JRadioButton("Computer Info Technology");
        interests[3] = new JRadioButton("Computer Info Systems");

        interests[0].setActionCommand("Computer Science");
        interests[1].setActionCommand("Cybersecurity");
        interests[2].setActionCommand("Computer Info Technology");
        interests[3].setActionCommand("Computer Info Systems");

        
        for (JRadioButton interest : interests) {
            group.add(interest);        
        }
        
        for (String degrees : degreesOptions) {
            degreeBox.addItem(degrees);
        }
        
        for (String year : gradYearOptions) {
            gradYearBox.addItem(year);
        }

        save.addActionListener(this);
        reset.addActionListener(this);
       
        addComponent(formPanel, fNameLabel, 0, 0, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, fName, 1, 0, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, lNameLabel, 5, 0, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, lName, 6, 0, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, emailLabel, 0, 1, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, email, 1, 1, 9, 1, 90, 100,GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, phoneLabel, 0, 2, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, phone, 1, 2, 4, 1, 40, 100,GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, addressLabel, 5, 2, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, address, 6, 2, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, highDegLabel, 0, 3, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, degreeBox, 1, 3, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, gradYearLabel, 5, 3, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, gradYearBox, 6, 3, 4, 1, 40, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, mentorInterestLabel, 0, 4, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, interests[0], 1, 4, 2, 1, 20, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, interests[1], 3, 4, 2, 1, 20, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, interests[2], 5, 4, 2, 1, 20, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, interests[3], 7, 4, 2, 1, 20, 100, GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(formPanel, save, 4, 5, 1, 1, 10, 100,GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(formPanel, reset, 5, 5, 1, 1, 10, 100, GridBagConstraints.NONE, GridBagConstraints.WEST);
 
        add(cardPanel);
        setVisible(true);
 
    }

    @Override
    public void actionPerformed(ActionEvent event) {

        Object source = event.getSource(); 
        String un = userName.getText();
        String pw = password.getText();

        if ((un.equals("username123")) && (pw.equals("password123"))) {
            cards.show(cardPanel, "form");
        }
        if (source == save){
            System.out.println("Save button pressed");
            System.out.println("Info added to database");

            String data = "jdbc:derby://localhost:1527/MentorsSystem";
            try (
                Connection conn = DriverManager.getConnection(
                    data, "nbuser", "nbuser");
                Statement st = conn.createStatement()) {

                Class.forName("org.apache.derby.jdbc.ClientDriver");

                PreparedStatement prep2 = conn.prepareStatement(
                     "insert into " +
                     "APP.MENTORS(FIRSTNAME, LASTNAME, EMAIL, TELEPHONE, ADDRESS, HIGHESTDEGREE, GRADUATIONYEAR, MENTORINGINTERESTS)" +
                     "values(?,?,?,?,?,?,?,?)"
                );

                prep2.setString(1, fName.getText());
                prep2.setString(2, lName.getText());
                prep2.setString(3, email.getText());
                prep2.setString(4, phone.getText());
                prep2.setString(5, address.getText());
                prep2.setString(6, (String) degreeBox.getSelectedItem());
                prep2.setString(7, (String) gradYearBox.getSelectedItem());
                prep2.setString(8, group.getSelection().getActionCommand());
            
                prep2.executeUpdate();

                prep2.close();
                conn.close();

            } catch (SQLException s) {
                 System.out.println("SQL Error: " + s.toString() + " "
                     + s.getErrorCode() + " " + s.getSQLState());
            } catch (Exception e) {
                 System.out.println("Error: " + e.toString()
                     + e.getMessage());
            }

        }
        if(source == reset){
            fName.setText("");
            lName.setText("");
            email.setText("");
            phone.setText("");
            address.setText("");
            degreeBox.setSelectedIndex(0);
            gradYearBox.setSelectedIndex(0);
            group.clearSelection();

        }
    }

    private void addComponent(JPanel p, Component component, int gridx, int gridy,
        int gridwidth, int gridheight, int weightx, int weighty, int fill,
        int anchor) {
    
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.gridx = gridx;
        constraints.gridy = gridy;
        constraints.gridwidth = gridwidth;
        constraints.gridheight = gridheight;
        constraints.weightx = weightx;
        constraints.weighty = weighty;
        constraints.fill = fill;
        constraints.anchor = anchor;
        p.add(component,constraints);
    }

    private static void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                "javax.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            System.err.println(exc);
        }
    }
    
    public static void main(String[] arguments) {
        MentorGui.setLookAndFeel();
        MentorGui mentor = new MentorGui();
    
    }
}
 