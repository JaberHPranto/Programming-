#include <bits/stdc++.h> 
using namespace std;
#define ll long long

vector<ll> z_algo(string str){
    ll len = str.length();
    ll l = 0,r = 0,count=0;
    vector<ll> z(len);

    for (ll i = 1; i < len;i++){
        if(i>r){
            l = r = i;
            while(r<len and str[r]==str[r-l])
                r++;
            z[i] = r - l;
            r--;
        }
        else{
            
            ll idx = i - l;
            if(i+z[idx]<=r)
                z[i] = z[idx];
            else{

                l = i;
                while(r<len and str[r]==str[r-l])
                r++;
                z[i] = r - l;
                r--;
            }    
        }

    }

    return z;
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;


    string s,pat,tot;
    cin >> s>>pat;
    tot = pat + "$" + s;
    vector<ll> z_array;
    z_array = z_algo(tot);

    for (int i = 0; i < z_array.size();i++){
        if(z_array[i]==pat.length()){
            cout << i - pat.length() - 1 << endl;
        }
    }
}