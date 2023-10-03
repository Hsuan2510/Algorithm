#include<bits/stdc++.h> 
#define MAX 2147483647
using namespace std;

struct node{  
	float x;
	float y;
};
int main(){		//¼É¤O½aÁ|ªk 
	double START,END; START = clock();
	int num=0;
	int dis;
	int min=MAX;
	float ans;
	cin>>num;
	node *arr=new node[num];
	for(int i=0;i<num;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			dis=(pow((arr[j].x-arr[i].x),2)+pow((arr[j].y-arr[i].y),2));
			if(dis<min) min=dis;
		}
	}
	ans=sqrt(min);
	cout<<fixed<<setprecision(3)<<ans<<endl;
	

	END = clock();
	cout << (END - START) / CLOCKS_PER_SEC << endl;
	
}
