#include<bits/stdc++.h>

using namespace std;
int fibonacci(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	
	return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
	double START,END; 
	int n;
	cin>>n;
	//ofstream ofs;
	//ofs.open("recursive.txt");
		START = clock();
		cout<<fibonacci(n)<<endl;
		END = clock();
		cout <<"花費時間: "<<(END - START) / CLOCKS_PER_SEC  << "\n";
	return 0;
}
