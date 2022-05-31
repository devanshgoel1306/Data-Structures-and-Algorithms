//square root of an integer
//algo similar to binary search
//reference- https://www.youtube.com/watch?v=QkHYa_EImFg
//https://practice.geeksforgeeks.org/problems/count-squares3649/1#

#include<bits/stdc++.h>

using namespace std;

//here n can take value upto 10^18
//time complexity is O(log n)
int solve(int n)
{
    long long int start= 1, mid= 0, end= 100000, ans= 0, flag= 0;

    while(start <= end)
    {
        mid= (start+end)/2;

        if(mid*mid > n)
        {
            end= mid-1;
        }
        else if(mid*mid < n)
        {
            ans= mid;
            start= mid+1;
        }
        else if(mid*mid == n)
        {
            flag= 1;
            ans= mid;
            break;
        }
    }

    if(flag) ans-=1;
    return ans;
}

//time complexity 0(sqrt(n))
int solve1(int n)
{
    int count= 0;

    for(int i=1; i*i < n; i++)
    {
        count++;
    }

    return count;
}

int main(void)
{
    int n= 0;
    cout<< "Enter the value of n: ";
    cin>> n;

    cout<< "Count of squares less than "<< n << " is " << solve(n) <<"\n";
    return 0;
}