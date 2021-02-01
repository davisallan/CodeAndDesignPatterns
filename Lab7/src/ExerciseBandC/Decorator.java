package ExerciseBandC;

/*
 * File Name: Decorator.java
 * Lab # and Assignment #: Lab 7 Exercise B and C
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */

/**
 * Class Name: Decorator
 *
 * Abstract class that all Decorators will extend from. Provides the protected data members
 * for all Decorators to inherit.
 */
public abstract class Decorator implements Component {
    protected Component cmp;
    protected int x, y, width, height;

    public Decorator(Component c) {
        cmp = c;
    }
}
