#include <stdio.h>
#include <stdlib.h>

typedef struct nodetree{
    int num;
    struct nodetree *left;
    struct nodetree *right;
} NodeTree;

NodeTree* add(NodeTree *root, int num){
    if(root == NULL){
        NodeTree *aux = malloc(sizeof(NodeTree));
        aux->num = num;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if (num < root->num){
            root->left = add(root->left, num);
        } else{
            root->right = add(root->right, num);
        }
        return root;
    }

}

void print_tree(NodeTree *root){
    if (root){
        printf("%d\n", root->num);
        print_tree(root->left);
        print_tree(root->right);
        
    }

}



int main(){

    NodeTree *root = NULL;
    int option, value;

    do {
        printf("\n\t0- Exit \n\t1- Add \n\t2 - Print\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n\tAdd Value: ");
            scanf("%d", &value);
            root = add(root, value);
            break;
        case 2:
            print_tree(root);
            break;
        default:
            break;
        }


    } while(option != 0); 


}