int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB) {

    int l = 0;
    int r = plantsSize - 1;

    int A = capacityA;
    int B = capacityB;

    int anew = 0;
    while (l < r) {

        if (A < plants[l]) {
            A = capacityA;
            anew++;
            A -= plants[l];
        } else {
            A -= plants[l];
        }

        if (B < plants[r]) {
            B = capacityB;
            anew++;
            B -= plants[r];
        } else {
            B -= plants[r];
        }

        l++;
        r--;
    }

    if (l == r) {

        if (A < B) {
            if (B < plants[r]) {
                anew++;
            }
        } else {
            if (A < plants[l]) {
                anew++;
            }
        }
    }

    return anew;
}
