#include<iostream>
#include "Trie.h"

using namespace std;

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("dot");
    t.insertWord("are");
    t.insertWord("bed");

    cout<<t.searchWord("are")<<endl;

    t.removeWord("are");

    cout<<t.searchWord("are")<<endl;
    return 0;
}
