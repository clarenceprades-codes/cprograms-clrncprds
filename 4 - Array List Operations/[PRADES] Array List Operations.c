#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
    Name: Clarence Prades
    Year and Section: BSCS-NS-1A
    Course: Computer Programming 2
    Professor: Mr.Fernando Renegado
*/

#define MAX 100


typedef struct STUDENTS
{
    char name[25];
    int quiz1;
    int quiz2;
    int quiz3;
    float ave;
}STUD; // Struct

int last;

// FUNCTIONS DECLARATION
void    retrieve(STUD *temp); // Retrieve saved data on record file.
int     isfull(); // Check array if full.
char    menu(); // Main Menu Options.
int     isempty(); // Check array if empty.
void    getData(char *name, int *q1, int *q2, int *q3, float *ave); // Getting data from user.
float   compQuiz(int q1, int q2, int q3); // Computer for quizzes.
void    display(STUD *stu); // Display data  in tabular from.
void    del(STUD *s, char *n); // Delete record.
int     locate (STUD *stu, char *n); // Locate for deleting purposes.
void    save(STUD *stu); // Save data entered to file.
const char *remarks(float ave); // Assigning remarks.


int main() // Main Program
{
    STUD stu[MAX];
    retrieve(stu); // Retrieve data from file
    while(1)    //Infinite loop
    {
        switch(menu())
        {
            case '1':
            {
                if(isfull())
                {
                    printf("------------------------");
                    printf("\tArray is full.");
                            getch();
                }
                else
                {
                    system("cls");

                    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INSERT MODE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
                    getData(stu[last].name, &stu[last].quiz1, &stu[last].quiz2,&stu[last].quiz3, &stu[last].ave);  //passes the address of the last array index for addition of data
                    printf("\n\tRecord Saved.");
                    getch();
                    last++;
                }
            }
                break;

            case '2':
            {
                char name[20];
                system("cls");
                printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE MODE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
                printf("\tEnter name to delete: ");
                scanf(" %[^\n]s",name); // scans name with space
                del(stu,name);
            }
                break;

            case '3':
            {
                system("cls");
                display(stu); // For displaying
            }
                break;

            case '4':
            {
                printf("\n\n\tClosing Console.\n");
                save(stu); // saving before exit.
                exit(1);
            }
                break;

            default:
            {
                printf("\n\tInvalid Choice.");
                getch();
                continue;
            }
        }
    }
    return 0;
}
// FUNCTIONS DEFINITION

void retrieve(STUD *stu)
{
    int i=0;
    FILE* record=fopen("record.txt","r+");
    if(!record)
    {
        system("cls");
        printf("record.txt doesn't exist");
    }
    while(1)
    {
        if(fscanf(record,"{\n\t\"Name:\" \t\"%[^\"]\"\n \t\"Quiz 1:\" \t%d\n \t\"Quiz 2:\" \t%d\n \t\"Quiz 3:\" \t%d\n\t \"Average:\" \t%f\n}\n", stu[i].name, &stu[i].quiz1, &stu[i].quiz2,&stu[i].quiz3, &stu[i].ave)==EOF)   //if it reaches the end of file
        break;

        i++;
    }
    last=i;
    fclose(record);
}

int isfull()
{
    return(last==MAX);
}

char menu()
{
    char choice=0;
    system("cls");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    printf("\t[1] Insert Record\n");
    printf("\t[2] Delete Record\n");
    printf("\t[3] Display All Record\n");
    printf("\t[4] Exit\n");

    printf("\n\tPress the key of your choice (1-4): ");
   choice=getch();

    return choice;
}

int isempty()
{
    return(last==0);
}

void getData(char *name, int *q1, int *q2,int *q3, float *ave)
{
    printf("\tEnter name: ");
    scanf("%[^\n]s",name);
    printf("\tEnter quiz 1 of %s: ", name);
    scanf("%d",q1);
    printf("\tEnter the quiz 2 of %s: ", name);
    scanf("%d",q2);
    printf("\tEnter the quiz 3 of %s: ", name);
    scanf("%d",q3);
    *ave=compQuiz(*q1,*q2,*q3);
    printf("\n\tEntered Quiz 1: %d\n",*q1);
    printf("\tEntered Quiz 2: %d\n",*q2);
    printf("\tEntered Quiz 3: %d\n",*q3);
    printf("\tAverage: %.2f\n",*ave);

    getch();
}

float compQuiz(int q1, int q2, int q3)
{
    return (q1+q2+q3)/3.0;
}

void del(STUD *stu, char *n)
{
    int i,p;
    if(isempty())
        {
            printf("\n\tArray is empty.");
            getch();
        }
    else
        {
            p=locate(stu, n);
            if (p<0)
             {
                printf("\t------------------------");
                printf("\t %s Not found.",n);
                getch();
             }
            else
             {
                for(i=p;i<last;i++)
                    {
                       strcpy(stu[i].name, stu[i+1].name);
                       stu[i].quiz1=stu[i+1].quiz1;
                       stu[i].quiz2=stu[i+1].quiz2;
                       stu[i].quiz3=stu[i+1].quiz3;
                       stu[i].ave=stu[i+1].ave;
                    }
                  last--;   //moves back the last index of array
                  printf("\tDeleted Succesfully!");
                  getch();
             }
    }
}

int locate(STUD *stu, char *n)
{
    int i;
    for(i=0;i<=last;i++)
    {
        if(strcasecmp(stu[i].name,n)==0) // comparing inputted string on elements of struct name.
        {
            return i;   //return index position
        }
    }
    return(-1);
}

void display(STUD *stu)
{
    system("cls");
    int i;
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DATA RECORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");


    printf("\n\tNo.\tName\t\tQuiz1\tQuiz2\tQuiz3\tAverage\t  Remarks\n");

    for(i=0; i<last;i++)
    {
        printf("\t%d.)\t%-12s\t%d\t%d\t%d\t%0.2f\t  %-5s\n",i+1, stu[i].name, stu[i].quiz1,stu[i].quiz2,stu[i].quiz3, stu[i].ave, remarks(stu[i].ave));   //displays data in a tabular form with remarks
    }

    printf("\n\tOccupied Space: %d/%d ",last,MAX);
    getch();
}

const char* remarks(float ave)
{
    if (ave>=75.0)
        return "Passed";
    else
        return "Failed";
}

void save(STUD *stu)
{
    FILE* record=fopen("record.txt","w+");
    if(!record)
    {
        system("cls");
        printf("record.txt doesn't exist");
    }
    for(int i=0; i<last;i++)
    {
        fprintf(record,"{\n\t\"Name:\" \t\"%s\"\n \t\"Quiz 1:\" \t%d\n \t\"Quiz 2:\" \t%d\n \t\"Quiz 3:\" \t%d\n \t \"Average:\" \t%.2f\n}\n", stu[i].name, stu[i].quiz1, stu[i].quiz2,stu[i].quiz3, stu[i].ave);   //writes dat
    }
    fclose(record);
}


