#include<iostream>
#include<map>
#include<iterator>

using namespace std;


void pairSum(int input[], int size, int x) {
	map<int, int>m1;
    map<int, bool>m2;
    map<int, int>::iterator itr;
    map<int, int>::iterator itr4;
    map<int, bool>::iterator itr2;
    map<int, bool>::iterator itr3;


    for(int i = 0; i < size; i++){
        m1[input[i]]++;
        m2[input[i]] = false;
    }
    for(itr = m1.begin();itr != m1.end();  ++itr){
        //first find mathcing element if found print and make that element true
        itr3 = m2.find(itr->first);

        if(itr3->second == false){
            //not visited do the search and make it mark
            if(x >= itr->first){
                itr3 = m2.find(x - itr->first);
                if( itr3 -> second == false){
                    int diff = x - itr->first;
                    itr4 = m1.find(diff);
                    int times = (itr->second) * (itr4->second);
                    m2[itr->first] = true;
                    m2[diff] = true;
                    for(int i = 1; i<= times; i++){
                        if(itr->first < diff){
                            cout<<itr->first <<" "<<diff<<endl;
                        }else{
                            cout<<diff <<" "<<itr->first<<endl;
                        }
                    }
                }
            }
        }

    }
}

int main(){
    int sized = 9;
    int input[9] = {1 ,3, 6, 2, 5, 4, 3, 2, 4};
    int x = 7;
    pairSum(input,sized,x);

}
