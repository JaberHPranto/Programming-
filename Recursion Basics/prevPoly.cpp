#include <bits/stdc++.h> 
using namespace std;

int prevPoly(int n,int k,int i){

    if(i==k){
        return 0;
    }
    return pow(n,i)+prevPoly(n,k,i+1);

}
int32_t main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n,k;
    cin>>n>>k;

    cout<<prevPoly(n,k,0)<<endl;

}
