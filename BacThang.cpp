#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

// Link de bai: https://www.youtube.com/watch?v=OHbZCo_C_Eo&list=PL8JRkLx_73-KDAroNHStrVXObcMpL2L3f&index=11

int main(){
    int n,k;
    cin >> n >> k;
    long long d[n+5]={};
    // d[i]: la so cach buoc den bac thu i
    d[0]=d[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i,k);j++){
            d[i] += d[i-j];
            d[i] %= mod;
        }
    }
    cout << d[n] << endl;
}