package app.vistas;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
public class PanelLogin extends  JPanel{
	private JLabel lblTitulo;
	private JLabel lblUsername;
	private JTextField txUsername;
	private JLabel lblPassword;
	private JPasswordField txPassword;
	private JButton btnLogin;
	private JLabel lblRegistrarse;
	private JTextArea txaErroresLogin;

	private MainWindow m;
	/**
	 * Create the panel.
	 */
	public PanelLogin(MainWindow m) {
		this.m = m;
		setBackground(new Color(243, 238, 234));

		setLayout(new GridBagLayout());
		setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		GridBagConstraints constraints = new GridBagConstraints();
		constraints.gridwidth = GridBagConstraints.REMAINDER;
		constraints.anchor = GridBagConstraints.CENTER;

		constraints.insets = new Insets(5, 4, 5, 4);

		constraints.fill = GridBagConstraints.NONE;

		add(getLblTitulo(), constraints);
		constraints.fill = GridBagConstraints.HORIZONTAL;

		add(getLblUsername(), constraints);
		add(getTxUsername(), constraints);
		add(Box.createVerticalStrut(5), constraints);
		add(getLblPassword(), constraints);
		add(getTxPassword(), constraints);
		add(getTxaErroresLogin(), constraints);

		constraints.fill = GridBagConstraints.NONE;
		add(getLblRegistrarse(), constraints);

		add(getBtnLogin(), constraints);

	}

	private JLabel getLblTitulo() {
		if (lblTitulo == null) {
			lblTitulo = new JLabel("Login");
			lblTitulo.setFont(new Font("Tahoma", Font.BOLD, 30));
		}
		return lblTitulo;
	}
	private JLabel getLblUsername() {
		if (lblUsername == null) {
			lblUsername = new JLabel("Username");
			lblUsername.setFont(new Font("Tahoma", Font.PLAIN, 14));
		}
		return lblUsername;
	}
	public JTextField getTxUsername() {
		if (txUsername == null) {
			txUsername = new JTextField();
			txUsername.setBorder(null);
			txUsername.setBackground(Color.white);
			txUsername.setBorder(new EmptyBorder(0,10,0,0));
			txUsername.setColumns(30);
			txUsername.setPreferredSize(new Dimension(txUsername.getPreferredSize().width,30));

		}
		return txUsername;
	}
	private JLabel getLblPassword() {
		if (lblPassword == null) {
			lblPassword = new JLabel("Password");
			lblPassword.setFont(new Font("Tahoma", Font.PLAIN, 14));
		}
		return lblPassword;
	}
	public JPasswordField getTxPassword() {
		if (txPassword == null) {
			txPassword = new JPasswordField();
			txPassword.setBorder(null);
			txPassword.setBackground(Color.white);
			txPassword.setBorder(new EmptyBorder(0,10,0,0));
			txPassword.setColumns(30);
			txPassword.setPreferredSize(new Dimension(txPassword.getPreferredSize().width,30));

			txPassword.addActionListener(new ActionListener() {
				@Override
				public void actionPerformed(ActionEvent e) {
					//new SignController().login(m);
				}
			});
		}
		return txPassword;
	}
	private JButton getBtnLogin() {
		if (btnLogin == null) {
			btnLogin = new JButton("Login");
			btnLogin.setBackground(new Color(178, 165, 155));
			btnLogin.setBorderPainted(false);
			btnLogin.setPreferredSize(new Dimension(140,25));


			// Agrega un manejador de eventos del ratón para cambiar la apariencia en hover
			btnLogin.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseEntered(MouseEvent e) {
					btnLogin.setBackground(new Color(142, 132, 125));

				}

				@Override
				public void mouseExited(MouseEvent e) {
					btnLogin.setBackground(new Color(178, 165, 155));

				}
			});
			btnLogin.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					m.pasarPanel("CONTROL");
				}
			});

		}
		return btnLogin;
	}
	private JLabel getLblRegistrarse() {
		if (lblRegistrarse == null) {
			lblRegistrarse = new JLabel("Sign Up");

			// Agrega un manejador de eventos del ratón para cambiar la apariencia en hover
			lblRegistrarse.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseEntered(MouseEvent e) {
					lblRegistrarse.setText("<html><u>Sign Up</u></html>");

				}

				@Override
				public void mouseExited(MouseEvent e) {
					lblRegistrarse.setText("Sign Up");

				}
			});
			lblRegistrarse.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					m.pasarPanel("REGISTER");
				}

			
			});
			lblRegistrarse.setForeground(Color.black);
			lblRegistrarse.setFont(new Font("Tahoma", Font.PLAIN, 15));
		}
		return lblRegistrarse;
	}
	public JTextArea getTxaErroresLogin() {
		if (txaErroresLogin == null) {
			txaErroresLogin = new JTextArea();
			txaErroresLogin.setWrapStyleWord(true);
			txaErroresLogin.setForeground(Color.RED);
			txaErroresLogin.setEditable(false);
			txaErroresLogin.setBackground(new Color(243, 238, 234));
		}
		return txaErroresLogin;
	}
}
