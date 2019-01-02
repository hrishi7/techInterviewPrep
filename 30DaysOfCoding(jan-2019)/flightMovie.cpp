#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


//nlogn solution
bool canpassengerwatchMovie(int fR, vector<int> mR){
    int s = mR.size();
    for(int i = 0; i<s; i++){
        if(mR[i] > fR){
            continue;
        }
        for(int j = i + 1; j<s; j++){
            if(mR[i] + mR[j] ==fR){
                return true;
            }
        }
    }
    return false;
}


//n^2 solution
bool CanPassengerViewTwoMovies(int fR, vector<int> mR){
    int vectorSize = mR.size();
    for(int i = 0; i< vectorSize; i++){
        for(int j = i + 1; j<vectorSize; j++){
            if(mR[i] + mR[j] ==fR){
                return true;
            }
        }
    }
    return false;
}

//o(n) time and o(n) space

bool canpassengerwatchMovieOpti(int fR, vector<int> mR){
    unordered_set<int>mLSeen;
    int s = mR.size();
    for(int i = 0; i< s; i++){
        int x = fR - mR[i];
        if(mLSeen.find(x) != mLSeen.end()){
            return true;
        }
        mLSeen.insert(mR[i]);
    }
    return false;
}
/*
bool searchBinary(int el, vector<int>v,int s,int e){
    if(s > e){
        return 0;
    }
    else if(s == e){
        if(v[s] == el)
            return true;
        else return false;
    }
    int mid = s/2;
    if(v[mid] == el){
        return true;
    }
    if(el < v[mid])
        return searchBinary(el,v,s,mid - 1);
    else
        return searchBinary(el,v,mid +1,e);
}


//o(logn) binary search solution
bool canWatchMovie(int fR, vector<int>mR){
    int s = mR.size();
    for(int i = 0; i<s; i++){
        if(mR[i]> fR){
            continue;
        }
        int el = fR - mR[i];
        if(searchBinary(el,mR,0,s-1)){
            return true;
        }
    }
    return false;
}

*/

int main(){

    vector<int> movieRuntime = {4,5,8,3,2};
    int flightRuntime = 5;
    sort(movieRuntime.begin(),movieRuntime.end());
    cout<<canWatchMovie(flightRuntime, movieRuntime)<<endl;
    //cout<<canpassengerwatchMovieOpti(flightRuntime, movieRuntime)<<endl;
    //cout<<canpassengerwatchMovie(flightRuntime, movieRuntime)<<endl;

    return 0;
}
