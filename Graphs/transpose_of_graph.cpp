#include <bits/stdc++.h>
using namespace std;

void add_edges(vector<int> adj[], int src, int dest) {
    adj[src].push_back(dest);
}

void display_of_graph(vector<int> adj[], int v) {
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose_of_graph(vector<int> adj[], vector<int> transpose_list[], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            add_edges(transpose_list, adj[i][j], i);
        }
    }
}

int main() {
    int v = 5;
    vector<int> adj[v];
    
    add_edges(adj, 0, 1);
    add_edges(adj, 0, 2);
    add_edges(adj, 1, 3);
    add_edges(adj, 2, 3);
    add_edges(adj, 3, 4);

    cout << "Original Graph:" << endl;
    display_of_graph(adj, v);

    vector<int> transpose[v];
    transpose_of_graph(adj, transpose, v);

    cout << "Transpose of Graph:" << endl;
    display_of_graph(transpose, v);

    return 0;
}
