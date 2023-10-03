#include<bits/stdc++.h> 
#define MAX 2147483647
using namespace std;

struct node{  
	float x;
	float y;
};
bool cmpX(node a,node b){
	return a.x<b.x;
}

int main(){
	int n;
	int min=MAX;
	cin>>n;
	node *arr=new node[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].y;
	}
	sort(arr,arr+n,cmpX);
}
