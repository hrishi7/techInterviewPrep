#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

int numNodes(TreeNode<int>* root)
{
    if(root == NULL)
        return 0;
    int ans = 1;
    for(int i = 0; i<root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

void printLevelK(TreeNode<int>* root, int k)
{
    if(root == NULL)
        return;
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    for(int i = 0; i< root->children.size(); i++)
    {
        printLevelK(root->children[i], k-1);
    }
}

void printLevelWise(TreeNode<int>* root)
{
     if(root == NULL)
        return;
    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() !=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        for(int i = 0; i<front->children.size(); i++)
        {
            cout<<front->children[i]->data<<",";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }

}

void printTree(TreeNode<int>* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<":";
    for(int i = 0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0; i<root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() !=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter No of children of"<< front->data<<endl;
        cin>>numChild;
        for(int i = 0; i<numChild; i++)
        {
            int childNum;
            cout<<"enter "<< i <<"th child";
            cin>>childNum;
            TreeNode<int>* child = new TreeNode<int>(childNum);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter No of children of "<<rootData<<endl;
    cin>>n;
    for(int i = 0; i<n ; i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<numNodes(root);
    cout<<endl;
    printLevelK(root,2);
    delete root;
}
