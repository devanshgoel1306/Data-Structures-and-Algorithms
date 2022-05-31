//sorting the data of the students according to date of birth
//statement printf("\n") is mandatory
//otherwise program will not work properly
//this is for vs code only.
//It will work perfectly for Code Blocks.
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

//comparing the dob
int compare(char dob1[],char dob2[])
{
    char d1[3],d2[3],m1[3],m2[3],y1[5],y2[5];
    int i=0,j=0;

    //extracting date from dob
    while(i<2)
    {
        d1[i]=dob1[i];
        i++;
    }
    i=0;
    while(i<2)
    {
        d2[i]=dob2[i];
        i++;
    }

    //extracting month from dob
    i=0,j=3;
    while(i<2)
    {
        m1[i]=dob1[j];
        i++; j++;
    }
    i=0,j=3;
    while(i<2)
    {
        m2[i]=dob2[j];
        i++; j++;
    }

    j=6;i=0;
    while(i<4)
    {
        y1[i]=dob1[j]; i++; j++;
    }
    i=0,j=6;
    while(i<4)
    {
        y2[i]=dob2[j]; i++; j++;
    }

    int D1,D2,M1,M2,Y1,Y2;
    D1= atoi(d1); 
    D2= atoi(d2);
    M1= atoi(m1);
    M2= atoi(m2);
    Y1= atoi(y1);
    Y2= atoi(y2);
    //printf("%d %d %d %d %d %d\n",D1,D2,M1,M2,Y1,Y2);
    //compare the year
    if(Y1>Y2) return 1;
    else if(Y1<Y2) return 0;

    if(Y1==Y2)
    {
        if(M1>M2) return 1; //if month M1 is greater
        else if(M1<M2) return 0; //if Month M2 is greater
        else if(M1==M2)
        {
            if(D1>D2) return 1;
            else return 0;
        }
    }
    return 0;
}

void max_heapify(student s[],int parent,int size)
{
    printf("\n"); //we are using this statement to overcome vs code compiler problem
    //it will work perfectly even without above statement in Code Blocks
    //index of the left child
    int l=2*parent+1;
    //index of the right child
    int r=2*parent+2;

    int largest=parent;

    if(l<size) //if left child exists
    {
        if(compare(s[l].dob,s[largest].dob)) //if dob of left is greater than parent's dob
        {
            largest=l; //update the index
        }
    }

    if(r<size)//if right child exists
    {
         if(compare(s[r].dob,s[largest].dob)) //if dob of right is greater than parent's dob
        {
            largest=r; //update the index
        }
    }

    //if parent's dob is not largest
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
    for(i=0;i<size-1;i++)
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
    
    //allocating the memory dynamically for student structure
    student s[n_records];

    //creating the file pointer
    FILE* fptr;

    //open the file in reading mode
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\Input file.txt","r");

    if(fptr==NULL) printf("I failed!");

    int i=0,j=0;
    char xyz;
    
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
    fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\Student_sort_dob.txt","w");

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