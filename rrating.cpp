#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	// input the no. of queries
	long int n=0, i=0;
	cin>>n;
	string query[n];
	
	//for get the \n character
	cin.get();
	while(i<n)
	{
	    //input the query
	    getline(cin,query[i]) ;
	    i++;
	}

	i=0;
	
	//vector to store the ratings
	vector<long long int> v;
    long int j=0;
	
	while(i<n){
	    //if new rating has to be added
	    if(query[i][0] == '1'){
	        v.push_back(stoi(query[i].substr(2, query[i].length()-1)));
	        sort(v.begin(), v.end(), greater<int>());
            j++;
	    }
	    //if rating has to be displayed
	    else if(query[i][0] == '2'){
	        //no. of positive ratings
	        long int temp= j/3;
	        //if the no. of ratings are less than 3
	        if(temp == 0){
	            cout<< "No reviews yet\n";
	        }
	        else{
	            cout<< v[temp-1] << "\n";
	        }
	    }
        i++;
	}
	
	
	return 0;
}
