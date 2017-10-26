#include <iostream>
#include <vector>
using namespace std;
class Graph{
	int nV;
	int nE;
	vector<int> *adjList;

public:
	Graph(int n){
		nV=n;
		adjList= new vector<int>[nV+1];
	}
	~Graph(){
		delete [] adjList;
	}
	void addEdge(int x,int y){
		adjList[x].push_back(y);
	}
	void DFSUtil(int src,bool visited[]){
		visited[src]=true;
		cout<<src<<" ";

		for(int i=0;i<adjList[src].size();++i){
			int neighbor=adjList[src][i];

			if(visited[neighbor]==false){
				DFSUtil(neighbor,visited);
			}
		}
	}
	void DFS(int src){
		bool *visited = new bool[nV+1];
		DFSUtil(src,visited);
		delete [] visited;
	}
};
int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);	
	return 0;
}