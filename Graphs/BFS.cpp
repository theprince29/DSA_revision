#include<bits/stdc++.h>
using namespace std;

vector<int>BFS_traversal_of_graph(vector<int>adj[],int v)
{
    vector<int>visited(v,0);
    queue<int>q;
    visited[0]=1;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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

    vector<int> bfs_result = BFS_traversal_of_graph(adj, v);

    // printing the BFS traversal result
    cout << "BFS Traversal of the graph: ";
    for (int i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    
    return 0;
}