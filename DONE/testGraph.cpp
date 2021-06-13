#include<iostream>
#include "function.hpp"
#include "struct.hpp"

int main(){
    int V = 13; // Untuk Ukuran array, artinya Graph berisi 12 vertex
    list node;
    ptrGraph graph;
    

    createGraph(graph, V);                                              // Membuat Graph dengan Jumlah vertex V
            
    addEdge(graph,1,2,5.6);                                             // Menambahkan Edge Antara Node 1 dan Node 2 dengan jarak 5.6 km
    addEdge(graph,1,3,5.0);                                             // Menambahkan Edge Antara Node 1 dan Node 3 dengan jarak 5 km
    addEdge(graph,1,4,1.0);                                             // Menambahkan Edge Antara Node 1 dan Node 4 dengan jarak 1 km
            
    addEdge(graph,2,1,5.6);                                             // Menambahkan Edge Antara Node 2 dan Node 1 dengan jarak 5.6 km
    addEdge(graph,2,4,4.7);                                             // Menambahkan Edge Antara NOde 2 dan node 4 dengan jarak 4.7 km
            
    addEdge(graph,3,1,5.0);                                             // Menambahkan Edge Antara Node 3 dan Node 1 dengan jarak 5 km 
    addEdge(graph,3,4,4.3);                                             // Menambahkan Edge Antara Node 3 dan Node 4 dengan jarak 4.3 km 
    addEdge(graph,3,7,5.6);                                             // Menambahkan Edge Antara Node 3 dan Node 7 dengan jarak 5.6 km    
            
    addEdge(graph,4,1,1.0);                                             // Menambahkan Edge Antara Node 4 dan Node 1 dengan jarak 1 km
    addEdge(graph,4,5,4.2);                                             // Menambahkan Edge Antara Node 4 dan Node 5 dengan jarak 4.2 km 
    addEdge(graph,4,2,4.7);                                             // Menambahkan Edge Antara Node 4 dan Node 2 dengan jarak 4.7 km
    addEdge(graph,4,3,4.3);                                             // Menambahkan Edge Antara Node 4 dan Node 3 dengan jarak 4.3 km
    addEdge(graph,4,6,3.4);                                             // Menambahkan Edge Antara Node 4 dan Node 6 dengan jarak 3.4 km
            
    addEdge(graph,5,4,4.2);                                             // Menambahkan Edge Antara Node 5 dan Node 4 dengan jarak 4.2 km
    addEdge(graph,5,6,2.3);                                             // Menambahkan Edge Antara Node 5 dan Node 6 dengan jarak 2.3 km
    addEdge(graph,5,8,3.6);                                             // Menambahkan Edge Antara Node 5 dan Node 8 dengan jarak 3.6 km
            
    addEdge(graph,6,4,3.4);                                             // Menambahkan Edge Antara Node 6 dan Node 4 dengan jarak 3.4 km
    addEdge(graph,6,5,2.3);                                             // Menambahkan Edge Antara Node 6 dan Node 5 dengan jarak 2.3 km
    addEdge(graph,6,8,4.0);                                             // Menambahkan Edge Antara Node 6 dan Node 8 dengan jarak 4 km
    addEdge(graph,6,9,2.2);                                             // Menambahkan Edge Antara Node 6 dan Node 9 dengan jarak 2.2 km
    addEdge(graph,6,7,3.0);                                             // Menambahkan Edge Antara Node 6 dan Node 7 dengan jarak 3 km
            
    addEdge(graph,7,3,5.6);                                             // Menambahkan Edge Antara Node 7 dan Node 3 dengan jarak 5.6 km
    addEdge(graph,7,10,4.7);                                            // Menambahkan Edge Antara Node 7 dan Node 10 dengan jarak 4.7 km
    addEdge(graph,7,11,3.7);                                            // Menambahkan Edge Antara Node 7 dan Node 11 dengan jarak 3.7 km
    addEdge(graph,7,9,3.1);                                             // Menambahkan Edge Antara Node 7 dan Node 9 dengan jarak 3.1 km
    addEdge(graph,7,6,3.0);                                             // Menambahkan Edge Antara Node 7 dan Node 6 dengan jarak 3 km
            
    addEdge(graph,8,5,3.6);                                             // Menambahkan Edge Antara Node 8 dan Node 5 dengan jarak 3.6 km
    addEdge(graph,8,6,4.0);                                             // Menambahkan Edge Antara Node 8 dan Node 6 dengan jarak 4 km
    addEdge(graph,8,9,2.3);                                             // Menambahkan Edge Antara Node 8 dan Node 9 dengan jarak 2.3 km
    addEdge(graph,8,11,5.1);                                            // Menambahkan Edge Antara Node 8 dan Node 11 dengan jarak 5.1 km
    addEdge(graph,8,12,4.4);                                            // Menambahkan Edge Antara Node 8 dan Node 12 dengan jarak 4.4 km
            
    addEdge(graph,9,6,2.2);                                             // Menambahkan Edge Antara Node 9 dan Node 6 dengan jarak 2.2 km
    addEdge(graph,9,7,3.1);                                             // Menambahkan Edge Antara Node 9 dan Node 7 dengan jarak 3.1 km
    addEdge(graph,9,11,4.6);                                            // Menambahkan Edge Antara Node 9 dan Node 11 dengan jarak 4.6 km
    addEdge(graph,9,8,2.3);                                             // Menambahkan Edge Antara Node 9 dan Node 8 dengan jarak 2.3 km
            
    addEdge(graph,10,7,4.7);                                            // Menambahkan Edge Antara Node 10 dan Node 7 dengan jarak 4.7 km
    addEdge(graph,10,11,5.6);                                           // Menambahkan Edge Antara Node 10 dan Node 11 dengan jarak 5.6 km
            
    addEdge(graph,11,10,5.6);                                           // Menambahkan Edge Antara Node 11 dan Node 10 dengan jarak 5.6 km
    addEdge(graph,11,7,3.7);                                            // Menambahkan Edge Antara Node 11 dan Node 7 dengan jarak 3.7 km
    addEdge(graph,11,9,4.6);                                            // Menambahkan Edge Antara Node 11 dan Node 9 dengan jarak 4.6 km
    addEdge(graph,11,8,5.1);                                            // Menambahkan Edge Antara Node 11 dan Node 8 dengan jarak 5.1 km
    addEdge(graph,11,12,6.3);                                           // Menambahkan Edge Antara Node 11 dan Node 12 dengan jarak 6.3 km
            
    addEdge(graph,12,8,4.4);                                            // Menambahkan Edge Antara Node 12 dan Node 8 dengan jarak 4.4 km
    addEdge(graph,12,11,6.3);                                           // Menambahkan Edge Antara Node 12 dan Node 11 dengan jarak 6.3 km

    seeGraph(graph);                                                    // Untuk Melihat Graph 

    return 0;
}
