//https://www.luogu.org/problem/P1091

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e3+7;
int a[MAXN],d1[MAXN],d2[MAXN],n;
#define INF 0x7fffffff

void list1(){
	int f[MAXN];
	int len=1;
	f[1]=a[1];
	d1[1]=1;
	for(int i=2;i<=n;i++){
		if(f[len]<a[i]){
			f[++len]=a[i];
		}else{
			f[lower_bound(f+1,f+1+len,a[i]) - f]=a[i];
		}
		d1[i]=len;
	}
}

void list2(){
	int f[MAXN];
	int len=1;
	f[1]=a[n];	
	for(int i=n-1;i>=1;i--){
		if(f[len]<a[i]){
			f[++len]=a[i];
		}else{
			/*
			lower_bound(start,end,value,|operator|) 
			参数类型与sort方法的参数类似 
			作用是找到参数中的地址区间内第一个小于等于value的地址
			返回地址 
			*/ 
			f[lower_bound(f+1,f+1+len,a[i]) - f]=a[i];			
		}
		d2[i]=len;
	}
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	list1();
	list2();
	int ans=INF;	
	for(int i=1;i<=n;i++){
		ans=min(ans,n-d1[i] - d2[i+1]);
	}
	printf("%d",ans);
	return 0;
}
