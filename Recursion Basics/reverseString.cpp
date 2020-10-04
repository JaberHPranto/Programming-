#include <bits/stdc++.h>
using namespace std;

string revString(string s, int i, int j)
{
    if (i > j)
        return s;
    swap(s[i], s[j]);
    return revString(s, ++i, --j);
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

    string s;
    getline(cin, s);
    cout << revString(s, 0, s.length() - 1) << endl;
}
