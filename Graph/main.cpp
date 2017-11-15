//
//  main.cpp
//  Graph
//
//  Created by Mads Tilgaard Jensen on 05/12/2016.
//  Copyright © 2016 Mads Tilgaard Jensen. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"

int main()
{
    std::cout << "Test of Dijkstras algorithm: " << std::endl;
    Graph* G0 = new Graph;
    
    Vertex* V0 = new Vertex(0);
    Vertex* V1 = new Vertex(1);
    Vertex* V2 = new Vertex(2);
    Vertex* V3 = new Vertex(3);
    Vertex* V4 = new Vertex(4);
    Vertex* V5 = new Vertex(5);
    
    Edge* E0 = new Edge(7, V4);
    Edge* E1 = new Edge(3, V5);
    Edge* E2 = new Edge(9, V3);
    Edge* E3 = new Edge(8, V4);
    Edge* E4 = new Edge(1, V2);
    Edge* E5 = new Edge(1, V0);
    Edge* E6 = new Edge(2, V5);
    Edge* E7 = new Edge(4, V2);
    Edge* E8 = new Edge(5, V1);
    
    G0->addVertex(V0);
    G0->addVertex(V1);
    G0->addVertex(V2);
    G0->addVertex(V3);
    G0->addVertex(V4);
    G0->addVertex(V5);
    
    V0->addEdge(E6);
    V0->addEdge(E8);
    
    V1->addEdge(E7);
    
    V2->addEdge(E2);
    
    V3->addEdge(E0);
    V3->addEdge(E1);
    
    V4->addEdge(E5);
    
    V5->addEdge(E3);
    V5->addEdge(E4);
    
    std::cout << "Vertices and their distances from V0 before Dijkstras algoritm(255 is equal to infinity): " << std::endl;
    G0->printGraphDistances();
    
    Dijkstra D(G0, V0);
    std::cout << "Vertices and their distances from V0 after Dijkstras algoritm: " << std::endl;
    G0->printGraphDistances();

    std::cout << "Test of topological sorting: " << std::endl;
    
    Graph* G1 = new Graph;
    
    Vertex* V10 = new Vertex(5);
    Vertex* V11 = new Vertex(7);
    Vertex* V12 = new Vertex(3);
    Vertex* V13 = new Vertex(11);
    Vertex* V14 = new Vertex(8);
    Vertex* V15 = new Vertex(2);
    Vertex* V16 = new Vertex(9);
    Vertex* V17 = new Vertex(10);
    
    Edge* E10 = new Edge(1, V13);
    Edge* E11 = new Edge(1, V13);
    Edge* E12 = new Edge(1, V14);
    Edge* E13 = new Edge(1, V14);
    Edge* E14 = new Edge(1, V17);
    Edge* E15 = new Edge(1, V15);
    Edge* E16 = new Edge(1, V16);
    Edge* E17 = new Edge(1, V16);
    Edge* E18 = new Edge(1, V17);
    
    G1->addVertex(V14);
    G1->addVertex(V15);
    G1->addVertex(V16);
    G1->addVertex(V17);
    G1->addVertex(V10);
    G1->addVertex(V11);
    G1->addVertex(V12);
    G1->addVertex(V13);
    
    V10->addEdge(E10);
    
    V11->addEdge(E11);
    V11->addEdge(E12);
    
    V12->addEdge(E13);
    V12->addEdge(E14);
    
    V13->addEdge(E15);
    V13->addEdge(E16);
    V13->addEdge(E18);
    
    V14->addEdge(E17);
    
    std::cout << "Before topological sort: " << std::endl;
    G1->printGraph();
    G1->topologicalSorting();
    std::cout << "After topological sort: " << std::endl;
    G1->printGraph();
    
    

    
    return 0;
}
