#include <cstdio>

struct Node {
    Node* left;
    Node* right;
    int val;

    Node(int x = 0) : left(nullptr), right(nullptr), val(x) {}
};


Node* insert(Node* root, int val) {
    if(val < root->val) {
        if(root->left == nullptr) {
            root->left = new Node(val);
        } else {
            root->left = insert(root->left, val);
        }

    } else {
        if(root->right == nullptr) {
            root->right = new Node(val);
        } else {
            root->right = insert(root->right, val);
        }

    }

    return root;
}

void inOrder(Node* root) {
    if(!root) return;

    inOrder(root->left);
    printf(" %d", root->val);
    inOrder(root->right);
}

void preOrder(Node* root) {
    if(!root) return;

    printf(" %d", root->val);
    if(root->left) preOrder(root->left);
    if(root->right) preOrder(root->right);
}

void postOrder(Node* root) {
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    printf(" %d", root->val);
}


int main() {
    Node* root;

    int n, tmp;
    scanf("%d", &n);

    scanf("%d", &tmp);
    root = new Node(tmp);

    for(int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }


  	printf("InOrder traversal:");
    inOrder(root);

    printf("\nPreOrder traversal:");
    preOrder(root);

    printf("\nPostOrder traversal:");
    postOrder(root);

    return 0;
}
