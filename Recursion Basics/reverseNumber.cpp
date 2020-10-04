#include <bits/stdc++.h>
using namespace std;

int revNum(int n, int rev)
{
    int rem;
    if (n == 0)
    {
        return rev;
    }
    rem = n % 10;
    rev = rev * 10 + rem;
    return revNum(n / 10, rev);
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

    int n;
    cin >> n;

    cout << revNum(n, 0) << endl;
}
