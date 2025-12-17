
int lengthOfLongestSubstring(char* s) {

    int len = strlen(s);
    int maxLen = 0;

    bool check[256] = {false};

    int l = 0;
    int r = 0;

    while (r < len) {
        char c = s[r];

        while (check[c]) {
            char start = s[l];
            check[start] = false;
            l++;
        }

        check[c] = true;

        int distance = r - l + 1;
        if (distance > maxLen) {
            maxLen = distance;
        }

        r++;
    }

    return maxLen;
}
