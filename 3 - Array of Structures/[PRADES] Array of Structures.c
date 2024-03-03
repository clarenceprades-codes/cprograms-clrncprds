//Using array of structures
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3

/*
    Name: Clarence Prades
    Year and Section: BSCS-NS-1A
    Course: Computer Programming 2
    Professor: Mr.Fernando Renegado
*/

typedef struct student{
    char name[31];
    int q1;
    int q2;
    int q3;
} STUD; // Stucture

// Function Declaration
void getData(STUD st[MAX]);
float aver(int a, int b, int c);
void displayData(STUD st[MAX]);

int main(){
    STUD st[MAX]; // Array Of Structures

    getData(st); // Function that gets data from the user.
    displayData(st); // Function that displays list of data and computed average.
}

void getData(STUD st[MAX]){
    for(int i = 0; i < MAX; i++){
        printf("Student Name: ");
        scanf("%[^\n]s",st[i].name);
        printf("Quiz No.1 of %s: ",st[i].name);
        scanf("%d",&st[i].q1);
        printf("Quiz No.2 of %s: ",st[i].name);
        scanf("%d",&st[i].q2);
        printf("Quiz No.3 of %s: ",st[i].name);
        scanf("%d",&st[i].q3);

        fflush(stdin); //  Clears input buffer
        printf("\n");
    }
}


void displayData(STUD st[MAX]){
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("No.\tName\t\tQ1\tQ2\tQ3\tAve\tRemarks\n");
    printf("---------------------------------------------------------------\n");
    for (int i=0;i<MAX;i++)
        printf("%d.)\t%s\t\t%d\t%d\t%d\t%.2f\t%s\n",i+1,st[i].name,st[i].q1,st[i].q2,st[i].q3,aver(st[i].q1,st[i].q2,st[i].q3),aver(st[i].q1,st[i].q2,st[i].q3)>=75.0?"PASSED":"FAILED");

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("Press any key to continue...");
    getch();
}


float aver(int a, int b, int c){
  return(a+b+c)/3.0;

}
