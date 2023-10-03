#include<bits/stdc++.h> 
#include <algorithm>
#include <queue>
using namespace std;
struct job{
	int order;
	int deadline;
	int time;
};
job *jobs=new job[10005];
vector <int> ans;
bool cmp(job a, job b) {
	return a.deadline < b.deadline;
}
bool cmpW(int a, int b) {
	return jobs[a].time < jobs[b].time;
}
int FindMAX(){
	int max=0;
	int idx;
	for(int i=0;i<ans.size();i++){
		if(jobs[ans[i]].time>max){
			max=jobs[ans[i]].time;
			idx=i;
		}
	}
	ans.erase(ans.begin()+idx);
	return max;
}
int main(){
	int n;
	cin>>n;
	//job *jobs=new job[n];
	for(int i=0;i<n;i++){
		jobs[i].order=i+1;
		cin>>jobs[i].time;
		cin>>jobs[i].deadline;
	}
	sort(jobs,jobs+n,cmp);
	int sum=0;
	
	for(int i=0;i<n;i++){
		ans.push_back(i);
		sum+=jobs[i].time;
		if(sum>jobs[i].deadline){
			sum=sum-FindMAX();
		}
	}
	for(int i=0;i<ans.size()-1;i++){
		cout<<jobs[ans[i]].order<<" ";
	}
	cout<<jobs[ans[ans.size()-1]].order;
}
