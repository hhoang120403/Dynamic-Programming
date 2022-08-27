#include<bits/stdc++.h>
using namespace std;

// Link de bai: https://www.youtube.com/watch?v=F4WA2CL0RQw&list=PL8JRkLx_73-KDAroNHStrVXObcMpL2L3f&index=6

int main(){
    int n,k;
    cin >> n >> k;
    int a, d[n+5][k];
	// d[i][j] la do dai day con lon nhat co tong la j+k, va chon tu a1-> a[i]
    d[0][0] = 0;
    for(int i=1;i<k;i++) d[0][i] = -1005;
    for(int i=1;i<=n;i++){
    	cin >> a;
    	a %= k;
    	for(int j=0;j<k;j++){
    		d[i][j] = max(d[i-1][j],d[i-1][(j+k-a)%k]+1);
			cout << i << " " << j << " " << d[i][j] << endl;
		}
	}
	cout << d[n][0];
}