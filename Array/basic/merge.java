
import java.util.Arrays;

public class merge {

    public static void main(String[] args) {
        int[] arr1 = {1, 5, 9, 10, 11, 13};
        int[] arr2 = {2, 4, 7, 8, 12, 16, 18, 21, 25};
        int[] mergedArray = mergeSortedArrays(arr1, arr2);

        System.out.println("the merged array is:");
        System.out.print(Arrays.toString(mergedArray));
    }

    static int[] mergeSortedArrays(int[] arr1, int[] arr2) {
        int n1 = arr1.length;
        int n2 = arr2.length;
        int[] mergedArray = new int[n1 + n2];

        int i = 0, j = 0, k = 0;

        // Merge the two arrays
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                mergedArray[k++] = arr1[i++];
            } else {
                mergedArray[k++] = arr2[j++];
            }
        }

        while (i < n1) {
            mergedArray[k++] = arr1[i++];
        }

        while (j < n2) {
            mergedArray[k++] = arr2[j++];
        }

        return mergedArray;
    }
}
