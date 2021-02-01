package ExerciseA;
/*
 * File Name: OneRow_Observer.java
 * Lab # and Assignment #: Lab 7 Exercise A
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.util.ArrayList;

public class OneRow_Observer implements Observer {
    /**
     * ArrayList containing the data
     */
    private ArrayList<Double> data;

    /**
     * The Subject that this Observer will observe
     */
    private Subject subject;

    /**
     * Constructs a OneRow_Observer and registers the Subject that it will be observing
     * @param subject the Subject to be observed
     */
    public OneRow_Observer(Subject subject) {
        this.subject = subject;
        subject.registerObserver(this);
    }

    /**
     * Updates the observed data and then calls the display method
     * @param arr the updated data to be displayed
     */
    @Override
    public void update(ArrayList<Double> arr) {
        data = arr;
        display();
    }

    /**
     * Displays the values of the data in 5 rows, with as many columns as needed
     */
    public void display() {
        System.out.println("\nNotification to One-Row ExerciseA.Observer: Data Changed:");
        for (Double d : data) {
            System.out.print(d + " ");
        }
    }
}
