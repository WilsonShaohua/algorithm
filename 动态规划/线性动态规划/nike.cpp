/*
转移方程：
	f[i]=f[i+1]+1   第i各数据的值为上一个值的空闲时间+1
	f[i] = max(f[i],f[i+r[num].last] 当前时间有任务下达，判断任务完成时间的结束时间后那个值的空闲时间更多
从后向前遍历查找
return f[1]
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
int n,k;
int f[MAXN],sum[MAXN];

struct ren{
	int start;
	int last;
};
ren r[MAXN];


inline  int cmp(ren r1,ren r2){
	return r1.start >r2.start;
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
	cin>>r[i].start;
		cin>>r[i].last;
		sum[r[i].start]++;
	}
	int num=1;
	sort(r+1,r+k+1,cmp);
	
	for(int i=n;i>=1;i--){
		if(sum[i]==0){
			f[i]=f[i+1] + 1;
		}else{
			for(int j=1;j<=sum[i];j++){
				if(f[i + r[num].last] > f[i]){
					f[i] = f[i+r[num].last];					
				}
				num++;
			}
		}
	}
	
	printf("%d",f[1]);
	
	return 0;
}