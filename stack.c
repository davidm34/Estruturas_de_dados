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


int main(){

    Node *top = NULL;
    int option;
    int num;


    do {
        
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:

            printf("Enter a number: \n");
            scanf("%d", &num);
            top = push(top, num);
            break;
        
        default:
            if (option != 0){
                printf("Invalid number!\n");
            }
        }


    } while (option != 0);



    return 0;
}