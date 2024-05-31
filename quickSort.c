#include <stdio.h>
#include <stdlib.h>


int divide(int *v, int i, int j){
    int pivot = v[j];
    while(i < j){
        while(i < j && v[i] <= pivot){
            i++;
        }
        while(i < j && v[j] > pivot){
            j--;
        }
        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    return i;
}

void quickSort(int *v, int i, int j){
    if(i < j){
        int position = divide(v, i , j);
        quickSort(v, i, position - 1);
        quickSort(v, position, j);
    }
}

void print_vector(int *v, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


int main(){

    int v[] = {40, 20, 35, 12, 14, 13, 90, 22, 56};
    print_vector(v, 9);
    quickSort(v, 0, 10);
    print_vector(v, 9);

}