#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char * ransomNote, char * magazine) {
    if (strlen(ransomNote) > strlen(magazine)) {
        return false;
    }

    int charCount[26] = {0};

    for (int i=0; magazine[i] != '\0'; i++) {
        charCount[magazine[i] - 'a']++;
    }

    for (int i=0; ransomNote[i] != '\0'; i++) {
        if (charCount[ransomNote[i] - 'a'] == 0) {
            return false;
        }
        charCount[ransomNote[i] - 'a']--;
    }
    return true;
}

int main() {
    char note1[] = "a";
    char mag1[] = "b";
    printf("Test 1 - Expected: 0, Got: %d\n", canConstruct(note1, mag1));

    char note2[] = "aa";
    char mag2[] = "ab";
    printf("Test 2 - Expected: 0, Got: %d\n", canConstruct(note2, mag2));

    char note3[] = "aa";
    char mag3[] = "aab";
    printf("Test 3 - Expected: 1, Got: %d\n", canConstruct(note3, mag3));

    return 0;
}
