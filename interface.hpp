#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#pragma once

void loading()
{
    system("cls");
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
        std::cout << "                  -[3]---------.              /----------[10]      " << std::endl;
        std::cout << "                 /  |           .            /           /         " << std::endl;
        std::cout << "          /--[1]/  /            [7]---------/           /          " << std::endl;
        std::cout << "[2]------/    |   /             / .         .          /           " << std::endl;
        std::cout << " .            |  /             /   .         . ----   /            " << std::endl;
        std::cout << "  .           | /             /     .              . /             " << std::endl;
        std::cout << "   .---------[4]------------[6]-----[9]------------[11]            " << std::endl;
        std::cout << "              .             / .     /               /              " << std::endl;                                            
        std::cout << "               .----[5]----/   .   /               /               " << std::endl;
        std::cout << "                                [8]-------.       /                " << std::endl;
        std::cout << "                                           .[12] /                 " << std::endl;
        std::cout << "===================================================================" << std::endl;
}