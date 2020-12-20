#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[101][101], a[101];
int n;

int lis(int prev, int i)
{
    if (i == n + 1)
        return 0;
    if (dp[prev][i] != -1)
        return dp[prev][i];
    int ans = 0;
    if (prev == 0 or a[prev] < a[i])
    {
        ans = max(1 + lis(i, i + 1), lis(prev, i + 1));
    }
    else
        ans = lis(prev, i + 1);
    return dp[prev][i] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    cout << lis(0, 1) << endl;
}
