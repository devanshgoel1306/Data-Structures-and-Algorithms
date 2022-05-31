//search in a rotated sorted array
//algo is similar to binary search
//reference- https://www.youtube.com/watch?v=QkHYa_EImFg

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int target)
{
    int index= -1, start= 0, end= arr.size()-1, mid=0;

    while(start <= end)
    {
        mid= (start+end)/2;

        if(arr[mid] == target)
        {
            index= mid;
            break;
        }
        else if(arr[mid] < arr[0])
        {
            if(target >= arr[0] || target < arr[mid])
            {
                end= mid-1;
            }
            else if(target > arr[mid] || target < arr[0])
            {
                start= mid+1;
            }
            
        }
        else if(arr[mid] >= arr[0]){
            if(target > arr[mid] || target < arr[0])
            {
                start= mid+1;
            }
            else if(target < arr[mid])
            {
                end= mid-1;
            }
        }
    }

    return index;

}

int main()
{
    //reading from a text file
    ifstream myfile("binary_rotate_input.txt");

    int num=0;
    vector<int> arr;

    //reading the integers from the input file
    while(myfile >> num)
    {
        arr.push_back(num);
    }

    //closing the file
    myfile.close();

    //last element in the arr vector is target
    int target= arr.back();

    //popping the last element from vector arr
    //to get the actual array
    arr.pop_back();
    

    int index= solve(arr, target);

    if(index == -1)
    {
        cout<< "Target not found.\n";
    }
    else{
        cout<< "Target found at index "<<index << ".\n";
    }


    return 0;
}