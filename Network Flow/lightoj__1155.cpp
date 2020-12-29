#include<bits/stdc++.h>

using namespace std;
const int maxnodes = 100;
int n,pr[210],cap[210][210];


int bfs(int src,int des)
{
    int vis[210]= {0};
    vis[src]=1;
    pr[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<=2*(n+4); i++)
        {
            
            // cout <<i<<" "<<u<<" "<< vis[i] << " " << cap[u][i] << endl;
            if(vis[i] or cap[u][i]<=0) continue;
            Q.push(i);
            vis[i]=1;
            pr[i]=u;

        }
    }

    return vis[des];
}
int maxFlow(int src,int des)
{
  
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=pr[i]) path=min(path,cap[pr[i]][i]);

        for(int i=des; i!=src; i=pr[i])
        {

            int u=pr[i];
            int v=i;

            // cout << "# " << u << " " << v <<"--"<<cap[u][v]<< endl;
            cap[u][v] -= path;
            cap[v][u] += path;
        }

        f+=path;
    
    }
    return f;
}

void clear(){
    memset(pr, 0, sizeof(pr));
    memset(cap, 0, sizeof(cap));
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,case_no=0;
    cin >> t;
    while(t--){

    int edge, s, t,node_cap,i,val;
    cin >> n;
    int source = 0;
    int sink = 2 * (n + 4);
    for (i = 1; i <= n;i++){
        cin >> val;
        int u = 2 * i - 1;
        int v = u + 1;
        
        cap[u][v] += val;
        cap[v][u] += val;

    }
        cin >>edge;

    for (i = 0; i < edge; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int u = 2 * a;
        int v = 2 * b - 1;

        cap[u][v] += c;
        // cap[v][u] += c;
        // cout <<u<<"-"<<v<<" "<< cap[u][v] << endl;
    }

    int b, d,node;
    cin >> b >> d;

    for (i = 1; i <= b;i++){
        cin >> node;
        int u = 2 * node - 1;

        cap[source][u] = INT16_MAX;
        // cap[u][source] += INT16_MAX;
    }
    for (i = 1; i <= d;i++){
        cin >> node;
        int u = 2 * node;

        cap[u][sink] = INT16_MAX;
        // cap[sink][u] += INT16_MAX;
    }


    cout << "Case " << ++case_no << ": " << maxFlow(source, sink) << "\n";

    clear();
    }

}
