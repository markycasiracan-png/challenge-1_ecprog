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
