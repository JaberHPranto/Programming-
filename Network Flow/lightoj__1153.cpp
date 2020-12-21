#include<bits/stdc++.h>

using namespace std;
const int maxnodes = 100;
int n,pr[110],cap[110][110];


int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    pr[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
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

            cap[u][v] -= path;
            cap[v][u] += path;

        }

        f+=path;
    
    }
    return f;
}

void clear(){
    for (int i = 0; i <= 110;i++){
        pr[i] = 0;
        for (int j = 0; j <= 110;j++){
            cap[i][j] = 0;
        }
    }
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

    int edge, s, t;
    cin >> n;
    cin >>s >> t >> edge;

    for (int i = 0; i < edge; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cap[a][b] += c;
        cap[b][a] += c;
    }
    cout <<"Case "<<++case_no<<": "<< maxFlow(s,t) << "\n";

    clear();
    }

}
