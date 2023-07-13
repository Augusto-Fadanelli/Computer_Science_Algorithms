#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int vertices;
int edges;

void create_graph(int is_directed)
{
    int i, edge, origin, destin;

    printf("Entre com o número de nós: ");
    scanf("%d", &vertices);

    printf("Digite o número de arestas: ");
    scanf("%d", &edges);

    // max_edges = is_directed ? vertices * (vertices - 1) : vertices * (vertices - 1) / 2;

    for (edge = 0; edge < edges; edge++){
        printf("Entre com a aresta %d (exemplo: 1 2): ", edge + 1);
        scanf("%d %d", &origin, &destin);

        if (origin > vertices || destin > vertices || origin < 0 || destin < 0){
            printf("Aresta inválida!\n");
            i--;
            continue;
        }
        
        adj[origin][destin] += 1;
        if (!is_directed && origin!=destin)
        {
            adj[destin][origin] += 1;
        }
    }

    printf("\n Ordem: %d", vertices);
}

void display()
{
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

int main()
{
    int is_directed;
    printf("O grafo é orientado? Digite 1 para Sim e 0 para Não: ");
    scanf("%d", &is_directed);

    create_graph(is_directed);
    printf("Matriz de Adjacência: \n");
    display();
    return 0;
}