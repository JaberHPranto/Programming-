#include <bits/stdc++.h>
#define len(x) x.size()
using namespace std;

string s1, s2;
int dp[100][100], vis[100][100];

int lcs(int i, int j)
{
    if (i >= len(s1) or j >= len(s2))
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
void pathPrint(int i, int j)
{
    if (i >= len(s1) or j >= len(s2))
        return;
    if (s1[i] == s2[j])
    {
        cout << s1[i];
        pathPrint(i + 1, j + 1);
    }
    else
    {
        if (dp[i + 1][j] > dp[i][j + 1])
            pathPrint(i + 1, j);
        else
            pathPrint(i, j + 1);
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    s1 = "HelloWorld";
    s2 = "Hellno";
    cout << lcs(0, 0) << endl;
    pathPrint(0, 0);

    return 0;
}