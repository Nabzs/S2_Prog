#include "graph.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "ex1" << std::endl;
    // ======= Exercice 1 : Création et comparaison de graphes =======
    // Exemple de matrice d'adjacence
    std::vector<std::vector<float>> matrix = {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    // Création du graphe à partir de la matrice
    Graph::WeightedGraph g1 = Graph::build_from_adjacency_matrix(matrix);

    // Création du même graphe manuellement
    Graph::WeightedGraph g2;
    for (int i = 0; i < 5; ++i) g2.add_vertex(i);
    g2.add_directed_edge(0, 1, 1.0f);
    g2.add_directed_edge(0, 4, 2.0f);
    g2.add_directed_edge(1, 2, 2.0f);
    g2.add_directed_edge(1, 3, 4.0f);
    g2.add_directed_edge(2, 3, 1.0f);
    g2.add_directed_edge(3, 4, 6.0f);

    std::cout << "Les deux graphes sont " << (g1 == g2 ? "égaux" : "différents") << std::endl ;
    
    std::cout << "ex2" << std::endl;
    // ======= Exercice 2 : Parcours DFS et BFS =======
    
    std::cout << "DFS depuis 0 : ";
    g1.print_DFS(0);
    std::cout << "BFS depuis 0 : ";
    g1.print_BFS(0);

    std::cout << "DFS (callback) depuis 0 : ";
    g1.DFS(0, [](int const node_id) { std::cout << node_id << " "; });
    std::cout << std::endl;

    // Exemple d'utilisation de Dijkstra pour trouver le plus court chemin de 0 à 4
    auto distances = Graph::dijkstra(g1, 0, 4);
    if (distances.find(4) != distances.end()) {
        std::cout << "Plus court chemin de 0 à 4 (distance: " << distances[4].first << "): ";
        // Reconstruction du chemin
        std::vector<int> path;
        int current = 4;
        while (current != -1) {
            path.push_back(current);
            current = distances[current].second;
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            std::cout << *it << (it + 1 != path.rend() ? " -> " : "");
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pas de chemin trouvé de 0 à 4." << std::endl;
    }

    return 0;
}