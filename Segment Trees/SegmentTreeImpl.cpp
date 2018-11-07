#include<iostream>

using namespace std;

void buildTree(int *arr, int *tree, int s, int e, int cI){

    //base case
    if(s == e){
        tree[cI] = arr[s];
        return;
    }

    int mid = (s+e)/2;

    buildTree(arr,tree,s,mid,2*cI);
    buildTree(arr, tree, mid + 1,e,2*cI+1);

    tree[cI] = tree[2*cI] + tree[2*cI + 1];
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

int main(){

    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int * tree = new int[2 * n];
    buildTree(arr, tree, 0,n - 1,1);

    updateTree(arr, tree, 0, n - 1,1,2,10);

    cout<<query(tree, 0,n - 1,1,2,4)<<endl;
    /*

    for(int i = 1; i<2*n; i++){
        cout<<i<<" - "<<tree[i]<<endl;
    }*/

}
