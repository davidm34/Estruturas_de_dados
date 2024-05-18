#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int number;
    struct node *next;
} Node;

Node* push(Node *top, int content){

    Node *new = malloc(sizeof(Node));

    if (new){

        new->number = content;
        new->next = top;
        return new;

    }
    else {
        
        printf("Error in allocating memory\n"); 

    }

    return NULL;
}


Node* pop(Node **top){

    if (top) {

        Node *remove = *top;
        *top = remove->next;
        return remove;
    }
    else {
        printf("\nEmpty stack\n");
    }
    return NULL;
}



void print_stack(Node *top){

    while(top){
        printf("\nNumber: %d\n", top->number);
        top = top->next;
    }

}


int main(){

    Node *top, *remove = NULL;
    int option;
    int num;


    do {
        
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n3- Print\n");
        scanf("%d", &option);
        getchar();

        switch (option) {
        case 1:

            printf("Enter a number: \n");
            scanf("%d", &num);
            top = push(top, num);
            break;
        
        case 2:
            remove = pop(&top);
            if (top){
                printf("\nElement remove: %d\n", remove->number);
            } else {
                printf("\nEmpty Stack!\n");
            }
            break;
        case 3:
            print_stack(top);
            break;
        default:
            if (option != 0){
                printf("Invalid number!\n");
            }
        }


    } while (option != 0);



    return 0;
}