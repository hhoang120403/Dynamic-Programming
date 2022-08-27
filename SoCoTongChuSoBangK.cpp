#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

// d[i][j]: so cac so co i chu so va co tong cac chu so bang j
// So co i chu so se duoc tao thanh bang cach ghep them 1 so vao so (i-1) chu so
// d[i][j] = d[i][j] + d[i-1][j-x]
// x: la so can ghep chay tu 0->9
// i-1: co tong la j-x
// So x: la cai so minh can chen vao o so (i-1) chu so
// Sau khi chen: se dc 1 so (i-1+1)= i chu so va tong la: (j - x + x) = j
//d[0][j]=0, d[i][0]=0,d[1][j] = 1

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    int d[n+5][k+5]={};
    for(int i=0;i<=n;i++){
    	d[i][0] = 0; 
	}
	for(int j=0;j<=k;j++){
		d[0][j] = 0;
	}
	for(int j=1;j<=9;j++){
		d[1][j] = 1;
	}
    for(int i=2;i<=n;i++){
    	for(int so=0;so<=9;so++){
    		for(int j=so;j<=k;j++){
    			d[i][j] = (d[i][j]%mod + d[i-1][j-so]%mod)%mod;
			}
		}
	}
	cout << d[n][k];
}