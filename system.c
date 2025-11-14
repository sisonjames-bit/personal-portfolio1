#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
    char course[20];
    int year;
} Student;

void inputStudents(Student students[], int *n);
void displayStudents(Student students[], int n);
void sortStudents(Student students[], int n);
void displaySeating(Student students[], int n, int rows, int cols);
void addStudent(Student students[], int *n);
void searchStudent(Student students[], int n);
void deleteStudent(Student students[], int *n);

int main() {
    Student students[MAX_STUDENTS];
    int n = 0;
    int choice;
    int rows = 5, cols = 6;

    printf("=== ROOM SORTING SYSTEM ===\n");
    inputStudents(students, &n);

    do {
        printf("\n\n========= MENU =========\n");
        printf("[1] Display All Students\n");
        printf("[2] Add Student\n");
        printf("[3] Search Student\n");
        printf("[4] Delete Student\n");
        printf("[5] Display Seating Arrangement\n");
        printf("[0] Exit\n");
        printf("=========================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                sortStudents(students, n);
                printf("\n--- SORTED STUDENTS (A–Z) ---\n");
                displayStudents(students, n);
                break;
            case 2:
                addStudent(students, &n);
                break;
            case 3:
                searchStudent(students, n);
                break;
            case 4:
                deleteStudent(students, &n);
                break;
            case 5:
                sortStudents(students, n);
                printf("\n--- SEATING ARRANGEMENT ---\n");
                displaySeating(students, n, rows, cols);
                break;
            case 0:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void inputStudents(Student students[], int *n) {
    printf("Enter number of students to input: ");
    scanf("%d", n);
    getchar();

    for (int i = 0; i < *n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &students[i].age);
        getchar();

        printf("Course: ");
        fgets(students[i].course, sizeof(students[i].course), stdin);
        students[i].course[strcspn(students[i].course, "\n")] = '\0';

        printf("Year Level (1 to 4): ");
        scanf("%d", &students[i].year);
        getchar();
    }
}

void addStudent(Student students[], int *n) {
    if (*n >= MAX_STUDENTS) {
        printf("Cannot add more students — list is full!\n");
        return;
    }

    printf("\nEnter new student details:\n");
    printf("Name: ");
    fgets(students[*n].name, sizeof(students[*n].name), stdin);
    students[*n].name[strcspn(students[*n].name, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &students[*n].age);
    getchar();

    printf("Course: ");
    fgets(students[*n].course, sizeof(students[*n].course), stdin);
    students[*n].course[strcspn(students[*n].course, "\n")] = '\0';

    printf("Year Level (1 to 4): ");
    scanf("%d", &students[*n].year);
    getchar();

    (*n)++;
    printf("Student added successfully!\n");
}

void searchStudent(Student students[], int n) {
    char searchName[50];
    int found = 0;

    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcasecmp(students[i].name, searchName) == 0) {
            printf("\nStudent found:\n");
            printf("Name: %s\nAge: %d\nCourse: %s\nYear: %d\n",
                   students[i].name, students[i].age,
                   students[i].course, students[i].year);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

void deleteStudent(Student students[], int *n) {
    char deleteName[50];
    int found = 0;

    printf("Enter name to delete: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcasecmp(students[i].name, deleteName) == 0) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Student '%s' deleted successfully!\n", deleteName);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

void sortStudents(Student students[], int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(Student students[], int n) {
    if (n == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("%-25s %-5s %-10s %-5s\n", "Name", "Age", "Course", "Year");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-25s %-5d %-10s %-5d\n",
               students[i].name,
               students[i].age,
               students[i].course,
               students[i].year);
    }
}

void displaySeating(Student students[], int n, int rows, int cols) {
    if (n == 0) {
        printf("No students to display seating.\n");
        return;
    }

    int index = 0;
    for (int i = 0; i < rows && index < n; i++) {
        for (int j = 0; j < cols && index < n; j++) {
            printf("[%2d] %-20s", index + 1, students[index].name);
            index++;
        }
        printf("\n");
    }
}
