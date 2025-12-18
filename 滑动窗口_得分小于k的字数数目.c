long long countSubarrays(int* nums, int numsSize, long long k) {

    long long ans = 0;
    long long sum = 0;
    long long l = 0;

    for (int r = 0; r < numsSize; r++) {
        sum += nums[r];

        while (sum * (r - l + 1) >= k) {
            sum -= nums[l];
            l++;
        }

        ans += r - l + 1;
    }

    return ans;
}
