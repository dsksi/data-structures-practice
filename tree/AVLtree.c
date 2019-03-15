#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

struct _node {
    struct _node* left;
    struct _node* right;
    int value;
};


tree newTree(void); 
tree newNode(int n);
int depth(tree t); 
int search(tree t, int n); 
tree insert(tree t, int n); 
tree rotateL(tree t); 
tree rotateR(tree t); 
tree rebalanceNode(tree t); 
void printLevel(tree t); 

tree newTree(void) {
    tree t = malloc(sizeof(tree));
    printf("New tree made\n");
    return t;
}

tree newNode(int n) {
    tree new = malloc(sizeof(node));
    new->left = new->right = NULL;
    new->value = n;
    return new;
}

int depth(tree t) {
    //printf("checking depth\n\n");
    if (t == NULL) return 0;
    int leftH = depth(t->left);
    int rightH = depth(t->right);
    int height = leftH > rightH ? leftH : rightH;
    return (height + 1);
}

int search(tree t, int n) {
    if(t == NULL) return 0;
    if(n == t->value) return 1;
    else if(n < t->value) search(t->left, n);
    else search(t->right, n);
    return 0;
}



tree insert(tree t, int n) {
    //Normal BST insert
    if (t == NULL) {
        return newNode(n);
    }
    if (n == t->value) {
        return t;
    } else if (n < t->value) {
        t->left = insert(t->left, n);
    } else {
        t->right = insert(t->right, n);
    }
    printf("Checking %d\n", n);
    //check and fix AVL property
    int leftD = 0;
    if (t->left != NULL) leftD = depth(t->left);
    int rightD = 0;
    if (t->right != NULL) rightD = depth(t->right);

    //if left heavy
    if (leftD - rightD > 1) {
    //check if in left child's right subtree
        if(n > t->left->value) t->left = rotateL(t->left);
        t = rotateR(t);
    }

    //if right heavy
    if (rightD - leftD > 1) {
    //check if in right child's left subtree
        if (n < t->right->value) t->right = rotateR(t->right);
        t = rotateL(t);
    }
    return t;
}
tree rotateL(tree t) {
    if(t == NULL) return t;
    if(t->right == NULL) return t;
    tree newRoot = t->right;
    t->right = newRoot->left;
    newRoot->left = t;
    return newRoot;
}

tree rotateR(tree t) {
    if(t == NULL) return t;
    if(t->left == NULL) return t;
    tree newRoot = t->left;
    t->left = newRoot->right;
    newRoot->left = t;
    return newRoot;
}


tree rebalanceNode(tree t) {
    if (t == NULL) return t;
    int leftD = depth(t->left);
    int rightD = depth(t->right);

    //left heavy
    if(leftD - rightD > 1) {
        //left child's right subtree
        if(depth(t->left->right) > depth(t->left->left))
            t->left = rotateL(t->left);
        t = rotateR(t);
    }

    //right heavy
    if(rightD - leftD > 1) {
        //right child's left subtree
        if(depth(t->right->left) > depth(t->right->right))
            t->right = rotateR(t->right);
        t = rotateL(t);
    }
    return t;
}

void printLevel(tree t) {
    Queue q = newQueue();
    if(t == NULL) return;

    QueueJoin(q, t);
    tree newLevel = t;
    while(QueueIsEmpty(q) != true) {
        tree tmp = QueueLeave(q);
        if(newLevel == tmp) {
            newLevel = NULL;
            printf("\n");
        }
        printf("Avl Tree:\n\n");
        printf("%d ", tmp->value); 
        if(tmp->left != NULL) {
            if(newLevel == NULL) { 
                newLevel = tmp->left;
            }
            QueueJoin(q, tmp->left);
        }
        if(tmp->right != NULL) {
            if(newLevel == NULL) {
                newLevel = tmp->right;
            }
            QueueJoin(q, tmp->right);
        }
    }
    dropQueue(q);
}

int main(void) {
    tree t = newTree();
    for(int i = 0; i < 10; i++) {
        //printf("Inserting %d\n", i);
        t = insert(t, i);
        //printf("Inserted %d\n", i);
    }

    printLevel(t);
    return 0;
}
