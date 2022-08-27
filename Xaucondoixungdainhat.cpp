#include<bits/stdc++.h>
using namespace std;

/*
F[i][j]: xau con bat dau tu i va ket thuc o j
Neu s[i] != s[j]: F[i][j] = False;
Neu s[i] == s[j] && F[i+1][j-1]==True : F[i][j] = True;
*/

// Cach QHD:

int main(){
    string s;
    cin >> s;
    int n = s.size();
    s = "x" + s;
    int ans=1;
	bool F[n+1][n+1];
	memset(F,false,sizeof(F));
	for(int i=1;i<=n;i++) F[i][i] = true;
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j = i+len-1;
			if(len==2 && s[i]==s[j]) F[i][j] = true;
			else{
				if(s[i]==s[j] && F[i+1][j-1]==true) F[i][j] = true;
			}
			if(F[i][j]) ans = max(ans,len);
		}
	}
	cout << ans;
}

// Cach khac
/*
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
   	string s;
   	cin >> s;
   	int res = 1;
   	s = '0' + s;
   	int j,k;
   	for(int i=1;i<=s.size();){
   		j = i, k = i;
   		while(k<s.size() && s[k]==s[k+1]){
   			k++;
		}
		i = k+1;
		while(k<s.size() && s[k+1]==s[j-1]){
			j--;
			k++;
		}
		res = max(res,k-j+1);
	}
	cout << res;
}
*/