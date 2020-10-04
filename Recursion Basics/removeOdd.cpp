#include <bits/stdc++.h> 
using namespace std;

void removeOdd(int *a,int *size,int i,int j){
    if(i==*size){
        *size=j;
        return;
    }
    if(a[i]%2==0) {
        a[j++]=a[i];
    }
    removeOdd(a,size,i+1,j);

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
    removeOdd(a,&n,0,0);
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


}
