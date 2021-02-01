package ExerciseA;
/*
 * File Name: FiveRowsTable_Observer.java
 * Lab # and Assignment #: Lab 7 Exercise A
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.util.ArrayList;

/**
 * Class Name: FiveRowsTable_Observer
 *
 * Provides the data fields and methods to create an Observer that will display the data
 * in 5 rows, with as many columns as needed anytime an update occurs.
 */
public class FiveRowsTable_Observer implements Observer {
    /**
     * ArrayList containing the data
     */
    private ArrayList<Double> data;

    /**
     * The Subject that this Observer will observe
     */
    private Subject subject;

    /**
     * Constructs a FiveRowsTable_Observer and registers the Subject that it will be observing
     * @param subject the Subject to be observed
     */
    public FiveRowsTable_Observer(Subject subject) {
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
        System.out.println("\nNotification to Five-Row Table ExerciseA.Observer: Data Changed:");
        int cols = (int) Math.round(data.size() / 5.0);

        for (int i = 0; i < 5; i++) {
            int index = i;
            for (int j = 0; j < cols; j++) {
                if (index >= data.size())
                    break;
                System.out.print(data.get(index) + " ");
                index += 5;
            }
            System.out.print("\n");
        }
    }
}
