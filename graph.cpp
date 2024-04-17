#include <bits/stdc++.h>
using namespace std;
class graph{
public:
	unordered_map<int,vector<int>> adj;

	void addEdge(int u , int v, bool direction)
	{
		// direction 0 -> undirected
		// direction 1 -> directed

		// creating edge from u to v
		adj[u].push_back(v);

		// using direction we determine if we have to add the opposite edge on the graph
		if (direction==0){
			adj[v].push_back(u);
		}
	}

	void printAdj()
	{
		for (auto i:adj)
		{
			cout << i.first << " -> ";
			for (auto j:i.second)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
};





// BFS -> Breadth first search
vector<int> bfs(int n , int start , unordered_map<int,vector<int>> &adj)
{
	vector<int> ans;
	queue<int> q;
	q.push(start);
	vector<int> visited(n);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		if (!visited[t])
		{
			ans.push_back(t);
			visited[t] = 1;
		}
		for (auto i:adj[t])
		{
			if (visited[i])
			{
				continue;
			}
			q.push(i);
		}
	}
	return ans;
}	



// DFS -> depth first search
void dfs(int node , vector<int> &component ,unordered_map<int,vector<int>> &adj ,bool visited[] )
{
    component.push_back(node);
    for (auto i:adj[node])
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(i,component,adj,visited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int n ,unordered_map<int,vector<int>> &adj)
{
    bool visited[n] = {false};
    vector<vector<int>> ans;
    for (int i = 0 ;i<n ; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            vector<int> component;
            dfs(i,component,adj,visited);
            ans.push_back(component);
        }
    }
    return ans;
    
}




int main()
{
	int n;
	cout << "Enter the number of nodes" << endl;
	cin >> n;
	int m;
	cout << "Enter the number of edges" << endl;
	cin >> m;
	graph g;
	for (int i = 0; i<m ; i++)
	{
		int u,v,direction;
		cout << "Enter the first node " << " ";
		cin >> u;
		cout << endl;
		cout << "Enter the second node " << " ";
		cin >> v;
		cout << "Enter the direction " << " ";
		cin >> direction;
		g.addEdge(u,v,direction);
	}
	cout << endl;
	g.printAdj();
	cout << endl;


// bfs
	cout << "BFS" << endl;
	cout << "Enter the position from where to start " << endl;
	int start;
	cin >> start; 
	vector<int> bfsv = bfs(n ,start,g.adj);
	for (auto i:bfsv)
	{
		cout << i << " ";
	}
	cout <<"BFS is done" <<  endl;



// dfs
	cout << "DFS" << endl;
	vector<vector<int>> dfsv = depthFirstSearch(n,g.adj);
	for (int i = 0 ; i<dfsv.size() ; i++)
	{
		for (auto j:dfsv[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}

	cout << "DFS is done" << endl;

	

}
