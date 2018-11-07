#include<iostream>
#include<queue>
#include<vector>
#include "BinaryTreeNode.h"
#include "Node.h"
using namespace std;
int prevLen= 0;
vector<int> v;


bool isMirror(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL || root->right == NULL) {
        return false;
    }
    if(root->left != NULL && root->right != NULL){
        if(root->left->data != root->right->data)
            return false;
    }
    queue<BinaryTreeNode<int>*>q;

    q.push(root->left);
    q.push(root->right);
    BinaryTreeNode<int>*first = NULL, *second = NULL;

    // traversal loop
    while (!q.empty())
    {
       // Pop two items from queue
       first = q.front();
       q.pop();
       second = q.front();
       q.pop();

       // Print children of first and second in reverse order
       if(first->left->data != second->right->data){
            return false;
       }
       if(first->right->data != second->left->data){
            return false;
       }

       // If first and second have grandchildren, enqueue them
       // in reverse order
       if (first->left->left != NULL)
       {
           q.push(first->left);
           q.push(second->right);
           q.push(first->right);
           q.push(second->left);
       }
    }
    return true;

}


long long int helperLeafToLeafSum(BinaryTreeNode<int> *root){

    if(root == NULL)
        return 0;
    long long int leftSum = helperLeafToLeafSum(root->left);
    long long int rightSum = helperLeafToLeafSum(root->right);
    return root->data + max(leftSum, rightSum);
}

long long int leafToleafMax(BinaryTreeNode<int> *root){
    long long int leftSum = helperLeafToLeafSum(root->left);
    long long int rightSum = helperLeafToLeafSum(root->right);
    return (root->data + leftSum + rightSum);
}

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    vector<node<int>* > v;
    // Base Case
    if (root == NULL)  return v;
    queue<BinaryTreeNode<int> *> q;
    node<int>* head = NULL;
    node<int>* tail = NULL;
    q.push(root);
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            BinaryTreeNode<int>* frontNode = q.front();
            q.pop();
            if (frontNode->left != NULL)
                q.push(frontNode->left);
            if (frontNode->right != NULL)
                q.push(frontNode->right);

            node<int>* n = new node<int>(frontNode->data);
            if(head != NULL)
            {
            	tail->next = n;
            	tail = n;
            }
            else
            {
               	head = n;
              	tail = n;
            }
            nodeCount--;
        }
        v.push_back(head);
        head = NULL;
        tail = NULL;
    }

  return v;

}

void printArray(int path[], int n){
    if(prevLen < n){
        prevLen = n;
        while(!v.empty()){
            v.pop_back();
        }
        for(int i = 0; i<n; i++){
            v.push_back(path[i]);
        }
    }
    for(int i = 0; i<n; i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void printpathRec(BinaryTreeNode<int>* root,int path[], int pathLength){
    if(root == NULL)    return;

    path[pathLength] = root->data;
    pathLength++;

    if(root->left == NULL && root->right == NULL){
        printArray(path, pathLength);
    }
    else{
        printpathRec(root->left, path, pathLength);
        printpathRec(root->right, path, pathLength);
    }
}

void printPaths(BinaryTreeNode<int>* root){
    int path[1000];
    printpathRec(root, path,0);
}

void printTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<" L "<<root->left->data;
    }
    if(root->right != NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter data:"<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputlevelWise()
{
    int rootData;
    cout<<"Enter Root data:"<<endl;
    cin>>rootData;
    if(rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter Right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreelevelWise(BinaryTreeNode<int>* root)
{
     if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front != NULL)
            cout<<front->data<<" : ";
        if(front->left != NULL){
            cout<<" L "<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right != NULL){
            cout<<" R "<<front->right->data;
            pendingNodes.push(front->right);
        }

        cout<<endl;
    }
}

int numNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    int ans = 1;
    return ans + numNodes(root->left) + numNodes(root->right);
}

void inOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
/*int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    return 1+ max(height(root->left),height(root->right));
}

int diameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}
*/
pair<int, int> heightDiameter(BinaryTreeNode<int>* root)
{
    if(root == NULL){
        pair<int,int>p;
        p.first =0 ;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh,rh);
    int diameter = max(lh+ rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}


void levelOrder(BinaryTreeNode<int>* root){
    if(root == NULL)    return;

    cout << root->data;

    // / Since it is perfect Binary Tree, right is not checked
    if (root->left != NULL)
      cout << " " << root->left->data << " " << root->right->data;

    // Do anything more if there are nodes at next level in
    // given perfect Binary Tree
    if (root->left->left == NULL)
        return;

    // Create a queue and enqueue left and right children of root
    queue<BinaryTreeNode<int>*>q;
    q.push(root->left);
    q.push(root->right);

    // We process two nodes at a time, so we need two variables
    // to store two front items of queue
    BinaryTreeNode<int>*first = NULL, *second = NULL;

    // traversal loop
    while (!q.empty())
    {
       // Pop two items from queue
       first = q.front();
       q.pop();
       second = q.front();
       q.pop();

       // Print children of first and second in reverse order
       cout << " " << first->left->data << " " << second->right->data;
       cout << " " << first->right->data << " " << second->left->data;

       // If first and second have grandchildren, enqueue them
       // in reverse order
       if (first->left->left != NULL)
       {
           q.push(first->left);
           q.push(second->right);
           q.push(first->right);
           q.push(second->left);
       }
    }
}
int main()
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
{
    vector<node<int>*> vfinal;
   /* BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */
    BinaryTreeNode<int>* root = takeInputlevelWise();
    /*printTreelevelWise(root);
    cout<<endl;
    cout<<numNodes(root);
    inOrder(root);
    pair<int, int> p = heightDiameter(root);
    cout<<"diameter: "<<p.second<<endl;
    cout<<"height: " <<p.first<<endl;*/
    /*printPaths(root);
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }*/
    //levelOrder(root);
    //vfinal = createLLForEachLevel(root);
    /*for(int i = 0; i<vfinal.size(); i++){
        for(int j = 0; j<vfinal[i].size(); j++ ){
            cout<<vfinal[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //cout<<leafToleafMax(root)<<endl;
    cout<<isMirror(root)<<endl;
    delete root;
}
