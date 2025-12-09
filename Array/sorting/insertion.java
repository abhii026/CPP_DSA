
import java.util.Arrays;


public class insertion {

    public static void main(String[] args) {
        // int[] arr = {3, 5, 4, 6, 7, 8, 9};
        int [] arr={1,2,3,4,5};
        InsertionSort(arr);
        System.out.print(Arrays.toString(arr));
    }

    static void InsertionSort(int[] arr) {
        int count=0,comp=0;
        for (int i = 0; i < arr.length-1; i++) {
            comp++;
            for (int j = i+1; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j, j - 1);
                    count++;
                } else {
                    break;
                }
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
