#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
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

    cout << fibo(n) << endl;
}
