/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int binarySearch(int* array, int size, long long Min) {

    int left = 0;
    int right = size - 1;
    int result = size;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] >= Min) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize,
                     long long success, int* returnSize) {

    int* ans = (int*)malloc(spellsSize * sizeof(int));
    *returnSize = spellsSize;

    qsort(potions, potionsSize, sizeof(int), compare);

    for (int i = 0; i < spellsSize; i++) {
        int spell = spells[i];

        long long needMin = (success + spell - 1) / spell;

        if (needMin > potions[potionsSize - 1]) {
            ans[i] = 0;
            continue;
        }

        int firstPos = binarySearch(potions, potionsSize, needMin);

        ans[i] = potionsSize - firstPos;
    }

    return ans;
}
