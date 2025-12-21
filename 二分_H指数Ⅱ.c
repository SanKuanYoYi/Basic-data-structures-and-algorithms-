int hIndex(int* citations, int citationsSize) {

    int left = 0;
    int right = citationsSize - 1;
    int ans = 0;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        int x = citationsSize - mid;

        if (citations[mid] >= x) {
            if (ans < x) {
                ans = x;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
