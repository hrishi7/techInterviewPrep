#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

vector<string> v;

string getString(int d){
    if(d == 2){
        return "abc";
    }
    if(d == 3){
        return "def";
    }
    if(d == 4){
        return "ghi";
    }
    if(d == 5){
        return "jkl";
    }
    if(d == 6){
        return "mno";
    }
    if(d == 7){
        return "pqrs";
    }
    if(d == 8){
        return "tuv";
    }
    if(d == 9){
        return "wxyz";
    }
    return " ";
}


int keypadCombination(int input, string output[]){

    if(input == 0 ){
        output[0] = "";
        return 1;
    }
    int lastDigit = input % 10;
    int smallNumber = input / 10;

    int smallOutputSize = keypadCombination(smallNumber, output);

    string options = getString(lastDigit);

    for(int i = 0; i<options.length() - 1; i++){
        for(int j = 0; j< smallOutputSize; j++){
            output[j + (i + 1)*smallOutputSize] = output[j];
        }
    }


    int k = 0;
    for(int i = 0; i<options.length(); i++){
        for(int j = 0; j<smallOutputSize; j++){
            output[k] = output[k] + options[i];
            k++;
        }
    }

    return smallOutputSize*options.length();
}

void keypadCombinationPrintOnly(int input, string output){
    if(input == 0){
        cout<<output<<endl;
        return ;
    }
    int lastDigit = input % 10;
    int smallNumner = input / 10;
    string options = getString(lastDigit);

    for(int i = 0; i< options.length(); i++){
        keypadCombinationPrintOnly(smallNumner,options[i]+ output);
    }
}

void subsPrint(string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    //without including current char
    string smallString = input.substr(1);
    subsPrint(smallString,output);

    //with including current char
    output = output + input[0];
    subsPrint(smallString,output);
}
void subsPrintVectorStore(string input, string output){
    if(input.length() == 0){
        v.push_back(output);
        return;
    }
    //without including current char
    string smallString = input.substr(1);
    subsPrintVectorStore(smallString,output);

    //with including current char
    output = output + input[0];
    subsPrintVectorStore(smallString,output);
}
int subs(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOutputSize = subs(smallString, output);
    for(int i = 0; i< smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2* smallOutputSize;
}
int main(){
    int input;
    cin>>input;
    keypadCombinationPrintOnly(input, "");

    return 0;
}
