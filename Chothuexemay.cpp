#include<bits/stdc++.h>
using namespace std;

/*
Trung tâm tính toán hi?u nang cao nh?n du?c don d?t hàng c?a n khách hàng. Khách hàng i mu?n s? d?ng máy trong kho?ng th?i gian t? ai d?n bi và tr? ti?n thuê là ci. 
Hãy b? trí l?ch thuê máy d? t?ng s? ti?n thu du?c là l?n nh?t mà th?i gian s? d?ng máy c?a 2 khách hàng b?t kì du?c ph?c v? d?u không giao nhau (c? trung tâm ch? có m?t máy cho thuê).
*/

int a[10005],b[10005],c[10005];

void Swap(int l, int r){
    int t1 = a[l];
    a[l] = a[r];
    a[r] = t1;
    int t2 = b[l];
    b[l] = b[r];
    b[r] = t2;
    int t3 = c[l];
    c[l] = c[r];
    c[r] = t3;
}

int partition(int low, int high){
    int l = low;
    int r = high-1;
    int pivot = b[high];
    while(true){
        while(l<=r && b[l] < pivot) l++;
        while(r>=l && b[r] > pivot) r--;
        if(l>=r) break;
        Swap(l,r);
        l++;
        r--;
    }
    Swap(l,high);
    return l;
}

void quicksort(int low, int high){
    if(low<high){
        int p = partition(low,high);
        quicksort(low,p-1);
        quicksort(p+1,high);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i] >> d >> c[i];
            b[i] = a[i] + d;
        }
        quicksort(1,n);
        long long l[10005],res=0;
        for(int i=1;i<=n;i++){
        	l[i] = (long long)c[i];
		}
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(b[j]<a[i]){
					long long tmp = (long long)l[j] + (long long)c[i];
					l[i] = max(l[i],tmp);
				}
            }
            res = max(res,l[i]);
        }
        cout << res << endl;
    } 
}