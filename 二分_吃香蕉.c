
#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool canEatAll(int* piles, int pilesSize, int h, int k) {
    long long hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;

        if (hours > h) {
            return false;
        }
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {

    long long maxPile = 0;
    for (int i = 0; i < pilesSize; i++) {
        maxPile = MAX(maxPile, piles[i]);
    }

    int left = 1;
    int right = maxPile;
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEatAll(piles, pilesSize, h, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}
