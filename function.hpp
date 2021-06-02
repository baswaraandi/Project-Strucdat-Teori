#include <iostream>
#include "struct.hpp"
#pragma once

// Perintah untuk membuat node baru dari List
ListNode* newListNode(int tujuan, int jarak, int tkt_kemacetan) { 
	struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode)); 
	newNode->tujuan = tujuan; 
	newNode->jarak = jarak; 
	newNode->tkt_kemacetan = tkt_kemacetan; //
	newNode->bobot_total = (jarak * tkt_kemacetan); //
	newNode->next = NULL; 
	return newNode; 
} 

// Perintah untuk membuat Graph dengan ukuran V
Graph* createGraph(int V){   
    // Mengalokasikan memori untuk graph
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));  
	graph->V = V; 
	// Perintah untuk membuat array dari list dengan ukuran V 
    graph->array = (struct List*) malloc(V * sizeof(struct List)); 
    for (int i = 0; i < V; ++i)     // perintah untuk megkosongkan setiap head list 
		graph->array[i].head = NULL; 
	return graph; 
}

// Perintah untuk menambahkan edge 
void addEdge(struct Graph* graph, int asal, int tujuan, float jarak, int tkt_kemacetan){  //
	// Menambahkan edge dari vertex asal ke tujuan. Node baru ditambahkan ke list dari asal. node ditambahkan dibagian awal
	struct ListNode* newNode = newListNode(tujuan, jarak, tkt_kemacetan); // 
	newNode->next = graph->array[asal].head; 
	graph->array[asal].head = newNode; 
	// Selama graph belum terhubung, tambahkan add dari tujuan ke asal  
	newNode = newListNode(tujuan, jarak, tkt_kemacetan); //
	newNode->next = graph->array[tujuan].head; 
	graph->array[tujuan].head = newNode; 
} 

// Fungsi untuk mencetak jalur tersingkat bersama dengan nilai bobotnya
void cetakJalur(list& node, int awal, int akhir){   
	int prevNode;										//variabel yang akan menyimpan node sebelumnya 
	prevNode = akhir;
	if (node[akhir].path != -1){						//Jika nilai path di dalam node != 1 maka akan dicari jalurnya dengan cara mundur dari node tujuan (akhir) ke node awal
		std::cout << "Bobot (Jarak yang Ditempuh) : "; 
        std::cout << node[prevNode].jarak << std::endl;
		std::cout << "Jalur Terpendek : ";
		while(node[prevNode].path  != -1){				//selama path masih bernilai != -1 artinya node masih terhubung atau terdapat jalur
			std::cout << prevNode;
			std::cout << " <- ";
			prevNode = node[prevNode].path;				//mengupdate prevNode dengan node yang ada di dalam path
		}
		if (node[akhir].path != -1){
			std::cout << prevNode << std::endl;
		}
	} else {											//jika bernilai -1 artinya tidak terdapat jalur antara node awal ke node yang akhir
		std::cout << "Tidak terhubung!\n";
	}
}

void dijkstraTotal(struct Graph* graph, list& node, int N, int awal, int akhir){
	float bobot;
	int tujuan;
	int min, minNode;
	int first = awal;
	for (int i = 0; i < N ; ++i){	//mereset semua nilai pada struct djikra setiap fungsi dijalankan
		node[i].visit = false;
		node[i].jarak = 999;
		node[i].path = -1;           
	}
	node[awal].jarak = 0;
	min = 0;
	while (min != 9999){                                                                        //looping untuk mengunjungi semua node
		node[awal].visit = true;                                                                //membuat tanda bahwa node ini sudah dikunjungi
		while(graph->array[awal].head != NULL){                                                     //looping untuk mengecek semua node yang terhubung dengan node awal
			tujuan = graph->array[awal].head->tujuan;                                                     //mengisi tujuan dengan node yang dituju pada list
			bobot = graph->array[awal].head->bobot_total;                                                    //mengisi dengan nilai bobot yang merupakan hasil kali antara jarak dan tingkat kemacetan
			if(node[tujuan].jarak > bobot + node[awal].jarak && node[tujuan].visit == false){     //jika node belum dikunjungi dan jarak di list lebih besar dari jumlah bobot dua node
				node[tujuan].jarak = bobot + node[awal].jarak;                                    //mengupdate jarak dengan jumlah dari dua node
				node[tujuan].path = awal;                                                       //mengupdate path dengan node sebelumnya 
			}
			graph->array[awal].head = graph->array[awal].head -> next;                                         //list akan terus bergerak sampai pointer bernilai null
		}
		min = 9999;                                                                 //deklarasi nilai minimal dengan angka terbesar
		for (int i = 0; i < N; ++i){                                                 //looping mencari jarak terkecil diantara semua node yang masih belum dikunjungi
			if(node[i].visit == false && node[i].jarak < min){                       //jika node yang ditunjuk belum dikunjungi dan memiliki jarak < min
				min = node[i].jarak;                                                 //min menjadi jarak dari node yang dituju
				minNode = i;                                                        //i akan menjadi minNode untuk ditelusuri selanjutnya
			}
		}
		awal = minNode;                                                             //min node dari looping tadi diisikan ke variabel awal untuk ditelusuri 
	}
	cetakJalur(node, awal, akhir);                                                 //menjalankan fungsi untuk mencetak jalur dan nilai
}