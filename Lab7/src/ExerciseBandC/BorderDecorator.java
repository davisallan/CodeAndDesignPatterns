package ExerciseBandC;
/*
 * File Name: BorderDecorator.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.awt.*;

/**
 * Class Name: BorderDecorator
 *
 * Adds a dashed line border in the shape of a rectangle to the Component
 */
public class BorderDecorator extends Decorator {

    /**
     * Constructs a BorderDecorator object and initializes all data members from the
     * specified arguments
     * @param c Component to be wrapped
     * @param x x coordinate
     * @param y y coordinate
     * @param width width of the rectangle
     * @param height height of the rectangle
     */
    public BorderDecorator(Component c, int x, int y, int width, int height) {
        super(c);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    /**
     * Displays any previous components and draws the dashed line rectangle on the GUI
     * @param g Graphics to be drawn
     */
    @Override
    public void draw(Graphics g) {
        cmp.draw(g);
        Graphics2D g2d = (Graphics2D) g;
        Stroke oldStroke = g2d.getStroke();
        Stroke dashed = new BasicStroke(3, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new
                float[]{9}, 0);

        g2d.setStroke(dashed);
        g2d.drawRect(x, y, width, height);
        g2d.setStroke(oldStroke);
    }
}
