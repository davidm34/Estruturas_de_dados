#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} Node;


void push(Node **queue, int content){
    Node *aux, *new = malloc(sizeof(Node));

    if (new) {
        new->number = content;
        new->next = NULL;
        if (*queue == NULL){
            *queue = new;
        }
        else {
            aux = *queue;
            while(aux != NULL){
                aux = aux->next;
            }
            aux->next = new;
        }
    }
    else {
        printf("\nError in allocating memory\n");
    }
}


Node* pop(Node **queue){
    Node *remove = malloc(sizeof(Node));

    if (*queue){
        remove = *queue;
        *queue = remove->next;
        
    }
    else {
        printf("\nError in allocating memory\n");
    }
    return remove;
}


void print_queue(Node *queue){
    while (queue != NULL){
        printf("\nNumber: %d\n", queue->number);
        queue = queue->next;
    }

}

int main(){

    Node *queue, *remove = NULL;
    int option;
    int num;
     do {
        
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n3- Print\n");
        scanf("%d", &option);

        switch (option) {

        case 1:
            printf("Enter a number: \n");
            scanf("%d", &num);
            push(&queue, num);
            break;
        
        case 2:
            remove = pop(&queue);
            if (remove){
                printf("\nElement remove: %d\n", remove->number);
            } else {
                printf("\nEmpty Stack!\n");
            }
            break;

        case 3:
            print_queue(queue);
            break;

        default:
            if (option != 0){
                printf("Invalid number!\n");
            }
        }


    } while (option != 0);



    return 0;
}