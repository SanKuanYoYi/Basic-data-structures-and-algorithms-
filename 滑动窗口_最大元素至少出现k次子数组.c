#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long countSubarrays(int* nums, int numsSize, int k) {

    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        max = MAX(max, nums[i]);
    }

    long long ans = 0;
    int cnt = 0;
    int l = 0;

    for (int r = 0; r < numsSize; r++) {

        cnt += nums[r] == max;

        while (cnt == k) {
            cnt -= nums[l] == max;
            l++;
        }

        ans += l;
    }

    return ans;
}
