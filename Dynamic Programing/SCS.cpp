#include <bits/stdc++.h>
using namespace std;
int dp[101][101], vis[101][101];
string s1, s2, s;
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
void pathPrint(int i, int j)
{
    if (i >= s1.size() or j >= s2.size())
        return;

    if (s1[i] == s2[j])
    {
        s.push_back(s1[i]);
        pathPrint(i + 1, j + 1);
    }
    else
    {
        if (dp[i + 1][j] > dp[i][j + 1])
        {
            pathPrint(i + 1, j);
        }
        else
        {
            pathPrint(i, j + 1);
        }
    }
    return;
}
void print_shortName(int i, int j)
{
    for (int k = 0; k < s.size(); k++)
    {
        while (i < s1.size() && s1[i] != s[k])
        {
            cout << s1[i];
            i++;
        }
        while (j < s2.size() && s2[j] != s[k])
        {
            cout << s2[j];
            j++;
        }
        cout << s[k];
        i++;
        j++;
    }
    while (i < s1.size())
    {
        cout << s1[i];
        i++;
    }
    while (j < s2.size())
    {
        cout << s2[j];
        j++;
    }
    cout << endl;
}
void reset()
{
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    s.clear();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> s1 >> s2)
    {
        int sub = lcs(0, 0);
        pathPrint(0, 0);
        print_shortName(0, 0);
        reset();
    }
}