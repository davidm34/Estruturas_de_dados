#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j;

    // First Method 
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Obrigate two lines 
    int matrix2[][3] = {{1, 2, 3}, {4, 5, 6}};

    for(i = 0; i < 3; i++){
        
        for(j = 0; j < 3; j++){

            printf("%d", matrix1[i][j]);

        }

    }

    printf("\n");

    for(i = 0; i < 2; i++){
        
        for(j = 0; j < 3; j++){

            printf("%d", matrix2[i][j]);

        }

    }


    return 0;
}


void addValuesMatrix(){
    
    int matrix[3][3];
    int i;
    int j;

    for(i = 0; i < 3; i++){

        for(j = 0; j < 3; j++){

            printf("Enter a number: \n");

            scanf("%d\n", &matrix[i][j]);   

        }
            
    }

}