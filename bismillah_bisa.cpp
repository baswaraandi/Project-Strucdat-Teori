/*
Kelompok            : 4
Anggota Kelompok    : Rangga Putra - 140810200007
                      Andyka Baswara Putra - 140810200061
Deskripsi           : 
Tanggal             :
*/

#include <iostream>
#include <stdlib.h>
#include "struct.hpp"
#include "function.hpp"
#include "interface.hpp"


int main(){
    int V = 13;  // Deklarasi nilai V = 13, artinya Graph berisi 12 vertex
    int asal, akhir, looping, salah;
    looping = 1;
    char pilih;
    list Node1, Node2;

    while (looping == 1){
        struct Graph* graph = createGraph(V); // Membuat Graph dengan Jumlah vertex V
        addEdge(graph,1,2,5,1);  // Menambahkan Edge Antara Node 1 dan Node 2 dengan jarak 5 km
        addEdge(graph,1,3,5,1);  // Menambahkan Edge Antara Node 1 dan Node 3 dengan jarak 5 km
        addEdge(graph,1,4,1,1);  // Menambahkan Edge Antara Node 1 dan Node 4 dengan jarak 1 km
        addEdge(graph,2,1,5,1);  // Menambahkan Edge Antara Node 2 dan Node 1 dengan jarak 5 km
        addEdge(graph,2,4,5,1);  // Menambahkan Edge Antara NOde 2 dan node 4 dengan jarak 5 km
        addEdge(graph,3,1,5,1);  // Menambahkan Edge Antara Node 3 dan Node 1 dengan jarak 5 km 
        addEdge(graph,3,4,5,1);  // Menambahkan Edge Antara Node 3 dan Node 4 dengan jarak 5 km 
        addEdge(graph,3,7,6,1);  // Menambahkan Edge Antara Node 3 dan Node 7 dengan jarak 6 km    
        addEdge(graph,4,1,1,1);  // Menambahkan Edge Antara Node 4 dan Node 1 dengan jarak 1 km
        addEdge(graph,4,5,4,1);  // Menambahkan Edge Antara Node 4 dan Node 5 dengan jarak 4 km 
        addEdge(graph,4,2,5,1);  // Menambahkan Edge Antara Node 4 dan Node 2 dengan jarak 5 km
		addEdge(graph,4,3,4,1);  // Menambahkan Edge Antara Node 4 dan Node 3 dengan jarak 4 km
		addEdge(graph,4,6,3,1);  // Menambahkan Edge Antara Node 4 dan Node 6 dengan jarak 3 km
		addEdge(graph,5,4,4,1);  // Menambahkan Edge Antara Node 5 dan Node 4 dengan jarak 4 km
		addEdge(graph,5,6,2,1);  // Menambahkan Edge Antara Node 5 dan Node 6 dengan jarak 2 km
		addEdge(graph,5,8,4,1);  // Menambahkan Edge Antara Node 5 dan Node 8 dengan jarak 4 km
		addEdge(graph,6,4,3,1);  // Menambahkan Edge Antara Node 6 dan Node 4 dengan jarak 3 km
		addEdge(graph,6,5,2,1);  // Menambahkan Edge Antara Node 6 dan Node 5 dengan jarak 2 km
		addEdge(graph,6,8,4,1);  // Menambahkan Edge Antara Node 6 dan Node 8 dengan jarak 4 km
		addEdge(graph,6,9,2,1);  // Menambahkan Edge Antara Node 6 dan Node 9 dengan jarak 2 km
		addEdge(graph,6,7,3,1);  // Menambahkan Edge Antara Node 6 dan Node 7 dengan jarak 3 km
		addEdge(graph,7,3,6,1);  // Menambahkan Edge Antara Node 7 dan Node 3 dengan jarak 6 km
		addEdge(graph,7,10,5,1); // Menambahkan Edge Antara Node 7 dan Node 10 dengan jarak 5 km
		addEdge(graph,7,11,4,1); // Menambahkan Edge Antara Node 7 dan Node 11 dengan jarak 4 km
		addEdge(graph,7,9,3,1);  // Menambahkan Edge Antara Node 7 dan Node 9 dengan jarak 3 km
		addEdge(graph,7,6,3,1);  // Menambahkan Edge Antara Node 7 dan Node 6 dengan jarak 3 km
		addEdge(graph,8,5,4,1);  // Menambahkan Edge Antara Node 8 dan Node 5 dengan jarak 4 km
		addEdge(graph,8,6,4,1);  // Menambahkan Edge Antara Node 8 dan Node 6 dengan jarak 4 km
		addEdge(graph,8,9,2,1);  // Menambahkan Edge Antara Node 8 dan Node 9 dengan jarak 2 km
		addEdge(graph,8,12,4,1); // Menambahkan Edge Antara Node 8 dan Node 12 dengan jarak 4 km
		addEdge(graph,9,6,2,1);  // Menambahkan Edge Antara Node 9 dan Node 6 dengan jarak 2 km
		addEdge(graph,9,7,3,1);  // Menambahkan Edge Antara Node 9 dan Node 7 dengan jarak 3 km
		addEdge(graph,9,11,5,1); // Menambahkan Edge Antara Node 9 dan Node 11 dengan jarak 5 km
		addEdge(graph,9,8,2,1);  // Menambahkan Edge Antara Node 9 dan Node 8 dengan jarak 2 km
		addEdge(graph,10,7,5,1); // Menambahkan Edge Antara Node 10 dan Node 7 dengan jarak 5 km
		addEdge(graph,10,11,6,1);// Menambahkan Edge Antara Node 10 dan Node 11 dengan jarak 6 km
		addEdge(graph,11,10,6,1);// Menambahkan Edge Antara Node 11 dan Node 10 dengan jarak 6 km
		addEdge(graph,11,7,4,1); // Menambahkan Edge Antara Node 11 dan Node 7 dengan jarak 4 km
		addEdge(graph,11,9,5,1); // Menambahkan Edge Antara Node 11 dan Node 9 dengan jarak 5 km
		addEdge(graph,11,8,5,1); // Menambahkan Edge Antara Node 11 dan Node 8 dengan jarak 5 km
		addEdge(graph,11,12,6,1);// Menambahkan Edge Antara Node 11 dan Node 12 dengan jarak 6 km
		addEdge(graph,12,8,4,1); // Menambahkan Edge Antara Node 12 dan Node 8 dengan jarak 4 km
		addEdge(graph,12,11,6,1);// Menambahkan Edge Antara Node 12 dan Node 11 dengan jarak 6 km
		
		
        system("cls");

		loading();

		map_semarang();

        salah = 1;
		asal = 1;
        while (salah == 1){
            std::cout << "Masukkan Nomor Kota Tujuan    : "; std::cin >> akhir;
            if( akhir < 1 || akhir > 12){
                std::cout << "Angka Salah !\n";
            }else{
                salah = 0;
            }
        }
        dijkstraTotal(graph, Node1, V, asal, akhir);
        std::cout << "\nLagi    ?(Y/N) "; std::cin >> pilih;
        
        if(pilih != 'y' && pilih != 'Y'){
            looping = 0;
        }
    }

    /*std::cout << "\n==========================" << std::endl;
    std::cout << "==       TERIMA KASIH    ==" << std::endl;
    std::cout << "===========================" << std::endl;
    */
    return 0;
}