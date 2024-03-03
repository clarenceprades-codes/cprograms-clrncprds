//Using function and global variables
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3

//global variables declared the function
//accessible to all functions in the program

void getData(char name[][15], float *q1, float *q2, float *q3);//populate the arrays
float aveGrade(float a, float b, float c);
void display(char name[][15],float q1[], float q2[], float q3[]);//display in tabular form

int main(){
    float q1[MAX];
    float q2[MAX];
    float q3[MAX];
    char name[MAX][15];
    int i;

    for(i=0;i<MAX;i++)
        getData(&name[i],&q1[i], &q2[i], &q3[i]);

    display(name,q1,q2,q3);
    return 0;
}
void getData(char name[][15], float *q1, float *q2, float *q3){
{
    printf("Input name: ");
    scanf("%s",name);
    printf("Input Q1: ");
    scanf("%f",q1);
    printf("Input Q2: ");
    scanf("%f",q2);
    printf("Input Q3: ");
    scanf("%f",q3);
    printf("\n");
  }

}
float aveGrade(float a, float b, float c){
    return(a+b+c)/3.0;
}

void display(char name[][15],float q1[], float q2[], float q3[]){
    int i;
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("No.\tName\tQ1\tQ2\tQ3\tAve\tRemarks\n");
    printf("---------------------------------------------------------\n");

    for(i=0;i<MAX;i++)
    printf("%d.)\t%s\t%.0f\t%.0f\t%.0f\t%0.2f\t%s\n",i+1,name[i],q1[i],q2[i],q3[i],aveGrade(q1[i],q2[i],q3[i]),aveGrade(q1[i],q2[i],q3[i])>=75.0?"PASSED":"FAILED");

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("Press any key to continue...");
    getch();
}
