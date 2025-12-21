
long long minimumTime(int* time, int timeSize, int totalTrips) {

    int min_time = INT_MAX;
    for (int i = 0; i < timeSize; i++) {
        if (time[i] < min_time) {
            min_time = time[i];
        }
    }

    long long left = 1;
    long long right = (long long)min_time * totalTrips;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long trips = 0;

        for (int i = 0; i < timeSize; i++) {
            trips += mid / time[i];

            if (trips >= totalTrips) {
                break;
            }
        }

        if (trips >= totalTrips) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
