#include<bits/stdc++.h> 
#include <queue>
#define INT_MAX 2147483647
using namespace std;

struct job{
	int order;
	int deadline;
	int time;
};
bool cmp(job a, job b) {
	return a.deadline < b.deadline;
}
int DP[10005][10005];
bool put[10005][10005]; 
int main(){
	int n;
	cin>>n;
	job *jobs=new job[n];
	for(int i=0;i<n;i++){
		jobs[i].order=i+1;
		cin>>jobs[i].time;
		cin>>jobs[i].deadline;
	}
	sort(jobs,jobs+n,cmp);
	//init
	
	for(int i=0;i<n+1;i++){
		DP[i][0]=0;
		for(int j=1;j<n+1;j++){
			 DP[i][j]=INT_MAX;
		}
	}
	/*
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<DP[i][j]<<" "; 
		}
		cout<<endl;
	}
	cout<<endl;*/
	//DP
	for (int i = 1; i <= n; i++){
		for (int k = 1; k<=i; k++){
			
			DP[i][k]=DP[i-1][k];
			if(DP[i-1][k-1]!=INT_MAX && DP[i-1][k-1]<=jobs[i-1].deadline-jobs[i-1].time){
				if(DP[i][k]<DP[i-1][k-1]+jobs[i-1].time)
					DP[i][k]=DP[i][k];
				else
					DP[i][k]=DP[i-1][k-1]+jobs[i-1].time;
			}
			/*if(DP[i][k-1]+jobs[i-1].time<=jobs[i-1].deadline){
				if(DP[i][k-1]+jobs[i-1].time<DP[i-1][k]){
					DP[i][k]=DP[i][k-1]+jobs[i-1].time;
					put[i][k]=true;
				}
				else{
					DP[i][k]=DP[i-1][k];
					put[i][k]=false;
				}
			}
			else{
				DP[i][k]=DP[i-1][k];
				put[i][k]=false;
			}*/	
		}
	}
	//check
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<DP[i][j]<<" "; 
		}
		cout<<endl;
	}
	//print
	vector<int> ans;
	int a=n,b=n;
	while(a!=0 && b!=0){
		while(DP[a][b]==INT_MAX){
			b--;
			
		}
		if(DP[a-1][b-1]+jobs[a-1].time==DP[a][b]){
			ans.push_back(jobs[a-1].order);
			a--;
			b--;
		}
		else{
			a--;
		}
	}
	while(ans.size()!=1){
		cout<<ans[ans.size()-1]<<" ";
		ans.pop_back();
	}
	cout<<ans[ans.size()-1];
}



