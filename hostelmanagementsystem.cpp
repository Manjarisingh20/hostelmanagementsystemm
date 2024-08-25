#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    int rollNumber;
    char branch[50];
    int roomNumber;
    long long int phoneNumber;
    char fatherName[50];
    char motherName[50];
    long long int fatherPhoneNumber;
    char hostelBlock[10];
};

// Function to add a new student
void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents == 100) {
        printf("Cannot add more students. Hostel is full.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*numStudents].rollNumber);
    printf("Enter branch: ");
    scanf("%s", students[*numStudents].branch);
    printf("Enter room number: ");
    scanf("%d", &students[*numStudents].roomNumber);
    printf("Enter phone number: ");
    scanf("%lld", &students[*numStudents].phoneNumber);
    printf("Enter father's name: ");
    scanf("%s", students[*numStudents].fatherName);
    printf("Enter mother's name: ");
    scanf("%s", students[*numStudents].motherName);
    printf("Enter father's phone number: ");
    scanf("%lld", &students[*numStudents].fatherPhoneNumber);
    printf("Enter hostel block name: ");
    scanf("%s", students[*numStudents].hostelBlock);

    (*numStudents)++;  // Increment the number of students
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No students in the hostel.\n");
    } else {
        printf("\n%-20s%-15s%-20s%-15s%-15s%-20s%-20s%-20s%-15s\n", "Name", "Roll Number", "Branch", "Room Number",
               "Phone Number", "Father's Name", "Mother's Name", "Father's Phone Number", "Hostel Block");
        for (int i = 0; i < numStudents; i++) {
            printf("%-20s%-15d%-20s%-15d%-15lld%-20s%-20s%-20lld%-15s\n", students[i].name, students[i].rollNumber,
                   students[i].branch, students[i].roomNumber, students[i].phoneNumber, students[i].fatherName,
                   students[i].motherName, students[i].fatherPhoneNumber, students[i].hostelBlock);
        }
    }
}

// Function to search for a student by roll number
void searchStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number to search: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\n%-20s%-15s%-20s%-15s%-15s%-20s%-20s%-20s%-15s\n", "Name", "Roll Number", "Branch", "Room Number",
                   "Phone Number", "Father's Name", "Mother's Name", "Father's Phone Number", "Hostel Block");
            printf("%-20s%-15d%-20s%-15d%-15lld%-20s%-20s%-20lld%-15s\n", students[i].name, students[i].rollNumber,
                   students[i].branch, students[i].roomNumber, students[i].phoneNumber, students[i].fatherName,
                   students[i].motherName, students[i].fatherPhoneNumber, students[i].hostelBlock);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to edit student details
void editStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter the roll number to edit: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new details for the student:\n");
            printf("Enter student name: ");
            scanf("%s", students[i].name);
            printf("Enter branch: ");
            scanf("%s", students[i].branch);
            printf("Enter room number: ");
            scanf("%d", &students[i].roomNumber);
            printf("Enter phone number: ");
            scanf("%lld", &students[i].phoneNumber);
            printf("Enter father's name: ");
            scanf("%s", students[i].fatherName);
            printf("Enter mother's name: ");
            scanf("%s", students[i].motherName);
            printf("Enter father's phone number: ");
            scanf("%lld", &students[i].fatherPhoneNumber);
            printf("Enter hostel block name: ");
            scanf("%s", students[i].hostelBlock);

            printf("Student details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to delete a student
void deleteStudent(struct Student students[], int *numStudents) {
    int rollNumber;
    printf("Enter the roll number to delete: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Move the last student to the deleted position
            students[i] = students[*numStudents - 1];
            (*numStudents)--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to sort students by roll number
void sortStudents(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                // Swap the students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by roll number.\n");
}

// Function to save students to a file
void saveStudentsToFile(struct Student students[], int numStudents) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %s %d %lld %s %s %lld %s\n", students[i].name, students[i].rollNumber,
                students[i].branch, students[i].roomNumber, students[i].phoneNumber, students[i].fatherName,
                students[i].motherName, students[i].fatherPhoneNumber, students[i].hostelBlock);
    }

    fclose(file);
    printf("Students saved to file.\n");
}

// Function to load students from a file
void loadStudentsFromFile(struct Student students[], int *numStudents) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("File not found or error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %d %s %d %lld %s %s %lld %s", students[*numStudents].name, &students[*numStudents].rollNumber,
                  students[*numStudents].branch, &students[*numStudents].roomNumber, &students[*numStudents].phoneNumber,
                  students[*numStudents].fatherName, students[*numStudents].motherName,
                  &students[*numStudents].fatherPhoneNumber, students[*numStudents].hostelBlock) != EOF) {
        (*numStudents)++;
        if (*numStudents == 100) {
            printf("Maximum number of students reached. Loading stopped.\n");
            break;
        }
    }

    fclose(file);
    printf("Students loaded from file.\n");
}

int main() {
    struct Student students[100];  // Assuming a maximum of 100 students
    int numStudents = 0;
    int choice;

    // Load existing data from file
    loadStudentsFromFile(students, &numStudents);

    do {
        printf("\nHostel Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students\n");
        printf("7. Save Students to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                searchStudent(students, numStudents);
                break;
            case 4:
                editStudent(students, numStudents);
                break;
            case 5:
                deleteStudent(students, &numStudents);
                break;
            case 6:
                sortStudents(students, numStudents);
                break;
            case 7:
                saveStudentsToFile(students, numStudents);
                break;
            case 8:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}