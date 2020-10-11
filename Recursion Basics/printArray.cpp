#include <bits/stdc++.h>
using namespace std;

void printArray(int a[], int i, int j)
{
    if (i > j)
        return;
    cout << a[i] << " " << a[j] << endl;
    printArray(a, i + 1, j - 1);
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

    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    printArray(a, 0, n - 1);
}
