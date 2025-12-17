int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {

    if (k <= 1) return 0;

    int fact = 1;
    int l = 0;
    int r = 0;

    int cnt = 0;

    while (r < numsSize) {

        fact *= nums[r];

        while (fact >= k) {
            fact /= nums[l];
            l++;
        }

        cnt += r - l + 1;

        r++;
    }
    return cnt;
}
