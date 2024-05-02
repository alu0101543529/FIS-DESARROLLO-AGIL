package app.vistas;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class PanelRegister extends JPanel {
	private JTextField txNick;
	private JTextField txEmail;
	private JPasswordField txPassword;
	private JButton btnRegistrar;
	private JButton btnVolver;
	private JLabel lblTitulo;
	private JTextArea txaErroresNick;
	private JTextArea txaErroresEmail;
	private JTextArea txaErroresContraseña;
	private JLabel lblContraseña;
	private JLabel lblEmail;
	private JLabel lblNick;
	private MainWindow m;

	/**
	 * Create the panel.
	 */
	public PanelRegister(MainWindow m) {
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

		add(getLblNick(), constraints);
		add(getTxNick(), constraints);
		add(getTxaErroresNick(), constraints);

		add(getLblEmail(), constraints);
		add(getTxEmail(), constraints);
		add(getTxaErroresEmail(), constraints);

		add(getLblContraseña(), constraints);
		add(getTxPassword(), constraints);
		add(getTxaErroresContraseña(), constraints);

		constraints.fill = GridBagConstraints.REMAINDER;
		JPanel panel = new JPanel(new BorderLayout());
		panel.add(getBtnRegistrar(),BorderLayout.EAST);
		panel.add(Box.createHorizontalStrut(50),BorderLayout.CENTER);
		panel.add(getBtnVolver(),BorderLayout.WEST);

		add(panel, constraints);

	}

	public JTextField getTxNick() {
		if (txNick == null) {
			txNick = new JTextField();
			txNick.setBorder(null);
			txNick.setBackground(Color.white);
			txNick.setBorder(BorderFactory.createEmptyBorder(0, 10, 0, 0));
			txNick.setPreferredSize(new Dimension(txNick.getPreferredSize().width,30));
			txNick.setColumns(30);
		}
		return txNick;
	}

	public JTextField getTxEmail() {
		if (txEmail == null) {
			txEmail = new JTextField();
			txEmail.setBorder(null);
			txEmail.setBackground(Color.white);
			txEmail.setBorder(BorderFactory.createEmptyBorder(0, 10, 0, 0));
			txEmail.setPreferredSize(new Dimension(txEmail.getPreferredSize().width,30));
			txEmail.setColumns(30);
		}
		return txEmail;
	}

	public JPasswordField getTxPassword() {
		if (txPassword == null) {
			txPassword = new JPasswordField();
			txPassword.setBorder(null);
			txPassword.setBackground(Color.white);
			txPassword.setBorder(BorderFactory.createEmptyBorder(0, 10, 0, 0));
			txPassword.setPreferredSize(new Dimension(txPassword.getPreferredSize().width,30));
			txPassword.setColumns(30);
		}
		return txPassword;
	}

	private JButton getBtnRegistrar() {
		if (btnRegistrar == null) {
			btnRegistrar = new JButton("Register");
			btnRegistrar.setBackground(new Color(178, 165, 155));
			btnRegistrar.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
			btnRegistrar.setBorderPainted(false);
			// Agrega un manejador de eventos del ratón para cambiar la apariencia en hover
			btnRegistrar.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseEntered(MouseEvent e) {
					btnRegistrar.setBackground(new Color(142, 132, 125));

				}

				@Override
				public void mouseExited(MouseEvent e) {
					btnRegistrar.setBackground(new Color(178, 165, 155));

				}
			});
			btnRegistrar.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// new SignController().register(PanelRegistro.this, m);
				}
			});
		}
		return btnRegistrar;
	}

	private JButton getBtnVolver() {
		if (btnVolver == null) {
			btnVolver = new JButton("Volver");
			btnVolver.setBackground(new Color(178, 165, 155));
			btnVolver.setBorder(BorderFactory.createEmptyBorder(5, 30, 5, 30));
			btnVolver.setBorderPainted(false);
			// Agrega un manejador de eventos del ratón para cambiar la apariencia en hover
			btnVolver.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseEntered(MouseEvent e) {
					btnVolver.setBackground(new Color(142, 132, 125));

				}

				@Override
				public void mouseExited(MouseEvent e) {
					btnVolver.setBackground(new Color(178, 165, 155));

				}
			});
			btnVolver.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					m.pasarPanel("LOGIN");
				}
			});
		}
		return btnVolver;
	}

	private JLabel getLblTitulo() {
		if (lblTitulo == null) {
			lblTitulo = new JLabel("Register");
			lblTitulo.setFont(new Font("Tahoma", Font.BOLD, 30));
		}
		return lblTitulo;
	}

	public JTextArea getTxaErroresNick() {
		if (txaErroresNick == null) {
			txaErroresNick = new JTextArea();
			txaErroresNick.setEditable(false);
			txaErroresNick.setForeground(Color.RED);
			txaErroresNick.setWrapStyleWord(true);
			txaErroresNick.setBackground(new Color(243, 238, 234));
		}
		return txaErroresNick;
	}

	public JTextArea getTxaErroresEmail() {
		if (txaErroresEmail == null) {
			txaErroresEmail = new JTextArea();
			txaErroresEmail.setWrapStyleWord(true);
			txaErroresEmail.setForeground(Color.RED);
			txaErroresEmail.setEditable(false);
			txaErroresEmail.setBackground(new Color(243, 238, 234));
		}
		return txaErroresEmail;
	}

	public JTextArea getTxaErroresContraseña() {
		if (txaErroresContraseña == null) {
			txaErroresContraseña = new JTextArea();
			txaErroresContraseña.setEditable(false);
			txaErroresContraseña.setForeground(Color.RED);
			txaErroresContraseña.setWrapStyleWord(true);
			txaErroresContraseña.setBackground(new Color(243, 238, 234));
		}
		return txaErroresContraseña;
	}

	private JLabel getLblContraseña() {
		if (lblContraseña == null) {
			lblContraseña = new JLabel("Password");
			lblContraseña.setFont(new Font("Tahoma", Font.PLAIN, 14));
		}
		return lblContraseña;
	}

	private JLabel getLblEmail() {
		if (lblEmail == null) {
			lblEmail = new JLabel("Email");
			lblEmail.setFont(new Font("Tahoma", Font.PLAIN, 14));
		}
		return lblEmail;
	}

	private JLabel getLblNick() {
		if (lblNick == null) {
			lblNick = new JLabel("Username");
			lblNick.setFont(new Font("Tahoma", Font.PLAIN, 14));
		}
		return lblNick;
	}
}