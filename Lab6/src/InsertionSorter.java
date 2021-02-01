 /*
  * File Name: InsertionSorter.java
  * Lab # and Assignment #: Lab 6 Exercise C and D
  * Lab section: B01
  * Completed by: Davis Allan, 10016543
  * Submission Date: Oct 30 2020
  */
import java.util.ArrayList;

public class InsertionSorter implements Sorter {

    @Override
    //code adapted from https://www.geeksforgeeks.org/insertion-sort/
    public void sort(ArrayList<Item> arr) {
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            Item key = arr.get(i);
            int j = i - 1;

            while (j >= 0 && arr.get(j).getItem() > key.getItem()) {
                arr.set(j + 1, arr.get(j));
                j = j - 1;
            }
            arr.set(j + 1, key);
        }
    }
}
