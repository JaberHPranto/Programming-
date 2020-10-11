#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n, int limit, int i)
{
    if (i > limit)
        return true;
    if (n % i == 0)
        return false;
    return (n, limit, i + 1);
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
    while (cin >> n)
    {
        if (!isPrime(n, n / 2, 2))
        {
            cout << "Not Prime" << endl;
        }
        else
            cout << "Prime" << endl;
    }
}
