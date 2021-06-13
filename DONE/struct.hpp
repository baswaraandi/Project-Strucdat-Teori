#include<iostream>
#pragma once

// Struct untuk merepresentasikan Node di dalam List
struct ListNode {
	int tujuan; 					
	float jarak;
	ListNode* next;      			// Pointer yang menyambungkan setiap Vertex(node)
}; 	

// Struct untuk List
struct List {
	struct ListNode *head;      	// Deklarasi pointer head untuk list
}; 

// Struct untuk Graph	
struct Graph { 
    int V; 
	struct List *array;         	// Pointer untuk menyambungkan array
}; 

// Struct untuk Dijkstra
struct Dijkstra {
	bool visit;                     // Menyimpan status sudah dikunjungi atau belum
	float jarak;                    // Menyimpan jarak tersingkat
	int path;                       // Menyimpan Vertex(node) sebelumnya
};

// Membuat array dari struct Dijkstra dengan nama list dan ukuran sesuai dengan jumlah node(vertex)
typedef Dijkstra list[13]; 	

// Membuat variabel ptrListNode dari Struct ListNode
typedef ListNode* ptrListNode;

// Membuat variabel ptrGraph dari Struct Graph
typedef Graph* ptrGraph; 