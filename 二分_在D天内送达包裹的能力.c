int check(int* weights, int weightsSize, int days, int mid) {

    int cntDays = 0;
    int sumDays = 0;

    for (int i = 0; i < weightsSize; i++) {
        sumDays += weights[i];
        if (sumDays > mid) {
            sumDays = weights[i];
            cntDays++;
        }
    }

    cntDays++;
    return cntDays <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days) {

    int total = 0;
    int maxWeight = 0;
    for (int i = 0; i < weightsSize; i++) {
        total += weights[i];
        if (weights[i] > maxWeight) {
            maxWeight = weights[i];
        }
    }

    int left = maxWeight;
    int right = total;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (check(weights, weightsSize, days, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
