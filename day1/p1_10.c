#include<stdio.h>

struct dob{
    int day;
    int month;
    int year;
};

struct student_info{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void display_by_value(struct student_info s)
{
    printf("\n--- Call by Value ---\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("CGPA: %.2f\n", s.CGPA);
    printf("DOB: %d/%d/%d\n", s.age.day, s.age.month, s.age.year);
}

void display_by_address(struct student_info *s)
{
    printf("\n--- Call by Address ---\n");
    printf("Roll No: %d\n", s->roll_no);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->CGPA);
    printf("DOB: %d/%d/%d\n", s->age.day, s->age.month, s->age.year);
}

int main()
{
    struct student_info student;
    
    printf("Enter student details:\n");
    printf("Roll No: ");
    scanf("%d", &student.roll_no);
    
    printf("Name: ");
    scanf("%s", student.name);
    
    printf("CGPA: ");
    scanf("%f", &student.CGPA);
    
    printf("Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &student.age.day, &student.age.month, &student.age.year);
    
    display_by_value(student);
    display_by_address(&student);
    
    return 0;
}