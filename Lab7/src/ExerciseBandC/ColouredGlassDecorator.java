package ExerciseBandC;
/*
 * File Name: ColouredGlassDecorator.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.awt.*;

/**
 * Class Name: ColouredGlassDecorator
 *
 * Provides the methods to draw a colored semi-transparent glass frame at the specified location
 */
public class ColouredGlassDecorator extends Decorator {

    /**
     * Constructs a ColouredGlassDecorator object and initializes all its data members
     * from the provided arguments
     * @param c Component that is being wrapped
     * @param x the x coordinate
     * @param y the y coordinate
     * @param width the width of the rectangle
     * @param height the height of the rectangle
     */
    public ColouredGlassDecorator(Component c, int x, int y, int width, int height) {
        super(c);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    /**
     * Draws the previous component and the new coloured glass at the specified location
     * @param g Graphics object to be drawn
     */
    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Color oldColor = g2d.getColor();
        g2d.setColor(Color.green);
        g2d.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 1 * 0.1f));
        g2d.fillRect(25, 25, 110, 110);
        g2d.setStroke(oldStroke);
        g2d.setColor(oldColor);
    }
}
