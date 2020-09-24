#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define F(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

unordered_map<int, int> parent, sz;
// making each value it's representative
void make_set(int num)
{
    parent[num] = num;
    sz[num] = 1;
}
// find parent of a node
int find_set(int num)
{
    if (parent[num] == num)
        return num;
    return parent[num] = find_set(parent[num]);
}
// union two number
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    //path compression using size
    if (sz[a] < sz[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        make_set(i);
    }
    cin >> t;
    while (t--)
    {

        int a, b;
        cin >> a >> b;
        union_set(a, b);
        cout << find_set(a) << " " << find_set(b) << endl;
    }

    return 0;
}