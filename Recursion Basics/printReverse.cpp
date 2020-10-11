#include <bits/stdc++.h> 
using namespace std;

void printreverse(int a[],int n){
    if(n==0)return;
    n--;
    cout<<a[n]<<" ";
    printreverse(a,n);
}
int32_t main() {

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin) ;
    // freopen("output.txt", "w", stdout) ;
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    // for(i=0;i<n;i++){
    //     cout<<a[i]<<endl;
    // }
    printreverse(a,n);


}
