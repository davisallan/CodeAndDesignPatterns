package ExerciseA;
/*
 * File Name: Subject.java
 * Lab # and Assignment #: Lab 7 Exercise A
 * Lab section: B01
 * Completed by: Davis Allan, 10016543
 * Submission Date: Nov 6 2020
 */

/**
 * Interface Name: Observer
 *
 * Provides the method definitions necessary for a Subject
 */
public interface Subject {
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyAllObservers();
}
