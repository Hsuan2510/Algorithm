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
job *jobs=new job[10005];
int main(){
	double START,END; 
	ofstream ofs;
	ofs.open("DP.txt");
	for(int n=1;n<=10000;n++){
		for(int i=0;i<n;i++){
			jobs[i].order=i+1;
			jobs[i].time=rand()%100000+1;
			jobs[i].deadline=rand()%100000+1;
		}
		START = clock();
		sort(jobs,jobs+n,cmp);
		for(int i=0;i<n+1;i++){
			DP[i][0]=0;
			for(int j=1;j<n+1;j++){
				DP[i][j]=INT_MAX;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int k = 1; k<=i; k++){	
				DP[i][k]=DP[i-1][k];
				if(DP[i-1][k-1]!=INT_MAX && DP[i-1][k-1]<=jobs[i-1].deadline-jobs[i-1].time){
					if(DP[i][k]<DP[i-1][k-1]+jobs[i-1].time)
						DP[i][k]=DP[i][k];
					else
						DP[i][k]=DP[i-1][k-1]+jobs[i-1].time;
				}	
			}
		}
		/*vector<int> ans;
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
		}*/ 
		END = clock();
		ofs <<(END - START) / CLOCKS_PER_SEC  << "\n";
		cout<<"n= "<<n<<" OK!"<<endl;
	}	
}



