#include <ctype.h>
#include <string.h>
#include <stdbool.h>

////////////////////////unrecommended//////////////////////////

/*bool isPalindrome(char* s) {

    int len = strlen(s);

    int check[1000000];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) {
            check[j++] = tolower(s[i]);
        } else
            continue;
    }
    check[j] = '\0';

    int l = 0;
    int r = j - 1;
    int flag = 1;
    while (l < r && flag) {
        if (check[l] == check[r]) {
            l++;
            r--;
            continue;
        } else {
            flag = 0;
            return false;
        }
    }

    return true;
}*/

//////////////////////////////////////////////////////

bool isPalindrome(char* s) {
	
    int len = strlen(s);

    int left = 0, right = len - 1;

    while (left < right) {

        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
