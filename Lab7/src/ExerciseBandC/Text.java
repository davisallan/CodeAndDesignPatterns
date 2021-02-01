package ExerciseBandC;
/*
 * File Name: Text.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.awt.*;

/**
 * Class Name: Text
 *
 * Provides the methods to draw a String to the GUI at the specified location
 */
public class Text implements Component {
    /**
     * the x and y coordinates of where the text will be drawn
     */
    private int x, y;

    /**
     * the String to be drawn
     */
    private String text;

    /**
     * Constructs a Text object and initializes its data members from the
     * specified arguments
     * @param text the String to be drawn
     * @param x the x coordinate
     * @param y the y coordinate
     */
    public Text(String text, int x, int y) {
        this.text = text;
        this.x = x;
        this.y = y;
    }

    /**
     * Draws the String contained in the text member variable at the specified location
     * @param g Graphics object to be drawn
     */
    @Override
    public void draw(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        g2d.drawString(text, x, y);
    }
}
