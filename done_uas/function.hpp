#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include "struct.hpp"
#pragma once

// ======================================================
//                    FUNGSI GRAPH
// ======================================================
// Perintah untuk membuat node baru dari List
ListNode* newListNode(int tujuan, float jarak){ 
	ListNode* newNode = new ListNode; 							 										// Mengalokasikan memori untuk graph 
	newNode->tujuan = tujuan; 									 	 									// Mengisi variabel tujuan	pada struct						
	newNode->jarak = jarak; 									 										// Mengisi variabel jarak	pada struct							 										// Mengisi variabel bobot_total
	newNode->next = nullptr;									 										// Inisialisasi pointer next = nullptr 
	
	return newNode; 											 										// Mengembalikan variabel newNode 
} 

// Perintah untuk membuat Graph dengan ukuran V
Graph* createGraph(int V){   
	Graph* graph = new Graph;									 										// Mengalokasikan memori untuk graph
	graph->V = V;  												 										// Mengisi variabel V

	// Perintah untuk membuat array dari list dengan ukuran V
	graph->array = new List[V];  								 										
	 
    for (int i = 0; i < V; ++i){     							 										// Perintah untuk megkosongkan setiap head pada List (Struct List) 
		graph->array[i].head = nullptr;							 
	}
	
	return graph; 														 	 							// Mengembalikan variabel graph 
}

// Perintah untuk menambahkan edge  
void addEdge(struct Graph* graph, int asal, int tujuan, float jarak){ 
	// Menambahkan edge dari vertex(node) asal ke tujuan. Node baru ditambahkan ke list dari asal. node ditambahkan dibagian awal
	ListNode* newNode = newListNode(tujuan, jarak);

	// Insert First
	newNode->next = graph->array[asal].head;					 										// pointer untuk menunjuk head dari array
	graph->array[asal].head = newNode;							 										// Mencaari node, jika ketemu maka dimasukkan ke node pertama (head)
} 

// Fungsi untuk melihat List pada Graph pada setiap Vertex
void seeGraph(Graph* graph){
	for(int i = 1; i < graph->V; ++i){
		ListNode* pBantu = graph->array[i].head; 				 					 	 				// Membuat pointer pBantu

		std::cout << "Vertex " << i << ": " << std::endl; 		 					 		 			// Output setiap vertex
		std::cout << "Head"; 									 					 	  	 			// Pemisalan Head dari List 
		
		while (pBantu != nullptr){
			std::cout << " -> (" << pBantu->jarak << ")" << pBantu->tujuan; 		 	 	 	 		// Output setiap Node pada List
			pBantu = pBantu->next; 
		}
		std::cout << '\n';
	}
}

// ======================================================
//                    FUNGSI DIJKSTRA
// ======================================================

// Fungsi nama Vertex yang akan digunakan pada fungsi cetakRute
void namaPariwisata(int jalur){
	if(jalur == 1){
		std::cout << "[1] Bandara Ahmad Yani" << " ";	
	}else if(jalur == 2){
		std::cout << "[2] Taman Lele & Candi Tugu" << " ";

	}else if(jalur == 3){
		std::cout << "[3] Pantai Marina & Taman Rekreasi Marina" << " ";

	}else if(jalur == 4){
		std::cout <<  "[4] Museum Ronggowarsito" << " ";

	}else if(jalur == 5){
		std::cout << "[5] Sam Poo Kong" << " ";

	}else if(jalur == 6){
		std::cout << "[6] Museum Mandala Bhakti & Lawang Sewu" << " ";

	}else if(jalur == 7){
		std::cout << "[7] Gereja Blenduk, Waroeng Semawis, dan Kelenteng Tay Kak Sie" << " ";

	}else if(jalur == 8){
		std::cout << "[8] Wonderia" << " ";

	}else if(jalur == 9){
		std::cout << "[9] Simpang Lima" << " ";
		
	}else if(jalur == 10){
		std::cout << "[10] Museum Jamu Nyonya Meneer" << " ";

	}else if(jalur == 11){
		std::cout << "[11] Masjid Agung Jawa Tengah dan Museum Perkembangan Islam Jawa Tengah" << " ";

	}else if(jalur == 12){
		std::cout << "[12] Water Blaster & Graha Candi Golf" << " ";

	}
}

// Fungsi untuk mencetak rute tersingkat bersama dengan nilai bobotnya (jarak tempuh)
void cetakRute(list& node, int awal, int akhir){   
	int prevNode;																 		  				// Variabel yang akan menyimpan node sebelumnya 
	int jalur[12];
	int i;
	std::string namaPar;
	prevNode = akhir;
	if (node[akhir].path != -1){									 			 	 	  		 		// Jika nilai path di dalam node != 1 maka akan dicari jalurnya dengan cara mundur dari node tujuan (akhir) ke node awal
		std::cout << "Rute Tercepat 	: ";
		i = 0;

		while(node[prevNode].path  != -1){				 			 			 	 	 	 	 	 	// Selama path masih bernilai != -1 artinya node masih terhubung atau terdapat jalur
			jalur[i] = prevNode;
			prevNode = node[prevNode].path;							 			 	 	 	 	 		// Mengupdate prevNode dengan node yang ada di dalam path
			i++;
		}
		if (node[akhir].path != -1){
			jalur[i] = prevNode;
		}

		namaPariwisata(jalur[i]);
		for (int j = (i-1); j >= 0; j--)
		{
			std::cout << " -> ";
			namaPariwisata(jalur[j]);
			 
		}
		std::cout << "\n";

		std::cout << "Jarak Tempuh 	: "; 
        std::cout << node[akhir].jarak << " Km" << std::endl;
	}else{														 	 		 	 	 	 	 		 	// Jika bernilai -1 artinya tidak terdapat jalur antara node awal ke node yang akhir
		std::cout << "Tidak terhubung!\n";
	}
}

// Fungsi untuk mencari jalur tersingkat 
void dijkstraTotal(struct Graph* graph, list& node, int N, int akhir){
	int awal = 1;
	float bobot;
	int tujuan;
	float min, minNode; 
	int first = awal;

	// Mereset semua nilai pada struct djikra setiap fungsi dijalankan
	for (int i = 0; i < N ; ++i){								 										
		node[i].visit = false; 		
		node[i].jarak = 999; 			  										 						
		node[i].path = -1;
	}
	node[awal].jarak = 0;
	min = 0;
	while (min != 9999){                                                                        		// Looping untuk mengunjungi semua node(vertex)
		node[awal].visit = true;                                                                		// Membuat tanda bahwa node(vertex) 'awal' telah dikunjungi
		
		while(graph->array[awal].head != nullptr){                                                     	// looping untuk memeriksa semua node(vertex) yang terhubung dengan node(vertex) 'awal'
			tujuan = graph->array[awal].head->tujuan;                                                   // mengisi tujuan dengan node yang dituju pada list (???)
			bobot = graph->array[awal].head->jarak;														// Mengisi variabel 'bobot'dengan jarak
	                                               		 
			if(node[tujuan].jarak > bobot + node[awal].jarak && node[tujuan].visit == false){    	    // Jika node(vertex) belum dikunjungi dan jarak di list lebih besar dari jumlah bobot dua node(vertex)
				node[tujuan].jarak = bobot + node[awal].jarak;                                    		// Memperbarui variabel 'jarak'
				node[tujuan].path = awal;    															// Memperbarui variabel 'path'
				
			}
			graph->array[awal].head = graph->array[awal].head -> next;                                  // List terus bergerak sampai pointer bernilai 'nullptr'
		}

		min = 9999;                    					                                             	// Deklarasi variabel 'min' dengan angka terbesar 

		for (int i = 0; i < N; ++i){                                                 					// Looping mencari jarak terkecil diantara semua node(vertex) yang belum dikunjungi
			if(node[i].visit == false && node[i].jarak < min){                       					// Jika node(vertex) yang ditunjuk belum dikunjungi dan nilai variabel 'jarak' < min
				min = node[i].jarak;                                                 					// Variabel 'min' berniali 'jarak' dari node(vertex) yang dituju
				minNode = i;                                                        					// Variabel minNode berniali 'i'
			}
		}
		
		awal = minNode;																					// Variabel 'awal' akan berniali variabel 'minNode' mulai dari baris ini
		                                                             					 
	}
	cetakRute(node, awal, akhir);                                                 						// Menjalankan fungsi untuk mencetak jalur dan nilai
}

// ======================================================
//  				FUNGSI INTERFACE                     
// ======================================================

void loading()
{
    
    char a = 177, b = 219;
    std::cout << "LOADING\t";
    for (int i = 0; i < 23; i++)
        std::cout << a;
        
    std::cout << "\r";
    std::cout << "\t";
    
    for (int i = 0; i < 23; i++) {
        std::cout << b;
        Sleep(20);
    }
    system("cls");
}

void map_semarang(){
        std::cout << "===================================================================" << std::endl;
        std::cout << "                  PETA DAERAH PARIWISATA SEMARANG                  " << std::endl;
        std::cout << "===================================================================" << std::endl;
        std::cout << "                                                                   " << std::endl;
        std::cout << "                  -[3]---------\\               /-----[10]      " << std::endl;
        std::cout << "                 /  |           \\             /       /         " << std::endl;
        std::cout << "          /--[1]/ /            [7]-----------/       /          " << std::endl;
        std::cout << "[2]------/    |  /             / \\          \\     /           " << std::endl;
        std::cout << " \\           |  /             /   \\          \\   /            " << std::endl;
        std::cout << "  \\          | /             /     \\          \\ /             " << std::endl;
        std::cout << "   \\--------[4]------------[6]-----[9]---------[11]            " << std::endl;
        std::cout << "               \\           / \\     /           /                  " << std::endl;                                            
        std::cout << "                \\---[5]---/   \\   /           /                   " << std::endl;
        std::cout << "                                [8]-------\\   /                    " << std::endl;
        std::cout << "                                           \\[12]                  " << std::endl;
        std::cout << "===================================================================" << std::endl;
}

void map(){
	std::cout << "===================================================================" << std::endl;
    std::cout << "                  PETA DAERAH PARIWISATA SEMARANG                  " << std::endl;
    std::cout << "===================================================================" << std::endl;
    std::cout << "                                                                   " << std::endl;
    std::cout << "                     [3]------------\\                " << std::endl;
    std::cout << "                     / |             \\                      [10]" << std::endl;
    std::cout << "                    /  |              \\-[7]------------------/" << std::endl;
    std::cout << "                   /   |                 / \\                /" << std::endl;
    std::cout << "       /----------[1]  |                /   \\              /" << std::endl;
    std::cout << "      /            \\   |               /     \\-----------[11]"<< std::endl;
    std::cout << "   [2]              \\  |              /      |           /"   << std::endl;
    std::cout << "      \\--------------[4]------------[6]-----[9]---/-----/   " << std::endl;                                            
    std::cout << "                       \\            / \\     |----/     /" << std::endl;
    std::cout << "                        \\          /   \\----[8]-/     /              " << std::endl;
    std::cout << "                         \\---[5]--/              \\   /                 " << std::endl;
    std::cout << "                                                  [12]          " << std::endl;
    std::cout << "===================================================================" << std::endl;

}


