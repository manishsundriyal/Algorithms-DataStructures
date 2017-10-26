#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
	int nV;
	int nE;
	vector<int> *adjList;
public:
	Graph(int n){
		nV=n;
		nE=0;
		adjList=new vector<int>[nV+1];
	}
	~Graph(){
		delete [] adjList;
	}
	void addEdge(int x, int y){
		
		adjList[x].push_back(y);
		++nE;
	}
	void BFS(int src){
		bool *visited = new bool[nV+1];
		queue<int> q;
		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			int curVertex=q.front();
			q.pop();

			cout<<curVertex<<" ";

			for(int i=0;i<adjList[curVertex].size();++i){
				int neighbor=adjList[curVertex][i];
				if(visited[neighbor]==false){
					visited[neighbor]=true;
					q.push(neighbor);
				}
			}
		}
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

    g.BFS(2);
	return 0;
}