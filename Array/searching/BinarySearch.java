
// import java.lang.annotation.Target;
public class BinarySearch {

    public static void main(String[] args) {
        int[] nums1 = {1, 3, 5, 6, 7, 9, 11, 23, 25, 30, 57};
        int[] nums2 = {7, 6, 5, 4, 3, 2, 1};
        int target = 2;
        System.out.print("Target at index: ");
        System.out.print(binarySearch(nums2, target));
    }

    static int binarySearch(int[] arr, int target) {
        int first = 0;
        int last = arr.length - 1;
        boolean isAsc = arr[first] < arr[last];
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (arr[mid] == target) {
                return mid;
            }
            if (isAsc) {
                if (arr[mid] < target) {
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }
            } else {
                if (target < arr[mid]) {
                    first = mid + 1;
                } else if (target > arr[mid]) {
                    last = mid - 1;
                }
            }
        }
        return -1;
    }
}
