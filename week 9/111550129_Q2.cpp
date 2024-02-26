#include<iostream>
using namespace std;
struct TreeNode{
    int value,height;
    TreeNode *lchild,*rchild;
    TreeNode(int v):value(v),height(1),lchild(NULL),rchild(NULL){}
};

int getHeight(TreeNode* root){
	// TODO
	if(root==nullptr){
        return 0;
	}else{
        return root->height;
	}

}

int getbalanceFactor(TreeNode* root){
    // TODO
    if(root==nullptr)return 0;
    else return getHeight(root->lchild)-getHeight(root->rchild);
}

void updateHeight(TreeNode* root){
    // TODO
    root -> height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

TreeNode* L(TreeNode* &root){
	// TODO
	TreeNode*tmp=root->rchild;
	root->rchild=tmp->lchild;
	tmp->lchild=root;
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
	tmp->height=max(getHeight(tmp->lchild),getHeight(tmp->rchild))+1;
	return tmp;
}

TreeNode* R(TreeNode* &root){
	// TODO
	TreeNode*tmp=root->lchild;
	root->lchild=tmp->rchild;
	tmp->rchild=root;
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
	tmp->height=max(getHeight(tmp->lchild),getHeight(tmp->rchild))+1;
	return tmp;
}

TreeNode* insert(TreeNode* &root,int v){
    if(root == NULL){
        root = new TreeNode(v);
        return root;
    }else
    if(v < root->value){
		// TODO
		insert(root->lchild,v);
    }else{
		// TODO
		insert(root->rchild,v);
    }
    updateHeight(root);
    int balance = getbalanceFactor(root);
    if(balance > 1 && root -> lchild -> value > v){ // LL
        root=R(root);
        return root;
    }
    if(balance < -1 && root -> rchild -> value < v){ // RR
        root=L(root);
        return root;
    }
    if(balance > 1 && root -> lchild -> value < v){ // LR
        root->lchild=L(root->lchild);
        root=R(root);
        return root;
    }
    if(balance < -1 && root -> rchild-> value > v){ // RL
        root->rchild=R(root->rchild);
        root=L(root);
        return root;
    }
    return root;
}



int main(){
    int n,tmp;
    TreeNode* root = NULL;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&tmp);
        insert(root,tmp);
    }
    printf("%d\n",root->value);
    return 0;
}
