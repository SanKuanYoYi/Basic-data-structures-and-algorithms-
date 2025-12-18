int longestOnes(int* nums, int numsSize, int k) {

    int l = 0;
    int r = 0;
    int change = 0;
    int maxLen = 0;
    int cLen;

    while (r < numsSize) {

        if (nums[r] == 0) {
            change++;
        }

        while (change > k) {
            if (nums[l] == 0) {
                change--;
            }
            l++;
        }

        if (change <= k) {
            cLen = r - l + 1;
            if (cLen > maxLen) {
                maxLen = cLen;
            }
        }

        r++;
    }

    return maxLen;
}
