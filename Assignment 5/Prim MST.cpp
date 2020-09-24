#include<bits/stdc++.h>
#define MAX 100

using namespace std;


typedef pair<int, int> pair_prim;
vector <pair_prim> v[MAX];

struct node_structure
{
    int u;
    int cost;
};

bool operator<(node_structure a, node_structure b)
{
    return a.cost > b.cost;
}

priority_queue<node_structure> pq;

int cost[MAX];
bool visited[MAX];
int vertex, edge;

int prim(int source)
{
    for(int i = 0 ; i < vertex ; i++ )
    {
        cost[i] = INT_MAX;
        visited[i] = false;
    }

    cost[source] = 0;
    node_structure node;
    node.u = source;
    node.cost = 0;
    pq.push(node);
    int total_cost = 0;

    while(!pq.empty())
    {

        node_structure current = pq.top();
        pq.pop();
        cout << current.u << " " << current.cost << endl;

        if(visited[current.u])
        {
            continue;
        }

        visited[current.u] = true;

        total_cost += current.cost;

        for(int i = 0 ; i < v[current.u].size() ; i++)
        {
            if(visited[v[current.u][i].first])
            {
                continue;
            }

            if(v[current.u][i].second < cost[v[current.u][i].first])
            {

                node_structure temp2;
                temp2.u = v[current.u][i].first;
                temp2.cost = v[current.u][i].second;
                pq.push(temp2);
                cost[v[current.u][i].first] = v[current.u][i].second;
            }
        }
    }

    return total_cost;
}

int main()
{
    freopen("Prim.txt", "r", stdin);

    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        int source;
        pair_prim p;
        cin >> source >> p.first >> p.second;
        v[source].push_back(p);
        int source2 = p.first;
        p.first = source;
        v[source2].push_back(p);
    }

    cout << "MST IS " << prim(0) << endl;

}
