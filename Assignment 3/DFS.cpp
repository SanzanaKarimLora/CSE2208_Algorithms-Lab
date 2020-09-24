#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define SIZE 100

int adj[SIZE][SIZE];
int color[SIZE];
int parent[SIZE];
int dist[SIZE];
int finish[SIZE];
int tim = 0;

char integer_to_char(int x)
{
    char y;
    y=x+65;
    return y;
}

void DFS_VISIT(int u, int vertex)
{
    tim = tim + 1;
    dist[u] = tim;
    color[u] = GRAY;

    for(int i = 0; i < vertex; i++)
    {
        if(adj[u][i] == 1)
        {
            int v = i;

            if(color[v] == WHITE)
            {
                parent[v] = u;
                DFS_VISIT(v, vertex);
            }
        }
    }
    color[u] == BLACK;
    tim = tim + 1;
    finish[u] = tim++;

    cout << integer_to_char(u) << " ";
}

void DFS(int vertex)
{
    for(int i = 0; i < vertex; i++)
    {
        color[i] = WHITE;
        parent[i] = INT_MIN;
    }
    tim = 0;

    cout << "DFS is : ";
    for(int i = 0; i < vertex; i++)
    {
        if(color[i] == WHITE)
        {
            DFS_VISIT(i, vertex);
        }
    }

}

int main()
{
    freopen("input.txt" , "r" , stdin);
    int vertex;
    int edge;
    cin >> vertex >> edge;
    cout << "Vertex is : " << vertex <<endl;
    cout << "Edge is : " << edge <<endl;

    int node1,node2;
    for(int i = 0 ; i< edge ; i++)
    {
        cin >> node1 >> node2;
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;

    }

    for(int i = 0 ; i < vertex ; i++)
    {
        for(int j = 0 ; j < vertex ; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    DFS(vertex);

    return 0;
}
