#include <iostream>
using namespace std;

// Estrutura para representar um nó em uma lista de adjacência
struct No {
    int vertice;
    No* prox;
};

// Função para adicionar uma aresta ao grafo
void adicionarAresta(No* adj[], int v, int w) {
    No* novoNo = new No;
    novoNo->vertice = w;
    novoNo->prox = adj[v];
    adj[v] = novoNo;
}

// Função para realizar a busca em largura a partir de um vértice s
void BFS(No* adj[], int V, int s) {
    // Marca todos os vértices como não visitados
    bool* visitado = new bool[V];
    for (int i = 0; i < V; i++)
        visitado[i] = false;

    // Cria uma fila para BFS
    int* fila = new int[V];
    int frente = 0, tras = 0;

    // Marca o nó atual como visitado e o coloca na fila
    visitado[s] = true;
    fila[tras++] = s;

    while (frente < tras) {
        // Retira um vértice da fila e o imprime
        s = fila[frente++];
        cout << s << " ";

        // Obtém todos os vértices adjacentes ao vértice s
        // Se um vértice adjacente não foi visitado, marca como visitado e o coloca na fila
        No* temp = adj[s];
        while (temp != nullptr) {
            int adjacente = temp->vertice;
            if (!visitado[adjacente]) {
                visitado[adjacente] = true;
                fila[tras++] = adjacente;
            }
            temp = temp->prox;
        }
    }

    delete[] visitado;
    delete[] fila;
}

int main() {
    int V = 4; // Número de vértices
    No* adj[V]; // Lista de adjacência

    // Inicializa a lista de adjacência
    for (int i = 0; i < V; i++)
        adj[i] = nullptr;

    // Adiciona arestas ao grafo
    adicionarAresta(adj, 0, 1);
    adicionarAresta(adj, 0, 2);
    adicionarAresta(adj, 1, 2);
    adicionarAresta(adj, 2, 0);
    adicionarAresta(adj, 2, 3);
    adicionarAresta(adj, 3, 3);

    cout << "Busca em Largura (BFS) começando do vértice 2:\n";
    BFS(adj, V, 2);

    // Libera a memória alocada para a lista de adjacência
    for (int i = 0; i < V; i++) {
        No* temp = adj[i];
        while (temp != nullptr) {
            No* prox = temp->prox;
            delete temp;
            temp = prox;
        }
    }

    return 0;
}
