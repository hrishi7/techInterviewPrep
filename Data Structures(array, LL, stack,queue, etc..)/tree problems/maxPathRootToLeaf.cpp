#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
template <typename T>

 class BinaryTreeNode {
 public :
     T data;
     BinaryTreeNode<T> *left;
     BinaryTreeNode<T> *right;

     BinaryTreeNode(T data) {
         this -> data = data;
         left = NULL;
         right = NULL;
     }
 };



void printPathsRecur(BinaryTreeNode<int>* node, int path[], int pathLen, vector<vector<int> > *vf)
{
  if (node==NULL) return;
  path[pathLen] = node->data;
  pathLen++;
  if (node->left==NULL && node->right==NULL)
  {
      vector<int>temp;
      for(int i = 0; i<pathLen; i++){
        //cout<<path[i]<<" ";
        temp.push_back(path[i]);
      }
      vf->push_back(temp);
  }
  else
  {
    printPathsRecur(node->left, path, pathLen,vf);
    printPathsRecur(node->right, path, pathLen,vf);
  }
}


void printPaths(BinaryTreeNode<int>* node)
{
  int path[1000];
  vector<vector<int> > vf;
  printPathsRecur(node, path, 0, &vf);
  int osum = INT_MIN;
  int r = -1;
  int i,j;
  for(i = 0; i<vf.size(); i++){
        int rsum = 0;
    for(j = 0; j< vf[i].size(); j++){
        rsum += vf[i][j];
    }
    if(osum < rsum){
        osum = rsum;
        r = i;
    }
  }
  for(int i = 0; i<vf[r].size(); i++){
    cout<<vf[r][i]<<" ";
  }
}


int main(){

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(-3);
    root->right = new BinaryTreeNode<int>(2);
    //root->left->left = new BinaryTreeNode<int>(4);
    /*root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);
*/
    printPaths(root);
    //maxSumPath(root);
}
