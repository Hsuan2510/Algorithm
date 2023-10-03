#include<bits/stdc++.h> 
#define x first
#define y second
#define INF 5e18
using namespace std;
vector<pair<int,int> > arr,temp;
int threshold;

int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    /* 計算可以被整除的長度 */
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;

    /* 將尾端會造成偏差的幾個亂數去除，
       若產生的亂數超過 limit，則將其捨去 */
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}

double dis(pair<int,int> a,pair<int,int> b){
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
/*void merge(vector<pair<int,int> > &arr,vector<pair<int,int> > &temp,int L,int mid,int R){
	int j=mid+1;
	int k=0;
	while(L<=mid && j<=R){
		if(arr[L].y<=arr[j].y)
			temp[k++]=arr[L++];
		else
			temp[k++]=arr[j++];
	}
	if(L>mid){
		for(int t=j;j<=R;t++){
			temp[k+t-j]=arr[t];
		}
		
	}
	else{
		for(int t=L;t<=mid;t++){
			temp[k+t-L]=arr[t];
		}
	}
	
}*/
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.y < b.y;
}
double divide(int L,int R){
	if((R-L)<=threshold) {
		int d=0;
		int min=INF;
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

	for(int i=L;i<=R;i++) arr[i] = temp[i-L]; //按照y排序好 
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
	int n=100000;
	int small = -10000;
	int big= 10000;
	double START,END; 
	temp.clear();
	arr.assign(n,{0,0});
	for(int i=0;i<n;i++) {
		arr[i].x=randint(big-small + 1) + small;
		arr[i].y=randint(big-small + 1) + small;
	} 
	sort(arr.begin(),arr.end());
	ofstream ofs;
	ofs.open("output.txt");
	for(int i=0;i<=300;i++){
		START = clock();
		threshold=i;
		cout<<"threshold="<<threshold<<" ok!"<<endl;
		double ans=divide(0,n-1);
		END = clock();
		ofs <<(END - START) / CLOCKS_PER_SEC  << "\n";
		sort(arr.begin(),arr.end());
	}
	/*for(int i=1;i<10;i++){
		threshold++;
		double ans=divide(0,n-1);
		//cout<<"threshold="<<i<<" OK!"<<endl;
		//	cout<<fixed<<setprecision(3)<<ans<<endl;
		//	cout<<"YES"; 
	}*/
	//END = clock();
	//cout << (END - START) / CLOCKS_PER_SEC << endl; 
}
