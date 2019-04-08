#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,int>m;
    int t;
	cin>>t;
	while(t != 0){
	    int u,v;
	    int sum = 0;
	    cin>>u>>v;
	    for(int i = 1; i<= 2*v;i += 2){
	        int x;
            cin>>x;
            m[x]++;
	    }

	    for(auto i: m){
            sum += i.second;
	    }
	    cout<<sum<<endl;
	    t--;
	}

    return 0;
}

