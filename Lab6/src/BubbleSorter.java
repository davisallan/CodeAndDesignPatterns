 /*
  * File Name: BubbleSorter.java
  * Lab # and Assignment #: Lab 6 Exercise C and D
  * Lab section: B01
  * Completed by: Davis Allan, 10016543
  * Submission Date: Oct 30 2020
  */

import java.util.ArrayList;

public class BubbleSorter implements Sorter {

    @Override
    //code adapted from https://www.geeksforgeeks.org/bubble-sort/
    public void sort(ArrayList<Item> arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr.get(j).getItem() > arr.get(j + 1).getItem()) {

                    Item temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                }
    }
}
