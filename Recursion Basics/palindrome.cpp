#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    if (i > j)
    {
        return true;
    }

    if (s[i] != s[j])
        return false;
    return isPalindrome(s, ++i, --j);
}

string clearWhiteSpace(string s)
{
    string updated_s = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || ((s[i] >= '0' && s[i] <= '9')))
            updated_s += s[i];
    }
    return updated_s;
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
    s = clearWhiteSpace(s);
    if (isPalindrome(s, 0, s.length() - 1))
        cout << "Palinedrome" << endl;
    else
        cout << "Not Palinedrome" << endl;
}
