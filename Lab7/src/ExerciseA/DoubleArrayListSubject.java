package ExerciseA;
/*
 * File Name: ExerciseA.DoubleArrayListSubject.java
 * Lab # and Assignment #: Lab 7 Exercise A
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */
import java.util.ArrayList;

/**
 * Class Name: DoubleArrayListSubject
 *
 * Represents a Subject in the Observer design pattern that holds an ArrayList of data to be displayed
 * by the various Observers
 */
public class DoubleArrayListSubject implements Subject{

    /**
     * ArrayList of Observers watching this Subject
     */
    private ArrayList<Observer> observers;

    /**
     * ArrayList containing the data
     */
    public ArrayList<Double> data;

    /**
     * Constructs the DoubleArrayListSubject object and initializes its data members to empty
     * lists
     */
    public DoubleArrayListSubject() {
        data = new ArrayList<Double>();
        observers = new ArrayList<Observer>();
    }

    /**
     * Adds the data to the list and notifies all Observers of the change
     * @param value number to be added
     */
    public void addData(Double value) {
        data.add(value);
        notifyAllObservers();
    }

    /**
     * Sets the data at a specified index to the new specified value and notifies
     * all Observers of the change
     * @param value the new value for the data
     * @param index index at which the update will occur
     */
    public void setData(Double value, int index) {
        if (index >= data.size()) { //ensures that the index is valid
            System.out.println("Index out of bounds, unable to add data");
            return;
        }
        data.set(index, value);
        notifyAllObservers();
    }

    /**
     * Populates the list with the data supplied by its argument
     * @param arr Array containing double values
     */
    public void populate(double[] arr) {
        for (double d : arr) {
            data.add(d);
        }
    }

    /**
     * Displays the values of the data to the console, outputs a message if the list is empty,
     * otherwise notifies all Observers to display the contents of the data
     */
    public void display() {
        if (data.size() == 0) {
            System.out.println("Empty List...");
            return;
        }
        notifyAllObservers();
    }

    /**
     * Adds the Observer to the observer list and updates the Observer with the current data
     * @param o the Observer to be registered
     */
    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
        o.update(data);
    }

    /**
     * Removes the Observer from the observer list
     * @param o the Observer to be removed
     */
    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    /**
     * Updates all Observers in the observer list with the current data
     */
    @Override
    public void notifyAllObservers() {
        for (Observer o : observers) {
            o.update(data);
        }
    }
}
