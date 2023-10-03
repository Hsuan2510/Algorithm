#include<bits/stdc++.h>
#include <list>
#include <vector>
using namespace std;

vector< pair<int,int> > ans; 
int n;
struct node{
	vector<int> adj;
};
bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}
void DFS(int u,bool visit[],int disc[],int low[],int parent[],node graph[]){
	static int time=0;
	visit[u]=true;
	disc[u]=low[u]=time;
	time++;
	//check
	for(int i=0;i<graph[u].adj.size();i++){
		int v= graph[u].adj[i];
		if(visit[v]==false){
			parent[v]=u;
			DFS(v,visit,disc,low,parent,graph);
			low[u]=min(low[u],low[v]);
			
			if(low[v]>disc[u]){
				if(u<v)
					ans.push_back(make_pair(u,v));
				else
					ans.push_back(make_pair(v,u));
			}
				
				
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);
	}
}
void findBridge(node graph[]){
	//init
	bool *visit=new bool[n];
	int *disc= new int[n];
	int *low=new int[n];
	int *parent=new int[n];
	for(int i=0;i<n;i++){
		parent[i]=NULL;
		visit[i]=false;
	}
	
	//DFS
	for(int i=0;i<n;i++){
		if(visit[i]==false)
			DFS(i,visit,disc,low,parent,graph);
	}
	
	
	//
	
}
int main(){
	cin>>n;
	node *graph=new node[n+1];
	int u,v;
	while(cin>>u>>v){
		graph[u].adj.push_back(v);
		graph[v].adj.push_back(u);
	}
	/* check
	for(int i=0;i<n;i++){
		cout<<i<<":";
		for(int j=0;j<graph[i].adj.size();j++){
			cout<<graph[i].adj[j]<<" ";
		}
		cout<<endl;
	}*/
	findBridge(graph);
	sort(ans.begin(),ans.end(),cmp);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	
}

