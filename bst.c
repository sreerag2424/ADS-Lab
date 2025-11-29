//Implement Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value);
struct Node* insert(struct Node* node, int value);
struct Node* deleteNode(struct Node* root, int key);
struct Node* search(struct Node* root, int key);
struct Node* findMinValueNode(struct Node* node);
void inorderTraversal(struct Node* root);
void preorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);

int main() {
    struct Node* root = NULL;
    int choice, value;

        printf("\n--- BINARY SEARCH TREE OPERATIONS ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search for an Element\n");
        printf("4. In-order Traversal (Sorted)\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("---------------------------------------\n");
        while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Element %d found in the tree.\n", value);
                } else {
                    printf("Element %d not found in the tree.\n", value);
                }
                break;
            case 4:
                printf("In-order Traversal: [ ");
                inorderTraversal(root);
                printf("]\n");
                break;
            case 5:
                printf("Pre-order Traversal: [ ");
                preorderTraversal(root);
                printf("]\n");
                break;
            case 6:
                printf("Post-order Traversal: [ ");
                postorderTraversal(root);
                printf("]\n");
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int value) {
    
    if (node == NULL) return createNode(value);

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            printf("Node with key %d deleted.\n", key);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            printf("Node with key %d deleted.\n", key);
            return temp;
        }

        struct Node* temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
       return root;
    }
    
    if (root->data < key) {
       return search(root->right, key);
    }
    
    return search(root->left, key);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
