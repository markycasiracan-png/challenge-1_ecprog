#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define MAJOR_LEN 50

int   ids[MAX_STUDENTS];
char  names[MAX_STUDENTS][NAME_LEN ];
char  majors[MAX_STUDENTS][MAJOR_LEN];
float gpas[MAX_STUDENTS];
int   credits[MAX_STUDENTS];

int studentCount = 0; 

void addStudent(void);
void displayAllStudents(void);
void searchById(void);
void searchByGpaThreshold(void);
void searchByMajor(void);
int  findIndexById(int id);
void printStudentLine(int i);
void printMenu(void);
void clearInputBuffer(void);

void printMenu(void) {
printf("==============================================\n");
printf("           STUDENT'S DATA ORAGANIZER\n"         );
printf("==============================================");
    
    printf("\n----------------- MAIN MENU ------------------\n");
    printf("| 1. Add new student                         |\n");                     
    printf("| 2. Display all students                    |\n");                
    printf("| 3. Search student by ID                    |\n");                
    printf("| 4. Find students with GPA >= threshold     |\n");
    printf("| 5. Find students by major (with count)     |\n");  
    printf("| 6. Exit                                    |\n");                                
    printf("----------------------------------------------\n");
}
int main(void) {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchById();
                break;
            case 4:
                searchByGpaThreshold();
                break;
            case 5:
                searchByMajor();
                break;
            case 6:
                printf("Goodbye, Dr. Santos!\n");
                break;
            default:
                printf("Invalid choice. Please select 1-6.\n");
        }
        printf("\n");
  } while (choice != 6);
    return 0;
}
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}
void addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Registry is full! Cannot add more than %d students.\n", MAX_STUDENTS);
    }

    int idx = studentCount; 

    printf("\n--- Add New Student ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &ids[idx]);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (ids[i] == ids[idx]) {
            printf("A student with ID %d already exists. Student not added.\n", ids[idx]);
        }
    }
    
    printf("Enter Full Name: ");
    fgets(names[idx], NAME_LEN, stdin);
    names[idx][strcspn(names[idx], "\n")] = '\0'; 

    printf("Enter Major: ");
    fgets(majors[idx], MAJOR_LEN, stdin);
    majors[idx][strcspn(majors[idx], "\n")] = '\0';

    printf("Enter GPA (0.0 - 4.0): ");
    scanf("%f", &gpas[idx]);
    clearInputBuffer();
