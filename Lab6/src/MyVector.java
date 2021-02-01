 /*
  * File Name: MyVector.java
  * Lab # and Assignment #: Lab 6 Exercise C and D
  * Lab section: B01
  * Completed by: Davis Allan, 10016543
  * Submission Date: Oct 30 2020
  */

 import java.util.ArrayList;

public class MyVector {

    private ArrayList<Item> storageM;
    private Sorter sortStrategy;

    public MyVector(int n) {
        storageM = new ArrayList<>(n);
    }

    public MyVector(ArrayList<Item> arr) {
        storageM = new ArrayList<>(arr.size());
        for (Item i : arr) {
            storageM.add(new Item(i.getItem()));
        }
    }

    public void add(Item value) {
        storageM.add(value);
    }

    public void setSortStrategy(Sorter s) {
        sortStrategy = s;
    }

    public void performSort() {
        sortStrategy.sort(storageM);
    }

    public void display() {
        for (Item i : storageM) {
            System.out.print(i.getItem() + " ");
        }
    }
}
