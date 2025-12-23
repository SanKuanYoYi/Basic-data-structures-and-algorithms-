bool isPerfectSquare(int num) {

    long long left = 1;
    long long right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == num) {
            return true;
        }

        if (mid * mid < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    
    } 
    return false;

}
