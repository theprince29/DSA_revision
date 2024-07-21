#include<bits/stdc++.h>
using namespace std;


// Function to create an adjacency matrix
vector<vector<int>> create_adj_mat(const vector<vector<int>>& graph, int n) {
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                adj_matrix[i][j] = 1;
                adj_matrix[j][i] = 1; // For undirected graph
            }
        }
    }
    return adj_matrix;
}

// Function to print the adjacency matrix
void print_adj_matrix(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to create an adjacency list
vector<vector<int>> create_adj_list(const vector<vector<int>>& graph, int n) {
    vector<vector<int>> adj_list(n);
    vector<vector<int>> gr = graph;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (gr[i][j] == 1) {
                gr[j][i] =0;
                adj_list[i].push_back(j);
                adj_list[j].push_back(i); // For undirected graph
            }
        }
    }
    return adj_list;
}

// Function to print the adjacency list
void print_adj_list(const vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ":";
        for (const auto& v : adj_list[i]) {
            cout << " " << v;
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    // Create and print adjacency matrix
    vector<vector<int>> adj_matrix = create_adj_mat(graph, n);
    cout << "Adjacency Matrix:" << endl;
    print_adj_matrix(adj_matrix);

    // Create and print adjacency list
    vector<vector<int>> adj_list = create_adj_list(graph, n);
    cout << "Adjacency List:" << endl;
    print_adj_list(adj_list);

    return 0;
}