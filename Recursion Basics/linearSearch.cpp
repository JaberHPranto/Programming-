#include <bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int num, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (a[i] == num)
        return i;
    return linearSearch(a, n, num, i + 1);
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

    int n, q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        int res = linearSearch(a, n, num, 0);
        if (res == -1)
            cout << "Not Found" << endl;
        else
            cout << res << endl;
    }
}
