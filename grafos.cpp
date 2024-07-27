#include <ostream>
#include <vector>
using namespace std;


void printMatriz(int vector[][5]){
     for(int l = 0; l < 5; l++){
        printf("%d: ", l);
        for(int c = 0; c < 5; c ++){
            printf("%d  ", vector[l][c]);
        }
        printf("\n");
    }
}

void addEdge(int vector[][5], int i, int j){
    vector[i][j] = 1;
}


int main(){
    int myvector[5][5];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            myvector[i][j] = 0;
        }
    }

    addEdge(myvector, 0, 1);
    addEdge(myvector, 3, 5);
    addEdge(myvector, 2, 3);
    addEdge(myvector, 1, 4); 

    printMatriz(myvector);



}