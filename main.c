#include <stdio.h>
#include <string.h>

// Define a structure to store student details
struct Student {
    char firstName[50];
    char lastName[50];
    int regNumber;
    char grade;
};

// Function to add a new student record
void addStudent(struct Student students[], int *count) {
    struct Student newStudent;

    printf("Enter First Name: ");
    scanf("%s", newStudent.firstName);
    printf("Enter Last Name: ");
    scanf("%s", newStudent.lastName);
    printf("Enter Registration Number: ");
    scanf("%d", &newStudent.regNumber);
    printf("Enter Grade: ");
    scanf(" %c", &newStudent.grade);

    students[*count] = newStudent;
    (*count)++;
}

// Function to display all student records
void displayStudents(struct Student students[], int count) {
    printf("Student Records:\n");
    for (int i = 0; i < count; i++) {
        printf("First Name: %s\n", students[i].firstName);
        printf("Last Name: %s\n", students[i].lastName);
        printf("Registration Number: %d\n", students[i].regNumber);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }
}

// Function to search for a student by registration number
void searchStudent(struct Student students[], int count, int regNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].regNumber == regNumber) {
            printf("Student Found:\n");
            printf("First Name: %s\n", students[i].firstName);
            printf("Last Name: %s\n", students[i].lastName);
            printf("Registration Number: %d\n", students[i].regNumber);
            printf("Grade: %c\n", students[i].grade);
            return;
        }
    }

    printf("Student with Registration Number %d not found.\n", regNumber);
}

int main() {
    struct Student students[100]; // Array to store student records
    int count = 0; // Number of students in the array

    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student by Registration Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                int regNumber;
                printf("Enter Registration Number to search: ");
                scanf("%d", &regNumber);
                searchStudent(students, count, regNumber);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
