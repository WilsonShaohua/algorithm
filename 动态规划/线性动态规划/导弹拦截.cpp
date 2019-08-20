//https://www.luogu.org/problem/P1020
#include<bits/stdc++.h>
using namespace std;
#include<ostream>
const int maxn=1e5+7;
int a[maxn],d1[maxn],d2[maxn],n;
/*
ower_bound会找出序列中第一个大于等于x的数

upper_bound会找出序列中第一个大于x的数
*/

inline bool read(int &x){
	char c= getchar();
	if(c==EOF) return false;
	while(c>'9' && c<'0') c=getchar();
	while(c>='0' && c<='9'){
		x=(x<<1) + (x<<3) + (c^48);
		c=getchar();
	}
	return true;
} 


int main(){
	while(read(a[++n])); n--;
	int len1=1,len2=1;
	d1[1]=d2[1]=a[1];
	for(int i=2;i<=n;i++){
		if(d1[len1]>=a[i]) 
			d1[++len1]=a[i];
		else
			*upper_bound(d1+1,d1+1+len1,a[i],greater<int>())=a[i];
		if(d2[len2]<a[i])
			d2[++len2]=a[i];
		else
		 *lower_bound(d2+1,d2+1+len2,a[i])=a[i];		
	}
	printf("%d\n%d",len1,len2);
	return 0;
}