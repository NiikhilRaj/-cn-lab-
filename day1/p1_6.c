#include <stdio.h>

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int matchAtPosition(char sentence[], char word[], int start) {
    int i = 0;
    while (word[i] != '\0') {
        if (sentence[start + i] != word[i]) {
            return 0;
        }
        i++;
    }

    if ((sentence[start + i] == ' ' || sentence[start + i] == '\0') &&
        (start == 0 || sentence[start - 1] == ' ')) {
        return 1;
    }

    return 0;
}

int countOccurrences(char sentence[], char word[]) {
    int i = 0, count = 0;
    int lenSentence = stringLength(sentence);
    int lenWord = stringLength(word);

    while (i <= lenSentence - lenWord) {
        if (matchAtPosition(sentence, word, i)) {
            count++;
        }

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            i++;
        }
        if (sentence[i] == ' ') i++;  
    }

    return count;
}

int main() {
    char sentence[200], word[50];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Enter the word to search: ");
    fgets(word, sizeof(word), stdin);

    int lenS = stringLength(sentence);
    if (sentence[lenS - 1] == '\n') sentence[lenS - 1] = '\0';

    int lenW = stringLength(word);
    if (word[lenW - 1] == '\n') word[lenW - 1] = '\0';

    int result = countOccurrences(sentence, word);
    printf("The word '%s' appears %d time(s).\n", word, result);

    return 0;
}
