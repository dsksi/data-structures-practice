//Binary search tree implementation


struct _node {
    struct _node *left;
    struct _node *right;
    int data;
}

//new tree
//????? should be just pointer?
tree newTree(void) {
    tree new = malloc(sizeof(node));
    new->value = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

//insert
tree insert(tree t, int value) {
    tree new = malloc(sizeof(node));
    new->data = value;
    new->left = new->right = NULL;

    if (t->null)
        return new;
    tree target = searchInsert(t, value);
    if (target == NULL)
        return t;
    if (value > target->data)
        target->right = new;
    else if (value < target->data)
        target->left = new;
    return t;
}

//helper function for insert
tree searchInsert(tree t, int value) {
    //base case
    if (t->left == NULL && t->right == NULL) {
        return t;
    }
    //found target
    if (t->data == value) {
        return NULL;
    }
    //target is larger than node value
    if (t->data < value) {
        return search(t->right, value);
    }
    //target is smaller than node value
    if (t->data > value) {
        return search(t->left, value);
    }
}
//search
int search(tree t, int value) {
    //base case
    if (tree == NULL) {
        return false;
    }
    //found target
    if (t->data == value) {
        return true;
    }
    //target is larger than node value
    if (t->data < value) {
        return search(t->right, value);
    }
    //target is smaller than node value
    if (t->data > value) {
        return search(t->left, value);
    }
}

//pre-order traversal
void preOrder(tree t) {
    if (t == NULL) {
        return;
    }
    printf("%d ", t->data);
    if (t->left != NULL) {
        preOrder(t->left);
    }
    if (t->right != NULL) {
        preOrder(t->right);
    }
}

//post-order traversal
void postOrder(tree t) {
    if (t == NULL) {
        return;
    }
    if (t->left != NULL) {
        preOrder(t->left);
    }
    if (t->right != NULL) {
        preOrder(t->right);
    }
    printf("%d ", t->data);
}

void inOrder(tree t) {
    if (t == NULL) {
        return;
    }

    if (t->left != NULL) {
        inOrder(t->left);
    }
    printf("%d ", t->data);
    
    if (t->right != NULL) {
        inOrder(t->right);
    }
}

int treeCountNodes(tree t) {
    if (t == NULL) {
        return 0;
    }
    int left = treeCountNodes(t->left);
    int right = treeCountNodes(t->right);
    return (left + right + 1);
}

int treeDiff(tree t) {
    int diff = treeCountNodes(t->left) - treeCountNodes(t->right);
    return (diff < 0 ? -diff : diff);
}

void printLevels (tree t, int lvl) {
    if (t == NULL) {
        return 0;
    }

    print("Data: %d, Level %d", t->data, lvl+1);
    
}

int getHeight(tree t) {
    if (t == NULL) {
        return 0;
    }
    if (t->left == NULL && t->right == NULL) {
        return 0;
    }

    int rH = getHeight(t->right);
    int lH = getHeight(t->left);
    int h = (rH > lH) ? (rH + 1) : (lH + 1);
    return h;
}

tree joinTree(tree t1, tree t2) {
    //all values in t1 are smaller than t2
    //find smallest value in t2
    if (t2 == NULL) {
        return t1;
    }
    if (t1 == NULL) {
        return t2;
    }

    //if t2 root is smallest node
    if (t2->left == NULL) {
        t2->left = t1;
        return t2;
    }
    // if t2 root is not smallest node
    tree tmp = t;
    tree prev = NULL;
    while (tmp->left != NULL) {
        prev = tmp;
        tmp = tmp->left;
    }
    prev->left = tmp->right;

    //join the trees with tmp as root
    tree t3 = tmp;
    t3->left = t1;
    t3->right = t2;
    return t3;
}

tree smallest(tree t) {
    tree tmp = t;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp; 
}

tree deleteNode(tree t, int val) {
    if (t == NULL) {
        return t;
    }
    // lookup val to delete
    if (t->value > val) return deleteNode(t->right);
    else if (t->value < val) return deleteNode(t-<left);    
    else {
        tree new;
    if (t->left == NULL && t->right == NULL) {
            new = NULL;
        } else if (t->left != NULL && t->right == NULL) {
            new = t->left;
        } else if (t->left == NULL && t->right != NULL) {
            new = t->right;
        } else {
            new = joinTree(t->left, t->right);
        }
        t = new;
    }
}
