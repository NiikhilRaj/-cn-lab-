#include <stdio.h>

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int areEqual(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

int isSubstring(char s1[], char s2[]) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);

    if (len2 > len1) return 0;

    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (s1[i + j] != s2[j]) {
                break;
            }
        }
        if (j == len2) {
            return 1; 
        }
    }
    return 0;  
}


int MatchAny(char s1[], char s2[]) {
    if (areEqual(s1, s2)) {
        return 0;
    } else if (isSubstring(s1, s2)) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    char s1[100], s2[100];

    printf("Enter string s1: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Enter string s2: ");
    fgets(s2, sizeof(s2), stdin);

    int len1 = stringLength(s1);
    if (s1[len1 - 1] == '\n') s1[len1 - 1] = '\0';
    int len2 = stringLength(s2);
    if (s2[len2 - 1] == '\n') s2[len2 - 1] = '\0';

    int result = MatchAny(s1, s2);
    if (result == 1) {
        printf("s2 is a substring of s1. Result = 1\n");
    } else if (result == 0) {
        printf("s1 and s2 are equal. Result = 0\n");
    } else {
        printf("s2 is not a substring of s1. Result = -1\n");
    }

    return 0;
}
