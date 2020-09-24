#include<bits/stdc++.h>

using namespace std;

char integer_to_char(int x)
{
    char y;
    y=x+65;
    return y;
}

int char_to_int(char x)
{
    int y;
    y=x-65;
    return y;
}

typedef pair<int, int> intPair;

class Graph
{
    int V;

    list< pair<int, int> > *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<intPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{
    priority_queue< intPair, vector <intPair> , greater<intPair> > pq;

    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        cout << integer_to_char(i) << "              " << dist[i] << endl;
}

int main()
{
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 3);
    g.addEdge(0, 3, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 4, 10);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 12);
    g.addEdge(5, 2, 2);
    g.addEdge(5, 4, 5);


    char source;
    cout << "Enter the source :" << endl;
    cin >> source;

    int s = char_to_int(source);

    g.shortestPath(s);

    return 0;
}
