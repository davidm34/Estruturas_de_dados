#include <stdlib.h>
#include <stdio.h>

int posicao(int v[], int left, int right){
    int pivot = v[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(v[j] <= pivot){
            i += 1;
            int aux = v[j];
            v[j] = v[i];
            v[i] = aux;
        }
    }

    v[right] = v[i + 1];
    v[i + 1] = pivot;
    return i+1;

}

void quickSort(int v[], int left, int right){
    if (left < right){
        int pos = posicao(v, left, right);
        quickSort(v, left, pos-1);
        quickSort(v, pos+1, right);
    }

}

int main(){

    int max = 13;
    int v[max] = {4, 8, 7, 1, 6, 4, 3, 5, 2, 9, 1, 2, 7};
    printf("\n");
    for(int i = 0; i < max; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    
    quickSort(v, 0, 12);

    printf("\n");
    for(int c = 0; c < max; c++){
        printf("%d ", v[c]);
    }

    return 0;
}

