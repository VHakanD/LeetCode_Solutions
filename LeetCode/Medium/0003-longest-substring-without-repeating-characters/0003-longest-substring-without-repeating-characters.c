int lengthOfLongestSubstring(char* s) {
    int text[128];
    for (int i = 0; i < 128; i++) {
        text[i] = -1;
    }
    int n=strlen(s);
    int maxLen=0, currLen=0, right=0, left=0;

    if (n == 0) return 0;
    while(right < n) {
        char str = *(s+right);
        if(text[str] >= left ) {
            left = text[str]+1;
        }
        text[str] = right;
        currLen = right - left + 1;
        if(currLen > maxLen) {
            maxLen = currLen;
        }
        right++;
    }
    return maxLen;
}