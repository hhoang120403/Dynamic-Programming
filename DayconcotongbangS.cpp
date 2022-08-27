#include<bits/stdc++.h>
using namespace std;

// Link de bai: https://www.youtube.com/watch?v=2oOnwrknr1s&list=PL8JRkLx_73-KDAroNHStrVXObcMpL2L3f&index=4

int main(){
    int n,s;
    cin >> n >> s;
    int a;
    int d[s+1]={};
    d[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> a;
        for(int j=a;j<=s;j++){
            if(d[j-a]==1) d[j] = 1;
        }
    }
    if(d[s]==1) cout << "Co day con co tong bang " << s;
    else cout << "Khong co day con co tong bang " << s;
}