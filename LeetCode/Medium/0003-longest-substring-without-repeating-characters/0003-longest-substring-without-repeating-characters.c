int lengthOfLongestSubstring(char* s) {
    int text[128] = {0};
    int n=strlen(s);
    int maxLen=0, currLen=0, right=0, left=0;
    
    while(right < n) {
        char str = *(s+right);
        while(text[(int)str] == 1) {
            text[(int)s[left]] = 0;
            left++;
        }
        text[(int)str] = 1;
        currLen = right-left+1;
        if(currLen > maxLen) {
            maxLen = currLen;
        }
        right++;
    }
    return maxLen;
}