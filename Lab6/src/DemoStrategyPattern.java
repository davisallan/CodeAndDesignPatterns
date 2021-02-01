 /*
  * File Name: DemoStrategyPattern.java
  * Lab # and Assignment #: Lab 6 Exercise C and D
  * Lab section: B01
  * Completed by: Davis Allan, 10016543
  * Submission Date: Oct 30 2020
  */
import java.util.ArrayList;
import java.util.Random;
public class DemoStrategyPattern {
	public static void main(String[] args) {
		// Create an object of MyVector<Double> with capacity of 50 elements
		MyVector v1 = new MyVector (50);
		
		// Create a Random object to generate values between 0
		Random rand = new Random();  
       
		// adding 5 randomly generated numbers into MyVector object v1
	   for(int i = 4; i >=0; i--) {
		   Item item;
		   item = new Item (Double.valueOf(rand.nextDouble()*100));
		   v1.add(item);
	   }
	   
	    // displaying original data in MyVector v1
       System.out.println("The original values in v1 object are:");
		v1.display();
		
		// choose algorithm bubble sort as a strategy to sort object v1
		v1.setSortStrategy(new BubbleSorter ());
		
		// perform algorithm bubble sort to v1 
		v1.performSort();
		
        System.out.println("\nThe values in MyVector object v1 after performing BoubleSorter is:");
		v1.display();
		
		// create a MyVector<Integer> object V2 
		MyVector v2 = new MyVector (50);
		
		// populate v2 with 5 randomly generated numbers
		for(int i = 4; i >=0; i--) {
			Item item;
			item = new Item (Double.valueOf(rand.nextInt(50)));
			v2.add(item);
			}
		   
		System.out.println("\nThe original values in v2 object are:");
		v2.display();
		v2.setSortStrategy(new InsertionSorter());;
		v2.performSort();
		System.out.println("\nThe values in MyVector object v2 after performing InsertionSorter is:");
		v2.display();

		// create a MyVector<Integer> object V3

		MyVector v3 = new MyVector(10);

		for (int i = 0; i < 6; i++) {
			v3.add(new Item(Double.valueOf(rand.nextInt(75))));
		}

		v3.setSortStrategy(new SelectionSorter());
		System.out.println("\nThe original values in v3 object are:");
		v3.display();
		v3.performSort();
		System.out.println("\nThe values in MyVector object v3 after performing SelectionSorter is:");
		v3.display();

		ArrayList<Item> arrayList = new ArrayList<>();
		for (int i = 0; i < 5; i++) {
			arrayList.add(new Item(Double.valueOf(rand.nextInt(75))));
		}

		System.out.println("\n\nTesting copy constructor of MyVector");
		MyVector v4 = new MyVector(arrayList);

		arrayList.remove(0);
		arrayList.remove(3);
		arrayList.get(0).setItem(-99.0);
		System.out.println("Printing arrayList after manipulating");
		for (Item i : arrayList) {
			System.out.print(i.getItem() + " ");
		}
		System.out.println("\nPrinting v4, expecting 5 elements.");
		v4.display();
	}
}
