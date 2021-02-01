package ExerciseBandC;
/*
 * File Name: ColouredFrameDecorator.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.awt.*;

/**
 * Class Name: ColouredFrameDecorator
 *
 * Adds a colored rectangle to the Component
 */
public class ColouredFrameDecorator extends Decorator {
    /**
     * thickness of the border
     */
    private int thickness;

    /**
     * Constructs the ColouredFrameDecorator object and initializes its data members from
     * the specified arguments
     * @param c Component to be wrapped
     * @param x x coordinate
     * @param y y coordinate
     * @param width width of the rectangle
     * @param height height of the rectangle
     * @param thickness thickness of the rectangle line
     */
    public ColouredFrameDecorator(Component c, int x, int y, int width, int height, int thickness) {
        super(c);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.thickness = thickness;
    }

    /**
     * Displays any previous components and draws the coloured rectangle on the GUI
     * @param g Graphics to be drawn
     */
    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Color oldColor = g2d.getColor();
        g2d.setStroke(new BasicStroke(thickness));
        g2d.setColor(Color.red);
        g2d.drawRect(x, y, width, height);
        g2d.setStroke(oldStroke);
        g2d.setColor(oldColor);
    }
}
