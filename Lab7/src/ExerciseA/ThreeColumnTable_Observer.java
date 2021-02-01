package ExerciseA;
/*
 * File Name: ThreeColumnTable_Observer.java
 * Lab # and Assignment #: Lab 7 Exercise A
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.util.ArrayList;

/**
 * Class Name: ThreeColumnTable_Observer
 *
 * Provides the data fields and methods to create an Observer that will display the data
 * in 3 columns, with as many rows as needed anytime an update occurs.
 */
public class ThreeColumnTable_Observer implements Observer {
    /**
     * ArrayList containing the data
     */
    private ArrayList<Double> data;

    /**
     * The Subject that this ExerciseA.Observer will observe
     */
    private Subject subject;

    /**
     * Constructs a ThreeColumnTable_Observer and registers the Subject that it will be observing
     * @param subject the Subject to be observed
     */
    public ThreeColumnTable_Observer(Subject subject) {
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
        System.out.println("\nNotification to Three-Column Table ExerciseA.Observer: Data Changed:");
        int rows = (int) Math.round(data.size() / 3.0);
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                if (index >= data.size())
                    break;
                System.out.print(data.get(index) + " ");
                index++;
            }
            System.out.print("\n");
        }
    }
}
