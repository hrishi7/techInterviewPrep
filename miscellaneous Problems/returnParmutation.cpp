#include<iostream>
#include <string>
using namespace std;

int helperreturnPermutations(string input, string output[]){
  if(input[0] == '\0'){
    output[0] = "";
    return 1;
  }
  char first = input[0];
  string smallOutput[500];
  int size = helperreturnPermutations(input.substr(1), smallOutput);
  int k = 0;
  for(int i = 0; i< size; i++){
    output[k] = first + smallOutput[i];
    k++;
  }
  return k;
}

int returnPermutations(string input, string output[]){
  int k = 0;
  string newInput = "";
  for(int i = 0; i< input.size(); i++){
    newInput += input[i];
    newInput += input.substr(0,i);
    newInput += input.substr(i +1);
    k += helperreturnPermutations(newInput, output);
  }
  return k;
}

int main(){
    string output[1000];
    int k = returnPermutations("abc",output);

    /*for(int i = 0; i< k; i++){
        cout<<output[i]<<endl;
    }*/
    return 0;
}
