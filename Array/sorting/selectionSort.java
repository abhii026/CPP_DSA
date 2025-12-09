
import java.util.Arrays;

public class selectionSort {

    static int swapCount = 0;
    static int compCount = 0;

    public static void main(String[] args) {
        // int[] arr = {3, 5, 4, 6, 7, 8, 9};
        // int[] arr = {3, 1, 5, 4, 2, 0, -4};
        int[] arr={3,1,2};

        SelectionSort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println("Total Swap : " + swapCount);

        System.out.println("Total comparisons: "+compCount);
    }

    static void SelectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int last = arr.length - i - 1;
            int maxInd = getMaxInd(arr, 0, last);
            swap(arr, maxInd, last);
        }
    }

    static int getMaxInd(int[] arr, int start, int last) {
        int max = start;
        for (int i = start+1; i <= last; i++) {
            compCount++;
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        return max;
    }

    static void swap(int[] arr, int first, int second) {
        if (first != second) {
            swapCount++;
        }
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
