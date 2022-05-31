//reading a file word by word
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  string s;
  //creating a file pointer
  //we use ifstream for reading a file
  ifstream my_file("practical3.txt");

  my_file>>s;

  while(!my_file.eof())
  {
    cout<<s<<endl;
    my_file>>s;
  }

  //closing the file
  my_file.close();
  return 0;
}

/*Output
191803
ISHIKA
GARG
11-03-1989
191543
BHAVYA
GUPTA
01-03-1990
191022
KARAN
VERMA
25-03-1990
191018
PRATHAM
BHARDWAJ
31-08-1990
191537
KALPIT
BANSAL
21-09-1990
191001
HARSHIT
THAKUR
10-01-1991
191534
MADHUMESH
SHUKLA
14-04-1992
191005
SAKSHAM
GUPTA
26-03-1993
191049
SHIVENDRA
SINGH
10-06-1995
191802
HIMANSHU
KUMAR
28-10-1996
*/
