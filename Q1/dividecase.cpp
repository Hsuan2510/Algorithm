#include<bits/stdc++.h> 
#define x first
#define y second
#define INF 5e18
using namespace std;
vector<pair<int,int> > arr,temp;
int threshold;

double dis(pair<int,int> a,pair<int,int> b){
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.y < b.y;
}
double divide(int L,int R){
	if((R-L)==0) {
		double d=0;
		double min=INF;
		for(int i=L;i<R;i++){
			for(int j=i+1;j<R;j++){
				d=dis(arr[i],arr[j]);
				if(d<min) min=d;
			}
		}
		return min;
	}
	int mid=(L+R)/2;
	int mid_pos=arr[mid].x;
	double ans=min(divide(L,mid),divide(mid+1,R));
	
	temp.assign((R-L+1),{0,0});
	merge(arr.begin()+L,arr.begin()+mid+1,arr.begin()+mid+1,arr.begin()+R+1,temp.begin(),cmp);
	
	//merge(arr,temp,L,mid,R);

	for(int i=L;i<=R;i++) arr[i] = temp[i-L]; //«ö·Óy±Æ§Ç¦n 
	temp.clear();
	for(int i=L;i<=R;i++){
		if(abs(arr[i].x-mid_pos)<=ans){
			temp.push_back(arr[i]);
		}
	}
	int lengh=temp.size();
	for(int i=0;i<lengh;i++){
		for(int j=i+1;j<lengh;j++){
			ans=min(ans,dis(temp[i],temp[j]));
			if(abs(temp[i].y-temp[j].y)>ans) break;
		}
	}
	
	return ans ;
}


int main(){
	int n;
	cin>>n;
	temp.clear();
	arr.assign(n,{0,0});
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	sort(arr.begin(),arr.end());
	
	double ans=divide(0,n-1);
	cout<<fixed<<setprecision(3)<<ans<<endl;
	 
}
