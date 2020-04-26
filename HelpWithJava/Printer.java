public class Printer {

    public static void main(String[] args) {
        // You can test the method here
        int[] array = {5, 1, 3, 4, 2};
        printArrayInStars(array);
    }

    public static void printArrayInStars(int[] array) {
        // Write some code in here
        System.out.println("Array length at: " + array.length);
        for (int i = 0; i < array.length; i++) {
            System.out.println("i at: " + i);
            for (int stars = 0; stars < array[i]; stars++) {
                System.out.print("*");
            }
            System.out.println("");
        }
    }

}