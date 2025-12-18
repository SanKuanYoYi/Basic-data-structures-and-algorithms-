int longestSemiRepetitiveSubstring(char* s) {

    int len = strlen(s);
    if (len <= 1) {
        return len;
    }

    int maxLen = 0;

    int l = 0;
    int r = 1;

    int recur = 0;

    while (r < len) {
        if (s[r] == s[r - 1]) {
            recur++;
        }

        while (recur > 1) {
            if (s[l] == s[l + 1]) {
                recur--;
            }
            l++;
        }

        int cLen = r - l + 1;
        if (maxLen < cLen) {
            maxLen = cLen;
        }

        r++;
    }

    return maxLen;
}
