#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	double START,END; 
	cin>>n;
	long long int *fibonacci=new long long int[n];
	fibonacci[0]=0;
	fibonacci[1]=1;
	START = clock();
	for(int i=2;i<=n;i++) 
		fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
		
	cout<<fibonacci[n]<<endl;
	END = clock();
	cout<<"花費時間: "<<(END - START) / CLOCKS_PER_SEC<<endl; 
}
