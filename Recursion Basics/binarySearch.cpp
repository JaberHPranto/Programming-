#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int num, int l, int r)
{
    if (l > r)
    {
        return -1;
    }

    int mid = (l + r) / 2;
    if (num < mid)
    {
        return binarySearch(a, num, l, mid - 1);
    }
    else if (num > mid)
    {
        return binarySearch(a, num, mid + 1, r);
    }
    return mid;
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
        int res = binarySearch(a, num, 0, n - 1);
        if (res == -1)
            cout << "Not Found" << endl;
        else
            cout << res << endl;
    }
}
