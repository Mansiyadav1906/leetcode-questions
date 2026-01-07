int lengthOfLongestSubstring(char* s) {
    int lastIndex[128];
    
    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }

    int start = 0;
    int maxLen = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        char c = s[end];

        if (lastIndex[(int)c] >= start) {
            start = lastIndex[(int)c] + 1;
        }

        lastIndex[(int)c] = end;

        int currentLen = end - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}