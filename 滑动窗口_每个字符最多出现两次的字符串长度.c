
int maximumLengthSubstring(char* s) {

    int check[26] = {0};
    int maxLen = 0;
    int len = strlen(s);

    int l = 0;
    int r = 0;

    while (r < len) {
        char c = s[r];

        check[c - 'a']++;

        while (check[c - 'a'] > 2) {
            check[s[l] - 'a']--;
            l++;
        }

        int cLen = r - l + 1;
        if (cLen > maxLen) {
            maxLen = cLen;
        }

        r++;
    }

    return maxLen;
}

