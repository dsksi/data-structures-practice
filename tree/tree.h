// Header file for tree functionality


typedef struct _node node;
typedef struct _node* tree;

enum {
    false,
    true,
}

//new tree
tree newTree(void);
//free tree
void freeTree(tree t);
//show tree
void showTree(tree t);
//insert
tree insertTree(tree t, int value);
//delete
tree deleteTree(tree t, int value);
//search
int search(tree t);
//pre-order traversal
void preOrder(tree t);
//post-order traversal
void postOrder(tree t);
//in-order traversal
void inOrder(tree t);

//tree height
int treeHeight(tree t);
//number of nodes in tree
int treeCountNodes(tree t);
//difference in number of nodes between left and right branch

//internal function
tree rotateRight(tree t);
tree rotateLeft(tree t);
tree insertAtRoot(tree t, int value);
tree rebalance(tree t);
tree partition(tree t, int value);
