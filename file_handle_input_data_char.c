#include<stdio.h>

int main(void){
//creating file pointer
FILE *fptr;

//creating a new file for writing the input in it
//mode of the file is w
//if file does not exist it will create
//and write the data in it
fptr= fopen("C:\\Users\\adarsh\\Desktop\\DAA LAB\\input_data_char.txt","w");
char a='z';
//writing the data in the file using fprintf function
for(int i=0; i<32000; i++){
    fprintf(fptr,"%c ",a-(i%26));
}

fclose(fptr);
return 0;
}

