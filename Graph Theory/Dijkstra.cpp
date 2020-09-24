#include<bits/stdc++.h>
#define pii pair<int,int> 
#define N 100000
#define INF 0x3f3f3f3f 
using namespace std;

// stores {w,v}-->{weight,vertex}
vector<pii>graph[N];
int dist[N];
int parent[N];

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    memset(dist, INF, sizeof(dist));
    pq.push({ 0, src });
    dist[src]=0;
    parent[src]=-1;
    int u, v, uw, vw, cost;
    while (!pq.empty()) {
        uw=pq.top().first;
        u=pq.top().second;
        pq.pop();

        //optimization
        if (uw!=dist[u])
            continue;

        for (pii vv:graph[u]) {
            vw=vv.first;
            v=vv.second;
            cost=dist[u]+vw;
            if (dist[v]>cost) {
                dist[v]=cost;
                parent[v]=u;
                pq.push({ cost, v });
            }
        }
    }
}
int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n, m, u, v, w;
        cin>>n>>m;
        for (int i=0;i<m;i++) {
            cin>>u>>v>>w;
            graph[u].push_back({ w, v });
            // graph[v].push_back({ w, u });
        }
        int src, dest;
        cin>>src>>dest;
        dijkstra(src);
        if (dist[dest]==INF)
            cout<<"NO"<<endl;
        else cout<<dist[dest]<<endl;
        for (int i=1;i<=n;i++) {
            graph[i].clear();
        }
    }


}
