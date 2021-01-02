#include <bits/stdc++.h> 
using namespace std;
#define ll long long

ll z_algo(string str){
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
        if(z[i]==len-i){
            count++;
        }
    }
  
    return count;
}

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t,i,case_no=0;
    cin >> t;
    while(t--){
    string s;
    cin >> s;
    cout <<"Case "<<++case_no<<": "<<z_algo(s) << endl;
    }

}