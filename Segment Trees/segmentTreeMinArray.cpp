#include<iostream>
#include<bits/stdc++.h>

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

    tree[cI] = min(tree[2*cI] , tree[2*cI + 1]);
}

void updateTree(int * arr, int* tree, int s, int e, int cI, int idx, int val){

    if(s == e){
        arr[idx] = val;
        //tree[cI] = val;
        return;
    }
    int mid = (s + e)/2;
    if(mid < idx){
        updateTree(arr, tree, mid+ 1 ,e, 2*cI + 1, idx, val);
    }
    else{
        updateTree(arr, tree,s, mid,2*cI, idx, val);
    }
    tree[cI] = min(tree[2*cI] , tree[2*cI + 1]);
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
    return min(ans1,ans2);
}





//end
int main(){

    int t;
    int n;
    cin>>n>>t;
    int *arr = new int[n + 1];
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    int * tree = new int[3 * n];

    buildTree(arr, tree, 1,n,1);

    //updateTree(arr, tree, 1, n ,1,3,6);
     for(int i = 1; i<3*n; i++){
        cout<<tree[i]<<endl;
    }
    //updateTree(arr, tree, 0, n - 1,1,2,10);

    //cout<<query(tree, 0,n - 1,1,2,4)<<endl;

    while(t--){
            char qu;
            int f,s;
            cin>>qu>>f>>s;
            if(qu == 'q'){
                cout<<query(tree, 1,n,1,f,s)<<endl;

            }
            if(qu == 'u'){
                updateTree(arr, tree, 1, n ,1,f,s);

            }

    }
    /*buildTreeMinEl(arr,tree,0,n - 1,1);
    for(int i = 1; i<2*n; i++){
        cout<<i<<" - "<<tree[i]<<endl;
    }
    //updateTree(arr,tree,0,n-1,1,2,10);
    cout<<queryMinEl(tree,0,n-1,1,2,4)<<endl;*/
    return 0;
}
