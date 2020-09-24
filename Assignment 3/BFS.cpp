#include <bits/stdc++.h>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define SIZE 100

int adj[SIZE][SIZE];
int color[SIZE];
int parent[SIZE];
int dis[SIZE];
int vertex, edge;

char integer_to_char(int x)
{
    char y;
    y=x+65;
    return y;
}

void BFS(int adj[][SIZE] , int vertex , int source)
{
    for(int i = 0; i < vertex; i++)
    {
        if(i != source)
        {
            color[i] = WHITE;
            dis[i] = INT_MIN;
            parent[i] = -1;
        }
    }

    color[source] = GRAY;
    dis[source] = 0;
    parent[source] = -1;

    queue <int> queue_bfs;
    queue_bfs.push(source);

    cout << "BFS is : ";
    while(!queue_bfs.empty())
    {
        int u = queue_bfs.front();
        cout << integer_to_char(u) << " ";

        queue_bfs.pop();

        for(int i = 0; i < vertex; i++)
        {
            if(adj[u][i] != 0)
            {
                int v = i;

                if(color[v] == WHITE)
                {
                    color[v] = GRAY;
                    dis[v] = dis[u] + 1;
                    parent[v] = u;

                    queue_bfs.push(v);
                }
            }
        }

        color[u] = BLACK;
    }
}

void PRINT_PATH(int source, int endVertex)
{
    if(source == endVertex || endVertex == -1)
        cout << integer_to_char(source) << " ";
    else
    {
        PRINT_PATH(source, parent[endVertex]);
        cout << integer_to_char(endVertex) << " ";
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

	    BFS(adj , vertex , 0);
	    cout << endl;
	    PRINT_PATH(0 , 4);
    return 0;
}

