#include <bits/stdc++.h>
using namespace std;
#define int long long
// creating lps array for pattern
vector<int> createLPS(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[index] == pattern[i])
        {
            lps[i] = index + 1;
            ++index;
            ++i;
        }
        else
        {
            if (index != 0)
                index = lps[i - 1];
            else
                lps[i] = index, ++i;
        }
    }
    return lps;
}
// KMP algo
void kmp(string text, string pattern)
{
    vector<int> lps = createLPS(pattern);
    bool found = false;
    int i = 0, j = 0;
    // i->text  j->pattern
    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            ++i, ++j;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
        // we found a pattern match
        if (j == pattern.length())
        {
            cout << "Found Match !!" << endl;
            found = true;
            // break;
            // for multiple pattern searching
            cout << "index at : " << (i - pattern.length()) << endl;
            j = lps[j - 1];
        }
    }
    if (!found)
        cout << "Not Found :( " << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    kmp(text, pattern);
    return 0;
}
