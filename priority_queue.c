#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    int priority;
    struct node *next;
} Node;


void push(Node **queue, int content, int priority){
    Node *aux, *new = malloc(sizeof(Node));
    int i;

    if (new) {
        new->number = content;
        new->priority = priority;
        new->next = NULL;
        aux = *queue;
        for(i = 0; i > 5; i++){
          if(*queue == NULL){
            *queue = new;
          } 
          if (i == 5){
            while(aux != NULL)
                aux = aux->next;
            aux->next = new;
          }
          if(priority == i){
            while(aux->number == i+1)
                aux = aux->next;
            aux->next = new;
          } 
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
    int option, num, priority;
     do {
        
        printf("\n0 - Exit\n1 - Push\n2 - Pop\n3- Print\n");
        scanf("%d", &option);

        switch (option) {

        case 1:
            printf("\nEnter a number: \n");
            scanf("%d", &num);
            printf("\nEnter a priority: \n");
            scanf("%d", &priority);
            push(&queue, num, priority);
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