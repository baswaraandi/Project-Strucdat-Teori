#include <iostream>
#include "struct.hpp"
#pragma once

// Perintah untuk membuat node baru dari List
ListNode* newListNode(int tujuan, float jarak){ 
	struct ListNode* newNode = 
	(struct ListNode*) malloc(sizeof(struct ListNode)); 
	
	newNode->tujuan = tujuan; 									// Mengisi variabel tujuan							
	newNode->jarak = jarak; 									// Mengisi variabel jarak 					
	newNode->bobot_total = jarak; 								// Mengisi variabel bobot_total
	newNode->next = nullptr;									// Inisialisasi pointer next = nullptr 
	
	return newNode; 											// Mengembalikan variabel newNode 
} 

// Perintah untuk membuat Graph dengan ukuran V
Graph* createGraph(int V){   
    // Mengalokasikan memori untuk graph
	struct Graph* graph = 
	(struct Graph*) malloc(sizeof(struct Graph));  
	
	graph->V = V;  												// Mengisi variabel V
	std::cout <<  sizeof(struct Dijkstra) << std::endl;
	// Perintah untuk membuat array dari list dengan ukuran V 
    graph->array = 
	(struct List*) malloc(V * sizeof(struct List)); 			// Perintah untuk membuat array dari list dengan ukuran V (???)
	
	 
    for (int i = 0; i < V; ++i){     							// Perintah untuk megkosongkan setiap head pada List (Struct List) 
		graph->array[i].head = nullptr;							 
	}
	
	return graph; 												// Mengembalikan variabel graph 
}


// Perintah untuk menambahkan edge  
void addEdge(struct Graph* graph, int asal, int tujuan, float jarak){ 
	// Menambahkan edge dari vertex(node) asal ke tujuan. Node baru ditambahkan ke list dari asal. node ditambahkan dibagian awal
	struct ListNode* newNode = 
	newListNode(tujuan, jarak);

	newNode->next = graph->array[asal].head;					// pointer untuk menunjuk head dari array
	graph->array[asal].head = newNode;							// Mencaari node, jika ketemu maka dimasukkan ke node pertama (head)
	
	// Selama graph belum terhubung, tambahkan add dari tujuan ke asal  
	newNode = newListNode(tujuan, jarak); 						// ???
	newNode->next = graph->array[tujuan].head;  				// ???
	graph->array[tujuan].head = newNode; 						// ???
} 

// Fungsi untuk mencetak jalur tersingkat bersama dengan nilai bobotnya
void cetakJalur(list& node, int awal, int akhir){   
	int prevNode;												// Variabel yang akan menyimpan node sebelumnya 
	prevNode = akhir;											// 
	if (node[akhir].path != -1){								// Jika nilai path di dalam node != 1 maka akan dicari jalurnya dengan cara mundur dari node tujuan (akhir) ke node awal
		std::cout << "Bobot (Jarak yang Ditempuh) : "; 
        std::cout << node[prevNode].jarak << " Km" << std::endl;
		std::cout << "Jalur Terpendek : ";
		while(node[prevNode].path  != -1){				 		// Selama path masih bernilai != -1 artinya node masih terhubung atau terdapat jalur
			std::cout << prevNode;
			std::cout << " <- ";
			prevNode = node[prevNode].path;						// Mengupdate prevNode dengan node yang ada di dalam path
		}
		if (node[akhir].path != -1){
			std::cout << prevNode << std::endl;
		}
	} else {													// Jika bernilai -1 artinya tidak terdapat jalur antara node awal ke node yang akhir
		std::cout << "Tidak terhubung!\n";
	}
}

// Fungsi untuk mencari jalur tersingkat 
void dijkstraTotal(struct Graph* graph, list& node, int N, int awal, int akhir){
	float bobot;
	int tujuan;
	int min, minNode;
	int first = awal;
	for (int i = 0; i < N ; ++i){								 										// Mereset semua nilai pada struct djikra setiap fungsi dijalankan
		node[i].visit = false;
		node[i].jarak = 999; 			// why ajig 
		node[i].path = -1;           
	}
	node[awal].jarak = 0;
	min = 0;
	while (min != 9999){                                                                        		// Looping untuk mengunjungi semua node(vertex)
		node[awal].visit = true;                                                                		// Membuat tanda bahwa node(vertex) 'awal' telah dikunjungi
		
		while(graph->array[awal].head != nullptr){                                                     	// looping untuk memeriksa semua node(vertex) yang terhubung dengan node(vertex) 'awal'
			tujuan = graph->array[awal].head->tujuan;                                                   // mengisi tujuan dengan node yang dituju pada list (???)
			//std::cout << tujuan << '\n';
			bobot = graph->array[awal].head->jarak;
			//std::cout << bobot << '\n';                                               		// Mengisi variabel 'bobot'dengan jarak
			if(node[tujuan].jarak > bobot + node[awal].jarak && node[tujuan].visit == false){ //10 >     		// Jika node(vertex) belum dikunjungi dan jarak di list lebih besar dari jumlah bobot dua node(vertex)
				node[tujuan].jarak = bobot + node[awal].jarak;                                    		// Memperbarui variabel 'jarak'
				node[tujuan].path = awal;   
				//std::cout << node[tujuan].jarak << std::endl;                                                    		// Memperbarui variabel 'path' dengan node sebelumnya 
			
			}
			graph->array[awal].head = graph->array[awal].head -> next;                                  // List terus bergerak sampai pointer bernilai 'nullptr'
		}
		min = 9999;                    					                                             	// Deklarasi variabel 'min' dengan angka terbesar (???)
		//std::cout << tujuan << '\n';

		for (int i = 0; i < N; ++i){                                                 					// Looping mencari jarak terkecil diantara semua node(vertex) yang belum dikunjungi
			if(node[i].visit == false && node[i].jarak < min){                       					// Jika node(vertex) yang ditunjuk belum dikunjungi dan nilai variabel 'jarak' < min
				min = node[i].jarak;                                                 					// Variabel 'min' berniali 'jarak' dari node(vertex) yang dituju
				minNode = i;                                                        					// Variabel minNode berniali 'i'
			}
		}
		awal = minNode;                                                             					// Variabel 'awal' akan berniali variabel 'minNode' mulai dari baris ini 
	}
	cetakJalur(node, awal, akhir);                                                 						// Menjalankan fungsi untuk mencetak jalur dan nilai
}