#include<bits/stdc++.h>
#define MAX 100

using namespace std;

char integer_to_char(int x)
{
    char y;
    y = x + 65;
    return y;
}

struct structure_edge
{
    int startingEdge;
    int endingEdge;
    int weight;
};

bool operator < (structure_edge lhs, structure_edge rhs)
{
    return lhs.weight < rhs.weight;
}

int parent[MAX];
int rankParent[MAX];


vector<structure_edge> edge_vector;

void makeSet(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        parent[i] = i;
        rankParent[i] = 0;
    }
}


int findParent(int x)
{
    if(x != parent[x])
        return parent[x] = findParent(parent[x]);
    else
        return x;
}


void unionSet(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);
    if(px == py)
        return;

    if(rankParent[px] < rankParent[py])
        parent[px] = py;
    else if(rankParent[px] > rankParent[py])
        parent[py] = px;
    else
    {
        parent[py] = px;
        rankParent[px]++;
    }
}

int kruskal(int n)
{
    makeSet(n);

    sort(edge_vector.begin(), edge_vector.end());

    int cost = 0;
    for(int i = 0 ; i < edge_vector.size(); i++)
    {
        if(findParent(edge_vector[i].startingEdge) != findParent(edge_vector[i].endingEdge))
        {
            unionSet(parent[edge_vector[i].startingEdge] , parent[edge_vector[i].endingEdge]);
            cout << integer_to_char(edge_vector[i].startingEdge) << " " << integer_to_char(edge_vector[i].endingEdge) << endl;
            cost += edge_vector[i].weight;
        }
    }

    return cost;
}


int main()
{
    freopen("kruskal.txt", "r", stdin);
    int vertex, edge;
    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        structure_edge e;
        cin >> e.startingEdge >> e.endingEdge >> e.weight;
        edge_vector.push_back(e);
    }
    cout << "Edges of Minimum Spanning Tree : " << endl;

    cout << "Total cost of Minimum Spanning Tree :" << kruskal(vertex) << endl;
}

