static int binarySearch(int[] arr, int numberToFind, int range) {
        int low = 0;
        int high = range;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == numberToFind) {
                return mid;
            } else if (numberToFind > arr[mid]) {
                low = mid + 1;
            } else if (numberToFind < arr[mid]) {
                high = mid - 1;
            }
        }
        return -1;
    }
static int beautifulTriplets(int d, int[] arr) {
        int count_ = 0;
        for (int i = arr.length - 1; i >= 0; --i) {
            int firstNumber = binarySearch(arr, arr[i] - d, arr.length - (arr.length - i));
            if (firstNumber != -1) {
                int secondNumber = binarySearch(arr, arr[firstNumber] - d, firstNumber);
                if (secondNumber != -1) {
                    ++count_;
             }
         }
     }
   return count_;
}
