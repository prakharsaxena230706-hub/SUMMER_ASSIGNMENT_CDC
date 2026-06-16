#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    if (n <= 1) return n;
    int last_seen[128];
    memset(last_seen, -1, sizeof(last_seen));
    int max_len = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        unsigned char current_char = s[right];
        if (last_seen[current_char] >= left) {
            left = last_seen[current_char] + 1;
        }
        last_seen[current_char] = right;
        max_len = MAX(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    char test_str[] = "abcabcbb";
    int result = lengthOfLongestSubstring(test_str);
    printf("Length of the longest non-repeating substring: %d\n", result);
    return 0;
}
