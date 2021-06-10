#include<iostream>
#pragma once

// Struct untuk merepresentasikan Node di dalam List
struct ListNode {
	int tujuan; 					
	float jarak;
	ListNode* next;      			// Pointer yang menyambungkan setiap node
}; 	

// Struct untuk List
struct List {
	struct ListNode *head;      	// Deklarasi pointer head untuk list
}; 

// Struct yang merepresentasikan graph, dimana graph merupakan array di dalam list, dengan ukuran array V (vertex/simpul)	
struct Graph { 
    int V; 
	struct List *array;         	// Pointer untuk menyambungkan array
}; 

struct Dijkstra {
	bool visit;                     // Menyimpan status sudah dikunjungi atau belum
	float jarak;                    // Menyimpan jarak tersingkat
	int path;                       // Menyimpan node(vertex) sebelumnya
};

// Membuat array dari struct Dijkstra dengan nama list dan ukuran sesuai dengan jumlah node(vertex)
typedef Dijkstra list[13]; 		     