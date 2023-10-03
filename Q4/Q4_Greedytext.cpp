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
	double START,END; 
	ofstream ofs;
	ofs.open("Greedy.txt");
	for(int n=1;n<=10000;n++){
		for(int i=0;i<n;i++){
			jobs[i].order=i+1;
			jobs[i].time=rand()%100000+1;
			jobs[i].deadline=rand()%100000+1;
		}
		START = clock();
		sort(jobs,jobs+n,cmp);
		int sum=0;
	
		for(int i=0;i<n;i++){
			ans.push_back(i);
			sum+=jobs[i].time;
			if(sum>jobs[i].deadline){
				sum=sum-FindMAX();	//找到job time最大並移除 
			}
		}
		END = clock();
		ofs <<(END - START) / CLOCKS_PER_SEC  << "\n";
		cout<<"n="<<n<<"OK!"<<endl;
		ans.clear();
	}
}
