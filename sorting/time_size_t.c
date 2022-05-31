//program showing size_t data type and output in last
#include<stdio.h>
#include<stdlib.h>

int main(){
    //size_t is analogous to int
    //using size_t as a data type
    //size_t x;
    unsigned int x;
    printf("Enter the value of x: ");
    scanf("%u",&x);
    printf("x= %u\n",x);

    //size of variable of type size_t
    printf("Size of x in bytes is %d\n",sizeof(x));
   
}

/*
Sample Output 1
Enter the value of x: -100
x= -100
Size of x in bytes is 4

Sample Output 2
Enter the value of x: 100
x= 100
Size of x in bytes is 4
*/

