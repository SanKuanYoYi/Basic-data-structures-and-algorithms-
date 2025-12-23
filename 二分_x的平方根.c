int mySqrt(int x) {

    if (x == 0) {
        return 0;
    }

    long long left = 1;
    long long right = x;

    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
