#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define MAJOR_LEN 30

typedef struct {
    int   studentID;
    char  studentName[NAME_LEN];
    char  major[MAJOR_LEN];
    float gpa;
    int   credits;
} STUDENT;

STUDENT student[MAX_STUDENTS];
int studentCount = 0; 

void printMenu(void);
void clearInputBuffer(void);
void addStudent(void);
void printStudentLine(int i);
void displayAllStudents(void);
int  findIndexById(int id);
void searchById(void);
void searchByGpaThreshold(void);
void searchByMajor(void);

void printMenu(void) {
printf("==============================================\n");
printf("           STUDENT'S DATA ORAGANIZER\n"         );
printf("==============================================");
    
    printf("\n----------------- MAIN MENU ------------------\n");
    printf("| 1. Add new student                         |\n");                     
    printf("| 2. Display all students                    |\n");                
    printf("| 3. Search student by ID                    |\n");                
    printf("| 4. Find students with GPA                  |\n");
    printf("| 5. Find students by major                  |\n");  
    printf("| 6. Exit                                    |\n");                                
    printf("----------------------------------------------\n");
}
int main(void) {
    int choice;
    do {
        printMenu();
        printf("\nEnter your choice in main menu: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n\n");
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
                printf("\nWell done!.......\n");
                break;
            default:
                printf("\nInvalid choice. Please select 1-6 only!!\n");
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
        return;
    }

    int idx = studentCount; 
    printf("\n===========================================");
    printf("\n          --- ADD NEW STUDENT ---\n");
    printf("===========================================\n");
    printf(" Enter Student ID: ");
    scanf("%d", &student[idx].studentID);
    clearInputBuffer();

    for (int i = 0; i < studentCount; i++) {
        if (student[i].studentID == student[idx].studentID) {
            printf("A student with ID %d already exists. Student not added.\n", student[idx].studentID);
            return;
        }
    }
    
    printf(" Enter Full Name: ");
    fgets(student[idx].studentName, NAME_LEN, stdin);
    student[idx].studentName[strcspn(student[idx].studentName, "\n")] = '\0'; 

    printf(" Enter Major: ");
    fgets(student[idx].major, MAJOR_LEN, stdin);
    student[idx].major[strcspn(student[idx].major, "\n")] = '\0';

    printf(" Enter GPA (0.0 - 4.0): ");
    scanf("%f", &student[idx].gpa);
    clearInputBuffer();

    printf(" Enter Credits Completed: ");
    scanf("%d", &student[idx].credits);
    clearInputBuffer();
    printf("===========================================\n");
    studentCount++;

    printf("\nStudent \"%s\" (ID: %d) added successfully! (%d/%d students)\n", student[idx].studentName, student[idx].studentID, studentCount, MAX_STUDENTS);
}
void printStudentLine(int i) {
    printf("%-6d %-25s %-25s %-8.2f %-11d\n", student[i].studentID, student[i].studentName, student[i].major, student[i].gpa, student[i].credits);
}

void displayAllStudents(void) {
    if (studentCount == 0) {
        printf("No students in the registry yet.\n");
        return;
    }
    printf("\n============================================================================");
    printf("\n                -------- ALL STUDENTS (%d TOTAL) --------\n", studentCount);
       printf("============================================================================\n");
     printf("ID     NAME                      MAJOR                     GPA      CREDITS\n");
    printf("----------------------------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printStudentLine(i);
         printf("============================================================================\n");
    }
}

int findIndexById(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (student[i].studentID == id) {
            return i;
        }
    }
    return -1;
}

void searchById(void) {
    if (studentCount == 0) {
        printf("No students in the registry yet.\n");
        return;
    }

    int searchId;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);
    clearInputBuffer();

    int idx = findIndexById(searchId);

    if (idx == -1) {
        printf("No student found with ID %d.\n", searchId);
    } else {
        printf("=================================");
          printf("\n    ---   Student Found ---\n");
               printf("=================================\n");
           printf("ID:      %d\n", student[idx].studentID);
        printf("Name:    %s\n", student[idx].studentName);
        printf("Major:   %s\n", student[idx].major);
        printf("GPA:     %.2f\n", student[idx].gpa);
        printf("Credits: %d\n", student[idx].credits);
             printf("=================================");
    }
}

void searchByGpaThreshold(void) {
    if (studentCount == 0) {
        printf("\nNo students in the registry yet.\n");
        return;
    }

    float threshold;
    printf("\nEnter minimum GPA threshold: ");
    scanf("%f", &threshold);
    clearInputBuffer();
    
     
     int found = 0;
     printf("\n============================================================================");
     printf("\n                    --- Students with GPA >= %.2f ---", threshold);
      printf("\n============================================================================\n");
    printf("%-6s %-25s %-25s %-8s %-8s\n",
           "ID", "Name", "Major", "GPA", "Credits");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        if (student[i].gpa >= threshold) {
            printStudentLine(i);
            found++;
             printf("============================================================================\n");
        }
    }
    if (found == 0) {
         printf("\n============================================================================");
        printf("\nNo students meet this GPA threshold.\n");
         printf("\n============================================================================");
    } else {
         printf("----------------------------------------");
         printf("\n %d student(s) found.", found);
          printf("\n----------------------------------------\n");
    }
}
     void searchByMajor(void){
         if(studentCount == 0){
             printf("No students in the register yet.\n");
             return;
         }

     char searchMajor[MAJOR_LEN];
     printf("\nEnter major to search for: ");
     fgets(searchMajor, MAJOR_LEN, stdin);
     searchMajor[strcspn(searchMajor, "\n")] = '\0';

     int count = 0;
      printf("\n============================================================================");
      printf("\n                  --- Students in \"%s\" ---", searchMajor);
      printf("\n============================================================================\n");
      printf("%-6s %-25s %-25s %-8s %-8s\n", "ID", "Name", "Major", "GPA", "Credits");
      printf("----------------------------------------------------------------------------\n");

      for(int i=0; i< studentCount; i++){
          if(strcmp(student[i].major, searchMajor) == 0){
               printStudentLine(i);
               count++;
                 printf("============================================================================\n");
          }
      }
        printf("----------------------------------------");
        printf("\nTotal students in \"%s\": %d\n", searchMajor, count);
        printf("----------------------------------------");
     }
