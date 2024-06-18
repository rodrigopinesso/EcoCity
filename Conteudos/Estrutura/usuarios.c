//código para adição e manipulação de usuários na rede social

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int adj[MAX_NODES][MAX_NODES];
    int numNodes;
    char *usernames[MAX_NODES]; // Array para armazenar nomes de usuários
} Graph;

void initGraph(Graph* g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->adj[i][j] = 0;
        }
        g->usernames[i] = NULL; // Inicializar ponteiros de nomes de usuários como NULL
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void addUser(Graph* g, int index, const char *username) {
    g->usernames[index] = (char *)malloc(strlen(username) + 1);
    strcpy(g->usernames[index], username);
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numNodes; i++) {
        printf("%s: ", g->usernames[i]);
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adj[i][j]) {
                printf("%s ", g->usernames[j]);
            }
        }
        printf("\n");
    }
}

void calculateDegreeCentrality(Graph* g, int* degree) {
    for (int i = 0; i < g->numNodes; i++) {
        degree[i] = 0;
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adj[i][j]) {
                degree[i]++;
            }
        }
    }
}

void exportGraphToDot(Graph* g, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(file, "graph G {\n");
    for (int i = 0; i < g->numNodes; i++) {
        for (int j = i + 1; j < g->numNodes; j++) {
            if (g->adj[i][j]) {
                fprintf(file, "    \"%s\" -- \"%s\";\n", g->usernames[i], g->usernames[j]);
            }
        }
    }
    fprintf(file, "}\n");
    fclose(file);
}

int main() {
    Graph g;
    initGraph(&g, 4);

    // Adicionar usuários
    addUser(&g, 0, "Alice");
    addUser(&g, 1, "Bob");
    addUser(&g, 2, "Charlie");
    addUser(&g, 3, "David");

    // Adicionar arestas (conexões)
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 0, 2);
    addEdge(&g, 2, 3);

    printGraph(&g);

    int degree[MAX_NODES];
    calculateDegreeCentrality(&g, degree);

    printf("Degree Centrality:\n");
    for (int i = 0; i < g.numNodes; i++) {
        printf("Node %s: %d\n", g->usernames[i], degree[i]);
    }

    exportGraphToDot(&g, "graph.dot");

    // Execute Graphviz to generate the image
    system("dot -Tpng graph.dot -o graph.png");

    // Free allocated memory for usernames
    for (int i = 0; i < g.numNodes; i++) {
        if (g->usernames[i] != NULL) {
            free(g->usernames[i]);
        }
    }

    return 0;
}
