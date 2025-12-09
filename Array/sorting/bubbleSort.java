// package sorting;

import java.util.Arrays;

public class bubbleSort {

    public static void main(String[] args) {
        int[] arr = {3, 5, 4, 6, 7, 8, 9};
        // int [] arr={1,2,3,4,5};
        BubbleSort(arr);
        System.out.print(Arrays.toString(arr));
    }

    static void BubbleSort(int[] arr) {
        int count = 0,comp=0;
        for (int i = 0; i < arr.length; i++) {
            boolean swapped = false;
            for (int j = 1; j < arr.length - i; j++) {
                comp++;
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j, j - 1);
                    count++;
                    swapped = true;
                }
            }
            if (!swapped) {
                break; // optimization: stop if already sorted
            }
        }
        System.out.println("Number of swaps: " + count);
        System.out.println("Number of comparisons: " + comp);
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
