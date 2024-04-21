package util.pages;

import java.awt.*;

import javax.swing.*;

public class MainPage extends JFrame {

    public MainPage() {
        super("Chat - App");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(500, 700);
        this.setMinimumSize(new Dimension(300, 500));

        ImageIcon icon = new ImageIcon(getClass().getResource("/assets/icone.png"));
        this.setIconImage(icon.getImage());

        setVisible(true);
    }
}
