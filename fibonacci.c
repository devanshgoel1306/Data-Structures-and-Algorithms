//program on fibonacci series using recursion
//1, 1, 2, 3, 5, 8, ...
#include<stdio.h>

int fibonacci(int n){

if(n==1 || n==2) return 1; //base condition

else{
    return fibonacci(n-1)+fibonacci(n-2);
}

}
int main(void){
int ans= fibonacci(10);
printf("%d",ans);
return 0;
}
/*Sample Ouput
55
*/

//Recurrence relation
//T(n)= T(n-1)+T(n-2)
