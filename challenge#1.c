#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LEN 50
#define MAJOR_LEN 50  



int ids[MAX_STUDENTS];
char names[NAME_LEN][50];    
char majors[MAJOR_LEN][50];   
float gpas[MAX_STUDENTS];
int credits[MAX_STUDENTS];
int studentCount = 0;   


int choice;
do {
    printf("Add new student");
    printf("Student data storage ");
    printf("\n1. Add Student\n2. Exit\nChoice: ");
    scanf("%d", &choice);
}










