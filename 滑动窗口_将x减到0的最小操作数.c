
int min(int x, int y) {
    if (x > y) {
        return y;
    } else
        return x;
}

int minOperations(int* nums, int numsSize, int x) {

    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    sum -= x;

    if (sum < 0) {
        return -1;
    } else if (sum == 0) {
        return numsSize;
    }

    int cSum = 0;
    int l = 0;
    int r = 0;
    int maxLen = -1;

    while (r < numsSize) {

        cSum += nums[r];

        while (cSum > sum) {
            cSum -= nums[l];
            l++;
        }

        if (cSum == sum) {
            int len = r - l + 1;
            maxLen = (maxLen < len) ? len : maxLen;
        }

        r++;
    }

    return maxLen == -1 ? -1 : numsSize - maxLen;
}
