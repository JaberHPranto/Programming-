#include<iostream>
#include<queue>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data=data;
    newNode->left=newNode->right= NULL;
    return newNode;

}

BstNode* Insert(BstNode* root,int data)
{

    if(root==NULL){
        root=GetNewNode(data);
    }
    else if(data <= root->data){
        root->left=Insert(root->left,data);
    }
    else {
        root->right=Insert(root->right,data);
    }
    return root;
}

bool Find(BstNode* root,int data)
{

    if(root==NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data){
        return Find(root->left,data);
    }
    else {
        return Find(root->right,data);
    }
}

int FindMin(BstNode* root)
{
    if(root==NULL)return -1;
        while(root->left!=NULL)
            {
               root=root->left;
            }
              return root->data;
}

int FindMax(BstNode* root)
{
    if(root==NULL)return -1;
        while(root->right!=NULL)
            {
               root=root->right;
            }
              return root->data;
}
BstNode* Delete(BstNode* root,int data)
{
    if(root==NULL) return root;
    else if(data<root->data)root->left=Delete(root->left,data);
    else if(data>root->data)root->right=Delete(root->right,data);
    else{
        // Case:1 -> No Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        // Case:2 -> One Child
        else if(root->left==NULL){
            BstNode*temp=root;
            root=root->right;
            delete temp;
        }
       else if(root->right==NULL){
            BstNode*temp=root;
            root=root->left;
            delete temp;
       }
       // Case:3 -> Two Child
       else {
        BstNode* temp=(BstNode*)FindMin(root->right);
        root->data=temp->data;
        root->right=Delete(root->right,temp->data);
    }
    }
    return root;
}
void BstBfs(BstNode *root)
{

    if(root==NULL)return ;
    queue<BstNode*>q;
    q.push(root);
    while(!q.empty()){
        BstNode* current=q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        q.pop();
    }

}
void BstDfs(BstNode *root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    BstDfs(root->left);
    BstDfs(root->right);
}
int main()
{
    BstNode* root=NULL;
    root=Insert(root,25);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,35);
    root=Insert(root,8);
    root=Insert(root,40);
    int number ;
    //Delete(root,20);
    BstBfs(root);
    cout<<endl;
    BstDfs(root);
   // number=FindMax(root);
    //cout<<number<<endl;
   cout<<"Enter number be searched"<<endl;
    cin>>number;
    if(Find(root,number)==true)cout<<"Found\n";
    else cout<<"Not Found"<<endl;
}

















