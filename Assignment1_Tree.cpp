#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->left = NULL;
            this->right = NULL;
            this->val = data;
        }
};

TreeNode* createTree(TreeNode* root){
    int data;
    cout<<"Enter the value for Node : ";
    cin>>data;
    if(data == -1){
        return NULL;
    }

    root = new TreeNode(data);
    int left,right;

    cout<<"Enter left child of node "<<data<<endl;
    root->left = createTree(root->left);

    cout<<"Enter right child of node "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}

void bfsTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void dfsTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    
    dfsTraversal(root->left);
    cout<<root->val<<" ";
    dfsTraversal(root->right);
}

int main(){
    TreeNode* root = NULL;
    root = createTree(root);

    cout<<"BFS Traversal : ";
    bfsTraversal(root);
    
    cout<<"DFS Traversal : ";
    dfsTraversal(root);
    
    return 0;
}