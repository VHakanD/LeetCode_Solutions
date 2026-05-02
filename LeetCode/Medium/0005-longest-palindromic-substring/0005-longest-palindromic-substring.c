#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";

    int max_len = 0;
    int best_start = 0;

    int i = 0;
    int searching = 1;

    while (i < n && searching) {
        int len = 1;
        int check_len = 1;

        while (i + 2 * len <= n && check_len) {
            int is_match_even = 1;
            int k = 0;
            while (k < len && is_match_even) {
                if (s[i + k] != s[i + 2 * len - 1 - k]) {
                    is_match_even = 0;
                }
                k++;
            }

            if (is_match_even == 1) {
                if (2 * len > max_len) {
                    max_len = 2 * len;
                    best_start = i;
                }
            }
            if (i + 2 * len + 1 <= n) {
                int is_match_odd = 1;
                k = 0;
                while (k < len && is_match_odd) {
                    if (s[i + k] != s[i + 2 * len - k]) {
                        is_match_odd = 0;
                    }
                    k++;
                }

                if (is_match_odd == 1) {
                    if (2 * len + 1 > max_len) {
                        max_len = 2 * len + 1;
                        best_start = i;
                    }
                }
            }

            len++;
        }
        i++;
    }

    if (max_len == 0) {
        max_len = 1;
        best_start = 0;
    }

    char* result = (char*)malloc(max_len + 1);
    int j = 0;
    while (j < max_len) {
        result[j] = s[best_start + j];
        j++;
    }
    result[max_len] = '\0';

    return result;
}