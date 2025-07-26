#include <stdio.h>

// Define structure to store student data
struct Student {
    int roll;
    char name[50];
    char gender;
    int marks[5];
    int total;
};

int main() {
    int n, i, j;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student students[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);

        printf("Name: ");
        getchar(); 
        fgets(students[i].name, sizeof(students[i].name), stdin);
        int len = 0;
        while (students[i].name[len] != '\0') len++;
        if (students[i].name[len - 1] == '\n') students[i].name[len - 1] = '\0';

        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);

        students[i].total = 0;
        printf("Enter marks in 5 subjects:\n");
        for (j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }
    }

    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Gender: %c\n", students[i].gender);
        printf("Marks: ");
        for (j = 0; j < 5; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nTotal Marks: %d\n", students[i].total);
    }

    int found = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            if (students[i].marks[j] < 40) {
                printf("\nStudent %d (%s) failed in Subject %d (Marks: %d)", 
                       students[i].roll, students[i].name, j + 1, students[i].marks[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("\nNo students failed in any subject.\n");
    }

    return 0;
}
