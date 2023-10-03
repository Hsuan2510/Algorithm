#include<bits/stdc++.h>
#include <queue>

using namespace std;

int n;
vector< pair<int,int> > *rgraph;
vector< pair<int,int> > *graph;
bool BFS(vector< pair<int,int> > rG[],int s,int t,int p[]){
	bool visit[n];
	//init
	for(int i=0;i<n;i++){
		visit[i]=0;
	}
	
	queue<int> q;
	q.push(s);
	visit[s]=true;
	p[s]=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<rG[u].size();i++){
			int v;
			v=rG[u][i].first;
			/*int cmp=-1;
			for(int i=0;i<rG[u].size();i++){
				if(rG[u][i].first==v){
					cmp=rG[u][i].second;
					break;
				}	
			}*/
			//cout<<v<<" ";
			if(visit[v]==false && rG[u][i].second>0){
				if (v == t) {
                    p[v] = u;
                    return true;
                }
                q.push(v);
                p[v] = u;
                visit[v] = true;
			}
		}
	}
	return false;
	
}
int fordFulkerson(vector< pair<int,int> > G[],vector< pair<int,int> > rgraph[],int s, int t){
	int u,v;
	//init rgraph
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j].first<<G[i][j].second;
		}
		cout<<endl;
	}*/
	
	for(u=0;u<n;u++){
		for(int v=0;v<G[u].size();v++){
			rgraph[u].push_back(G[u][v]);	
		}
	}
	int parent[n]={-1};
	int max_flow=0;
	//§äargument path 
	while (BFS(rgraph,s, t, parent)){
		int path_flow =10000;
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];
			int cmp_flow;
			for(int i=0;i<rgraph[u].size();i++){
				if(rgraph[u][i].first==v){
					cmp_flow=rgraph[u][i].second;
					break;
				}
			}
			path_flow=min(path_flow,cmp_flow);
		}
		for(int v=t;v!=s;v=parent[v]){
			u = parent[v];
			for(int i=0;i<rgraph[u].size();i++){
				if(rgraph[u][i].first==v){
					rgraph[u][i].second-=path_flow;
					break;
				}
			}
			for(int i=0;i<rgraph[v].size();i++){
				if(rgraph[v][i].first==u){
					rgraph[v][i].second+=path_flow;
					break;
				}
			}
		}
		max_flow += path_flow;	
	}
	for(int i=0;i<n;i++){
		rgraph[i].clear();
	}
	return max_flow;
	
}
int main(){
	cin>>n;
	int u,v;
	int min=10000;
	vector< pair<int,int> > *graph=new vector< pair<int,int> >[n+1];
	vector< pair<int,int> > *rgraph=new vector< pair<int,int> >[n+1];
	while(cin>>u>>v){
		graph[u].push_back(make_pair(v,1));
		graph[v].push_back(make_pair(u,1));
	}
	for(int i=1;i<n;i++){
		int now;
		now=fordFulkerson(graph,rgraph,0,i);
		if(min>now)	min=now;	
	}	cout<<min<<endl;
	
}
