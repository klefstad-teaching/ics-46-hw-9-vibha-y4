#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    vector<int> distances(G.numVertices, INF);
    previous.assign(G.numVertices, -1);
    vector<bool> visited(G.numVertices, false);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, source});
    distances[source] = 0;
    
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]){
            continue;
        }
        visited[u] = true;
        
        for (const Edge& e : G[u]){
            int v = e.dst;
            int weight = e.weight;
            
            if (!visited[v] && distances[u] != INF && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if (distances[destination] == INF) return path;
    
    for (int v = destination; v != -1; v = previous[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    if (!v.empty()){
        for (size_t i = 0; i < v.size(); i++){
            cout << v[i];
            if (i < v.size() - 1){
                cout << " ";
            }
        }
    }
    cout << "\n" << "Total cost is " << total << endl;
}