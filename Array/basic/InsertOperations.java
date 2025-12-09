
public class InsertOperations {

    public static void main(String[] args) {
        int maxsize = 20;
        int currentsize = 6;

        int[] arr = new int[maxsize];
        int[] initial = {1, 2, 3, 4, 5, 6};
        System.arraycopy(initial, 0, arr, 0, currentsize);

        System.out.print("Original Array: ");
        printArray(arr, currentsize);

        // Insert at Beginning
        currentsize = insertAtBeginning(arr, 100, currentsize);
        System.out.print("After inserting 100 at beginning: ");
        printArray(arr, currentsize);

        // Insert at End
        currentsize = insertAtEnd(arr, 200, currentsize);
        System.out.print("After inserting 200 at end: ");
        printArray(arr, currentsize);

        // Insert at Random Position
        currentsize = insertAtRandom(arr, 4, 500, currentsize);
        System.out.print("After inserting 500 at position 4: ");
        printArray(arr, currentsize);
    }

    // 🧩 Function to print array
    static void printArray(int[] arr, int currentsize) {
        for (int i = 0; i < currentsize; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // 🧩 Insert at Beginning
    static int insertAtBeginning(int[] arr, int element, int currentsize) {
        for (int i = currentsize - 1; i >= 0; i--) {
            arr[i + 1] = arr[i]; // shift all elements to right
        }
        arr[0] = element;
        currentsize++;
        return currentsize;
    }

    // 🧩 Insert at End
    static int insertAtEnd(int[] arr, int element, int currentsize) {
        arr[currentsize] = element;
        currentsize++;
        return currentsize;
    }

    // 🧩 Insert at Random Position
    static int insertAtRandom(int[] arr, int position, int element, int currentsize) {
        if (position < 0 || position > currentsize) {
            System.out.println("Invalid position!");
            return currentsize;
        }
        for (int i = currentsize - 1; i >= position; i--) {
            arr[i + 1] = arr[i];
        }
        arr[position] = element;
        currentsize++;
        return currentsize;
    }
}
