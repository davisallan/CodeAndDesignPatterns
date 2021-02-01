package ExerciseBandC;
/*
 * File Name: DemoDecoratorPattern.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.awt.*;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Class Name: DemoDecoratorPattern
 *
 * Provides the driver code to test the implementation of the Decorator design pattern
 */
public class DemoDecoratorPattern extends JPanel {
	Component t;

    public DemoDecoratorPattern(){
   	 t = new Text("Hello World", 60, 80);
   }

    public void paintComponent(Graphics g){
 	    //EXERCISE A CODE:
        int fontSize = 10;
 	    g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize));

// 	     Now lets decorate t with BorderDecorator: x = 30, y = 30, width = 100, and height 100
 	    t = new BorderDecorator(t, 30, 30, 100, 100);
//
// 	     Now lets add a ColouredFrameDecorator with x = 25, y = 25, width = 110, height = 110,
// 		 and thickness = 10.
 	    t = new ColouredFrameDecorator(t, 25, 25, 110, 110, 10);

 	    // Now lets draw the product on the screen
 	    t.draw(g);

// 	    EXERCISE C CODE: uncomment lines to test it
        g.setFont(new Font("TimesRoman", Font.PLAIN, fontSize));
        t = new ColouredGlassDecorator(new ColouredFrameDecorator(
                new BorderDecorator(t, 30, 30, 100, 100), 25, 25, 110, 110, 10), 25, 25,
                110, 110);
        t.draw(g);
    }

	public static void main(String[] args) {
        DemoDecoratorPattern panel = new DemoDecoratorPattern();
        JFrame frame = new JFrame("Learning Decorator Pattern");
        frame.getContentPane().add(panel);
        frame.setSize(400,400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
	}
}