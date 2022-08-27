#include<bits/stdc++.h>
using namespace std;

// Link de bai: https://www.youtube.com/watch?v=2oOnwrknr1s&list=PL8JRkLx_73-KDAroNHStrVXObcMpL2L3f&index=4

int main(){
    int n;
    cin >> n;
    int a[n+1];
    int l[n+1]={},res=0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        l[i] = 1;
        for(int j=1;j<i;j++){
            if(a[i]>=a[j] && l[i]<l[j]+1){
                l[i] = l[j]+1;
            }
        }
        res = max(res,l[i]);
    }
    cout << res;
}