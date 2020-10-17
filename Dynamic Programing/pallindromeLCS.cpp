#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001], vis[5001][5001];
string s1, s2;
int lcs(int i, int j)
{
    if (i >= s1.size() or j >= s2.size())
        return 0;
    if (vis[i][j])
        return dp[i][j];
    vis[i][j] = 1;

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(i + 1, j + 1);
    }
    else
    {
        return dp[i][j] = max(lcs(i, j + 1), lcs(i + 1, j));
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    cout << n - lcs(0, 0) << endl;

    return 0;
}