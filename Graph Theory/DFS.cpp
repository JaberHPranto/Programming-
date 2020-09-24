#include <bits/stdc++.h>
using namespace std;
int node, edge;
vector<int> graph[100000];
bool visited[100000];
int parent[100000];
void dfs(int src)
{
    visited[src] = true;
    cout << src << endl;
    for (auto child : graph[src])
    {
        if (!visited[child])
        {
            parent[child] = src;
            dfs(child);
        }
    }
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
    int i, j;
    cin >> node >> edge;
    int n1, n2;
    for (i = 1; i <= edge; i++)
    {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for (i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            parent[i] = -1;
            dfs(i);
        }
    }
}