#include <bits/stdc++.h>
using namespace std;

void findMax(int a[], int n, int current_max, int i)
{
    if (i == n - 1)
    {
        cout << current_max << endl;
        return;
    }
    current_max = max(current_max, a[i]);
    return findMax(a, n, current_max, i + 1);
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
    int init_max = INT16_MIN;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    findMax(a, n, init_max, 0);
    // cout << findMax(a, n, init_max, 0) << endl;
}
