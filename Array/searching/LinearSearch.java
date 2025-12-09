
public class LinearSearch {

    public static void main(String[] args) {
        int[] num = {1, 5, 3, 9, 6, 4, 8, 7};
        int target = 0;
        int ans = linearSearch(num, target);
        System.out.print("Element at index: " + ans);
    }

    static int linearSearch(int[] arr, int target) {
        int ind = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                ind = i;
                break;
            }
        }
        return ind;
    }
}
