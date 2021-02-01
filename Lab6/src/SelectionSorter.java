 /*
  * File Name: SelectionSorter.java
  * Lab # and Assignment #: Lab 6 Exercise C and D
  * Lab section: B01
  * Completed by: Davis Allan, 10016543
  * Submission Date: Oct 30 2020
  */
import java.util.ArrayList;

public class SelectionSorter implements Sorter {

    @Override
    //code adapted from https://www.programiz.com/dsa/selection-sort
    public void sort(ArrayList<Item> arr) {
        int size = arr.size();

        for (int step = 0; step < size - 1; step++) {
            int min_idx = step;

            for (int i = step + 1; i < size; i++) {

                if (arr.get(i).getItem() < arr.get(min_idx).getItem()) {
                    min_idx = i;
                }
            }

            Item temp = arr.get(step);
            arr.set(step, arr.get(min_idx));
            arr.set(min_idx, temp);
        }
    }
}
