#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
    int vertices, arestas;
    cin >> vertices >> arestas;

    vector<vector<pair<int, int>>> Grafo(vertices);
    for (int i = 0; i < arestas; i++) {
        // Conexões dos Vértices e Peso
        int v1, v2, peso;
        cin >> v1 >> v2 >> peso;
        v1--; v2--; // Caso o vértice começar em 1
        Grafo[v1].push_back({v2, peso}); // Vertice com ligação e peso
    }

    priority_queue<pair<int, int>, vector<pair<int, int>    >, greater<pair<int, int>>> fila_prioridade; // distância e vértice
    vector<int> distancia(vertices, INT_MAX);
    //int inicio;
    //cin >> inicio;

    distancia[0] = 0;
    fila_prioridade.push({0, 0});

    while (!fila_prioridade.empty()) {
        int v = fila_prioridade.top().second; // Vertice
        int w = fila_prioridade.top().first; // Distancia
        fila_prioridade.pop();

        if (w != distancia[v]) continue;

        for (auto edge : Grafo[v]) {
            int u = edge.first; // Ligação 
            int cost = edge.second; // Peso da Aresta
            if ((distancia[v] + cost) < distancia[u]) {
                distancia[u] = distancia[v] + cost;
                fila_prioridade.push({distancia[u], u});
            }
        }
    }

    for (int d : distancia) {
        cout << (d == INT_MAX ? -1 : d) << " ";
    }
    cout << endl;

    return 0;
}
