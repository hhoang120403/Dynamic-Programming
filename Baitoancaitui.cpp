#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int w[n+1],v[n+1];
    int d[n+1][n+1]={};
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            d[i][j]= d[i-1][j];
            if(w[i]<=j) d[i][j] = max(d[i][j],d[i-1][j-w[i]]+v[i]);
        }
    }
    cout << d[n][m];
}