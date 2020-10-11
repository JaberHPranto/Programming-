#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b, int max)
{
    if (max % a == 0 && max % b == 0)
    {
        return max;
    }
    max = lcm(a, b, max + 1);
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
    int a, b;
    cin >> a >> b;
    int maxi = max(a, b);
    cout << lcm(a, b, maxi) << endl;
}
