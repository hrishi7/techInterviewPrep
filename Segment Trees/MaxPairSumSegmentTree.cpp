#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct node{
    int maximum;
    int smaximum;
};

void buildTree(int *arr, node *tree, int treeIndex,int s, int e){

    //base case
    if(s == e){
        tree[treeIndex].maximum = arr[s];
        tree[treeIndex].smaximum = INT_MIN;
        return;
    }

    int mid = (s+e)/2;

    buildTree(arr,tree,2*treeIndex,s,mid);
    buildTree(arr, tree, 2*treeIndex + 1,mid + 1,e);

    node left = tree[2*treeIndex];
    node right = tree[2*treeIndex + 1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
    return;
}

void updateTree(int * arr, int* tree, int s, int e, int cI, int idx, int val){

    if(s == e){
        arr[idx] = val;
        tree[cI] = val;
        return;
    }
    int mid = (s + e)/2;
    if(mid < idx){
        updateTree(arr, tree, mid+ 1 ,e, 2*cI + 1, idx, val);
    }
    else{
        updateTree(arr, tree,s, mid,2*cI, idx, val);
    }
    tree[cI] = tree[2*cI] + tree[2*cI + 1];
}

int query(int* tree, int s, int e, int cI, int l, int r){

    //completely outside range
    if(s > r || e< l){
        return 0;
    }

    //completely inside range
    if(s >= l && e <= r){
        return tree[cI];
    }

    //partially inside or partially outside
    int mid = (s+e)/2;
    int ans1 = query(tree, s,mid,2*cI,l,r);
    int ans2 = query(tree, mid+1,e,2*cI + 1,l,r);
    return ans1+ans2;
}




//end
int main(){

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    node* tree = new node[3 * n];

    buildTree(arr, tree,1, 0,n - 1);




    for(int i = 0; i<3*n; i++){
        cout<<tree[i].maximum<<" , "<<tree[i].smaximum<<endl;
    }


}
