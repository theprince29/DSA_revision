#include<bits/stdc++.h>
using namespace std;



 void dfs(int node,vector<int>adj[],int visited[],vector<int>&ls)
    {
        visited[node] =1;
        ls.push_back(node);
        
        for(auto it :adj[node])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,ls);
            }
        }
    }

vector<int>DFS_traversal_of_graph(vector<int>adj[],int v)
{
   int visited[v] = {0};
        int start =0 ;
        vector<int> ls;
        
        dfs(start,adj,visited,ls);
        
        return ls;
}


int main()
{

    int v = 5; // number of vertices
    vector<int> adj[v];

    // creating a graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[3].push_back(4);

    vector<int> bfs_result = DFS_traversal_of_graph(adj, v);

    
    cout << "DFS Traversal of the graph: ";
    for (int i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    
    return 0;
}