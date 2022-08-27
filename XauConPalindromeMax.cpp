#include<bits/stdc++.h>
using namespace std;

/*
Bài toán: Cho một xâu S, độ dài không quá 1000 kí tự. 
Tìm palindrome dài nhất là xâu con của S (Xâu con là một dãy các kí tự liên tiếp).
Đây cũng là một bài cơ bản với nhiều cách làm.
*/

void solve1(string s){
    // Su dung QHD: Độ phức tạp thuật toán là O(N2).
    //F[i, j] = T/F nếu đoạn gồm các kí tự từ i đến j của S có/không là palindrome.
    //F[i][j] = F[i+1][j-1] if S[i] = S[j]
    //F[i][j] = False if S[i] != S[j]
    int n = s.length();
    bool F[n+1][n+1];
    int res = 1;
    memset(F,false,sizeof(F));
    for(int i=1;i<=n;i++){
        F[i][i] = true;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j = i+len-1;
            if(len==2 && s[i]==s[j]) F[i][j] = true;
            else{
                if(s[i]==s[j] && F[i+1][j-1]==true){
                    F[i][j] = true;
                }
            }
            if(F[i][j]) res = max(res,len);
        }
    }
    cout << "Do dai xau Palindrome dai nhat la: " << res << endl;
}

int main(){
    string s;
    cin >> s;
    s = '0' + s;
    solve1(s);
}

/*
Dùng duyệt cận:
Xét từng vị trí i:
- Xem Si có phải là tâm của Palindrome có lẻ kí tự không? (ví dụ Palindrome MADAM có tâm là kí tự D)
- Xem Si và Si+1 có phải là tâm của Palindrome có chẵn kí tự không? (ví dụ Palindrome ABBA có tâm là 2 kí tự BB)
- Với mỗi kí tự ta tìm palindrome dài nhất nhận nó là tâm, cập nhập lại kết quả khi duyệt. Ta duyệt từ giữa ra để dùng kết quả hiện tại làm cận.


#include<bits/stdc++.h>

using namespace std;

int res = 1;
int i,j;
string s;

void Try(int first, int last, int n){
	int d=0;
	if(first==last){
		d = 1;
		first--;
		last++;
	}
	while(true){
		if(first<1 || last>n) break;
		if(s[first]==s[last]){
			d += 2;
			first--;
			last++;
		}
		else break;
	}
	if(res<d) res = d;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	int n = s.size();
	s = '0' + s;
	i = n/2;
	j = n/2 + 1;
	while(i>res/2 && j<=n-res/2){
	   	if(i>res/2){
	   		Try(i,i,n);
	   		Try(i,i+1,n);
		}
		if(j<=n-res/2){
			Try(j,j,n);
			Try(j,j+1,n);
		}
		i--;
		j++;
	}
	cout << res;
}
*/