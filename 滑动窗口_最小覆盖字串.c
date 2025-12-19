
char* minWindow(char* s, char* t) {

    int sLen = strlen(s);
    int tLen = strlen(t);
    int map[256] = {0};
    int minLen = INT_MAX;
    int len;
    int start = 0;

    int l = 0, r = 0;

    for (int i = 0; i < tLen; i++) {
        map[t[i]]++;
    }

    while (r < sLen) {

        if (map[s[r]] > 0) {
            map[s[r]]--;
            tLen--;
        } else {
            map[s[r]]--;
        }

        if (tLen == 0) {
            while (map[s[l]] < 0) {
                map[s[l]]++;
                l++;
            }

            len = r - l + 1;
            if (len < minLen) {
                minLen = len;
                start = l;
            }

            map[s[l]]++;
            l++;
            tLen++;
        }

        r++;
    }

    if (minLen == INT_MAX) {
        return "";
    }

    char* ans = (char*)malloc(sizeof(char*) * (minLen + 1));
    ans[0] = '\0';

    strncat(ans, s + start, minLen);
    return ans;
}
