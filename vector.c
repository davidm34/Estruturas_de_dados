#include <stdio.h>
#include <stdlib.h>


int main(){

    // First Method 
    int vector1[8];

    // Second Method
    int vector2[] = {0, 1, 2, 3, 4, 5, 6, 7};

    // Third method that places 0 in empty positions
    int vector3[5] = {1, 2, 3};

    // Fourth method in which only takes valid positions
    int vector4[5] = {1, 2, 3, 4, 5, 6};

    // Fill the vector with 0
    int vector5[5] = {0};

    // Caracters

    // First Method
    char letters[100];

    // Second Method
    char vogal[5] = {'a', 'e', 'i', 'o', 'u'};


}


int addValuesVector(int vector[], int size){
    
    int i;

    for(i = 0; i < size; i++){

        printf("Enter a number: \n");

        scanf("%d\n", &vector[i]);

    }

    return vector;
}