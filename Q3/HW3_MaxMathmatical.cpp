#include<bits/stdc++.h> 
#include<algorithm> 
#define max_limit 2147483647
#define min_limit -2147483648

using namespace std;

vector<int> num;
vector<char> op;
vector<pair<int,int> > record;


long long int max_arr[1005][1005];
long long int min_arr[1005][1005];
long long int cut[1005][1005]={}; //存放最佳切點
long long int L[1005][1005]; //判斷左右界線是否是max 
long long int R[1005][1005];

long long int Fmax(long long int a,long long int b,long long int c,long long int d){
	long long int M=a;
	if(b>M) M=b;
	if(c>M) M=c;
	if(d>M) M=d;
	return M;
} 
long long int Fmin(long long int a,long long int b,long long int c,long long int d){
	long long int m=a;
	if(b<m) m=b;
	if(c<m) m=c;
	if(d<m) m=d;
	return m;
}
void findout(int i,int j,int max_or_not){
	long long int k=cut[i][j];
	if(max_or_not==0) {
		k=cut[j][i];
		
	}
	if(i!=k) {
		record.push_back({i,k});
	}
	if(k+1!=j) {
		record.push_back({k+1,j});
	}
	
	if(i != k && i != k-1){ //還可分割->recursive 
	 	if(max_or_not){
	 		if(L[i][j]==1)
	 			findout(i,k,1);
	 		else if(L[i][j]==0)
	 			findout(i,k,0);
		}
		else{
			if(L[j][i]==1)
			 	findout(i,k,1);
	 	 	else
	 			findout(i,k,0);
		}
	 }
	 if(k+1!=j && k+1!=j-1){
	 	if(max_or_not){
	 		if(R[i][j]==1)
	 			findout(k+1,j,1);
	 		else if( R[i][j]==0)
	 			findout(k+1,j,0);
		}
		else{
			if(R[j][i] == 1)
			 	findout(k+1,j,1);
	 	 	else
	 			findout(k+1,j,0);
		}
	 }
}






int main(){
	int x;
	while(cin>>x){
		num.push_back(x);
		char ch=getchar();
		if(ch=='\n')
			break;
		else
			op.push_back(ch);	
	}
	//check input
	/*for(int i=0;i<num.size();i++)
		cout<<num[i]<<" ";
	for(int i=0;i<op.size();i++)
		cout<<op[i]<<" ";*/
	
	//initialize
	
	
	for(int i=0;i<num.size();i++){
		for(int j=0;j<num.size();j++){
			max_arr[i][j]=min_limit;
			min_arr[i][j]=max_limit;
		}
	}
	for(int i=0;i<num.size();i++){
		max_arr[i][i]=min_arr[i][i]=num[i];
		cut[i][i]=-1;
	} 
	
	for(int r=0;r<num.size();r++){
		for(int i=0,j=r;i<num.size() && j<num.size();i++,j++){
			for(int k=i;k<j;k++){
				long long int MAX=min_limit,MIN=max_limit;
				long long int a,b,c,d;
				if(op[k]=='*'){
					a=max_arr[i][k]*max_arr[k+1][j];
					b=max_arr[i][k]*min_arr[k+1][j];
					c=min_arr[i][k]*max_arr[k+1][j];
					d=min_arr[i][k]*min_arr[k+1][j];
				}
				else if(op[k]=='+'){
					a=max_arr[i][k]+max_arr[k+1][j];
					b=max_arr[i][k]+min_arr[k+1][j];
					c=min_arr[i][k]+max_arr[k+1][j];
					d=min_arr[i][k]+min_arr[k+1][j];
				}
				else if(op[k]=='-'){
					a=max_arr[i][k]-max_arr[k+1][j];
					b=max_arr[i][k]-min_arr[k+1][j];
					c=min_arr[i][k]-max_arr[k+1][j];
					d=min_arr[i][k]-min_arr[k+1][j];
				}
				MAX=Fmax(a,b,c,d);
				MIN=Fmin(a,b,c,d);
				if(MAX>max_arr[i][j]) {
					max_arr[i][j]=MAX;
					cut[i][j]=k;
					if(MAX==a){
						L[i][j]=1;
						R[i][j]=1;
					}  
					else if(MAX==b){
						L[i][j]=1;
						R[i][j]=0;
					}
					else if(MAX==c){
						L[i][j]=0;
						R[i][j]=1;
					}
					else if(MAX==d){
						L[i][j]=0;
						R[i][j]=0;
					}
				}
		
				if(MIN<min_arr[i][j]){
					min_arr[i][j]=MIN;
					cut[j][i]=k;
					if(MIN==a){
						L[j][i]=1;
						R[j][i]=1;
					}  
					else if(MIN==b){
						L[j][i]=1;
						R[j][i]=0;
					}
					else if(MIN==c){
						L[j][i]=0;
						R[j][i]=1;
					}
					else if(MIN==d){
						L[j][i]=0;
						R[j][i]=0;
					}
				}
			}
		}
	}
	
	cout<<max_arr[0][num.size()-1]<<endl;

	long long int printL[num.size()];
	long long int printR[num.size()];
	for(int i=0;i<num.size();i++){
		printL[i]=0;
		printR[i]=0;
	}
	findout(0,num.size()-1,1);
	for(int i=0;i<record.size();i++){
		printL[record[i].first]++;
		printR[record[i].second]++;
	}
	for(int i=0;i<num.size();i++){
		while(printL[i]>0){
			cout<<"(";
			printL[i]--;
		}
		cout<<num[i];
		while(printR[i]>0){
			cout<<")";
			printR[i]--;
		}
		cout<<op[i];
	}
	return 0;
	
}
