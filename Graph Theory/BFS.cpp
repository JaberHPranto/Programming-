#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100000];
int parent[100000];
int level[100000];
bool visited[100000];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    parent[src] = -1;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << endl;
        q.pop();
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}
void printPath(int u)
{
    if (parent[u] != -1)
        printPath(parent[u]);
    cout << u << " ";
}
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int node, edge;
    int i, j;
    cin >> node >> edge;
    int n1, n2;
    for (i = 0; i < edge; i++)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    printPath(7);
}