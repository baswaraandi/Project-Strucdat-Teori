#include<iostream>
#pragma once

// Struct untuk merepresentasikan Node di dalam List
struct ListNode {
	int tujuan; 
	int jarak;
	float tkt_kemacetan; 		// 
	float bobot_total;
	ListNode* next;      		// Pointer yang menyambungkan setiap node
}; 

// Struct untuk List
struct List {
	struct ListNode *head;      // Deklarasi pointer head untuk list
}; 

// Struct yang merepresentasikan graph, dimana graph merupakan array di dalam list, dengan ukuran array V (vertex/simpul)	
struct Graph { 
    int V; 
	struct List* array;         // Pointer untuk menyambungkan array
}; 

struct Dijkstra {
	bool visit;                     //menyimpan status sudah dikunjungi atau belum
	float jarak;                    //menyimpan jarak tersingkat
	int path;                       //menyimpan node/vertex sebelumnya
};

// Membuat array dari struct dijkstra dengan nama list dan ukuran sesuai dengan jumlah vertex
typedef Dijkstra list['N'];