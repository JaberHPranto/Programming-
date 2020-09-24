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

/* ----- start from here ------ */
ll lsb(ll idx)
{
    return (idx & (-idx));
}
void update(ll node_idx, ll val, ll n, ll *bit)
{
    while (node_idx <= n)
    {
        bit[node_idx] += val;
        // update all it's parent -> 2+lsb(2)=4
        node_idx = node_idx + lsb(node_idx);
    }
}
ll *create_bit(ll *a, ll n)
{
    ll *bit = new ll[n + 1];
    for (ll i = 1; i <= n; i++)
        bit[i] = 0;
    for (ll i = 1; i <= n; i++)
        update(i, a[i], n, bit);
    return bit;
}
ll get_sum(ll idx, ll *bit)
{
    ll sum = 0;
    while (idx >= 1)
    {
        sum += bit[idx];
        // go to all it's child --> 10-lsb(10)=10-2=8
        idx = idx - lsb(idx);
    }
    return sum;
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
    ll n, i;
    cin >> n;
    ll a[n + 1];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    ll *bit = create_bit(a, n);

    // get_sum(5,15)=> get_sum(15)-get_sum(5-1)
    ll lb, ub;
    cin >> lb >> ub;
    cout << get_sum(ub, bit) - get_sum(lb - 1, bit) << endl;
}