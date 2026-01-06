#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Expand around center and return palindrome length
int expand(char *s, int left, int right, int n) {
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        int len1 = expand(s, i, i, n);       // odd length
        int len2 = expand(s, i, i + 1, n);   // even length
        int len = len1 > len2 ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    char *res = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';

    return res;
}