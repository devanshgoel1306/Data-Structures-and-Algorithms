#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//structure to store the data of the student
typedef struct student
{
    int roll_no;
    char name[30];
    char dob[11];
}student;

//insertion sort is similar to sorting the cards in hand
void insertion_sort(student s[],int size)
{
    int i=0,j=0;
    int roll,roll_no;
    char name[30],dob[11],n[30],d[11];
    //we start with i=1 because 1st card is already sorted
    for(i=1;i<size;i++)
    {
        j=i-1;
        //it is the key value
        roll_no= s[i].roll_no;
        strcpy(n,s[i].name);
        strcpy(d,s[i].dob);

        while(j>=0 && s[j].roll_no>roll_no)
        {
            //shift the record towards right
            s[j+1].roll_no= s[j].roll_no;
            strcpy(s[j+1].name,s[j].name);
            strcpy(s[j+1].dob,s[j].dob);

            j--;
        }

        //place the ith record at its correct position
        j++; //j is decremented one more time in while loop
        s[j].roll_no= roll_no;
        strcpy(s[j].name,n);
        strcpy(s[j].dob,d);
    }
}

int main()
{
    //input the no. of records
    int n_records=0;
    printf("Enter the no. of records: ");
    scanf("%d",&n_records);
    
    student s[n_records];

    //creating the file pointer
    FILE* fptr;

    //open the file in reading mode
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\Input file.txt","r");

    if(fptr==NULL) printf("I failed!");

    int i=0,j=0;
    char xyz;
    
    //fetching the data from the file
    while(!feof(fptr) && i<n_records)
    {
        fscanf(fptr,"%d",&s[i].roll_no);
        xyz= fgetc(fptr);
        while(xyz==' ') xyz= fgetc(fptr);
        
        fgets(s[i].name,30,fptr);
        //loop to truncate the string when \n is encountered
        j=0;
        while(j<30)
        {
            if(s[i].name[j]=='\n')
            {
                s[i].name[j]= '\0';
                break;
            }
            j++;
        }

        fgets(s[i].dob,11,fptr);
        i++;
    }

    insertion_sort(s,n_records);
    
    //closing the file
    fclose(fptr);

    //creating a file to insert sorted data
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\Student_insertion_sort_roll_no.txt","w");

    for(i=0;i<n_records;i++)
    {
        fprintf(fptr,"%d\n",s[i].roll_no);
        fprintf(fptr,"%s\n",s[i].name);
        fprintf(fptr,"%s\n\n",s[i].dob);
    }

    //closing the file
    fclose(fptr);

    return 0;
}