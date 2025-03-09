#include "dijkstras.h"

int main(){
    string filename = "src/small.txt";
    file_to_graph(filename, G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    
    cout << "\nShortest paths from vertex 0:\n";
    for (int i = 0; i < G.numVertices; i++) {
        cout << "To vertex " << i << ": ";
        vector<int> path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }
    
    return 0;
}