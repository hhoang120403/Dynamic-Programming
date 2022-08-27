#include<bits/stdc++.h>
using namespace std;

// Link de bai: https://www.youtube.com/watch?v=Cd-mu9jKjk0&list=PLux-_phi0Rz3xM_h4WoSo6xAAi9mdnETx&index=5

int main(){
    int t;
    cin >> t;
    int d[1001][1001];
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]) d[i][j] = d[i-1][j-1] + 1;
                else d[i][j] = max(d[i-1][j],d[i][j-1]);
            }
        }
        cout << d[n-1][m-1];
    }
}