#include<stdio.h>
#include<string.h>
#include<stdlib.h> //library for atoi(used to convert char to integer) function 

//structure to store the data of the student
typedef struct student
{
    int roll_no;
    char name[30];
    char dob[11];
}student;

void max_heapify(student s[],int parent,int size)
{
    //index of the left child
    int l=2*parent+1;
    //index of the right child
    int r=2*parent+2;

    int largest=parent;

    if(l<size) //if left child exists
    {
        if(s[l].roll_no>s[largest].roll_no) //if roll no of left is greater than parent's roll_no
        {
            largest=l; //update the index
        }
    }

    if(r<size)//if right child exists
    {
         if(s[r].roll_no>s[largest].roll_no) //if roll no of right is greater than parent's roll_no
        {
            largest=r; //update the index
        }
    }

    //if parent's roll_no is not largest
    if(largest!=parent)
    {
        //swap the values of student largest and parent
        int roll_no;
        char name[30],dob[11];
        roll_no= s[parent].roll_no;
        strcpy(name,s[parent].name);
        strcpy(dob,s[parent].dob);

        s[parent].roll_no= s[largest].roll_no;
        strcpy(s[parent].name,s[largest].name);
        strcpy(s[parent].dob,s[largest].dob);

        s[largest].roll_no= roll_no;
        strcpy(s[largest].name,name);
        strcpy(s[largest].dob,dob);

        //calling the max-heapify
        max_heapify(s,largest,size);
    }
}

void build_max_heap(student s[],int size)
{
    int i=0;
    for(i=size-2;i>=0;i--)
    {
        max_heapify(s,i,size);
    }
}

void heap_sort(student s[],int size)
{
    build_max_heap(s,size);

    int i=0;
    for(i=0;i<size;i++)
    {
        int roll_no;
        char name[30],dob[11];
        roll_no= s[0].roll_no;
        strcpy(name,s[0].name);
        strcpy(dob,s[0].dob);

        s[0].roll_no= s[size-i-1].roll_no;
        strcpy(s[0].name,s[size-i-1].name);
        strcpy(s[0].dob,s[size-i-1].dob);

        s[size-i-1].roll_no= roll_no;
        strcpy(s[size-i-1].name,name);
        strcpy(s[size-i-1].dob,dob);

        //calling the max_heapify function
        max_heapify(s,0,size-i-1);
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

    heap_sort(s,n_records);
    
    //closing the file
    fclose(fptr);

    //creating a file to insert sorted data
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\Student_sort_roll_no.txt","w");

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