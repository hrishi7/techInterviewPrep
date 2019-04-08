#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
  public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool areMirror(TreeNode<int> *r1, TreeNode<int> *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;
    return r1->data == r2->data && areMirror(r1->left, r2->right) && areMirror(r1->right, r2->left);
}


int height(TreeNode<int> * root){
    if(root == NULL)    return 0;
    int left = height(root->left);
    int right = height(root->right);
    int h = -1;
    if(left > right){
        h = 1+ left;
    }else{
        h = 1 + right;
    }
    return h;
}

int diameter(TreeNode<int>* root){
    if(root == NULL)    return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int dleft = diameter(root->left);
    int dright = diameter(root->right);
    int fd = max(lheight +rheight + 1,max(dleft, dright));
    return fd;
}

int main()
{
    //1st tree
    TreeNode<int> *root = new TreeNode<int>(15);
    root->left = new TreeNode<int>(5);
    root->left->left = new TreeNode<int>(1);
    root->right = new TreeNode<int>(20);
    root->right->right = new TreeNode<int>(25);

    //2nd tree
    TreeNode<int> *root2 = new TreeNode<int>(15);
    root2->left = new TreeNode<int>(20);
    root2->left->left = new TreeNode<int>(25);
    root2->right = new TreeNode<int>(5);
    root2->right->right = new TreeNode<int>(1);
    bool ans = areMirror(root, root2);
    if (ans)
        cout << "Yes :)" << endl;
    else
        cout << "No :(" << endl;

    cout<<diameter(root);
}
