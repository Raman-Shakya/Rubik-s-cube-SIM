#include <iostream>
#include <string>
#include "cube.h"
#include "helper.h"
#include "rotations.h"
#include "edge_sticker_map.h"



int main() {

    Cube Rubiks;

    set_color_palette();
    set_rotation_edge_map_data();
    

    scramble(&Rubiks, "U' F' R' B2 L' F2 L' D2 L D2 U2 B2 R B2 F' D2 U' L2 D B U2");

    Rubiks.print_cube();

    int move_cnt = 0;

    while(true) {
        std::string move;
        std::cout << "enter move : ";
        std::cin >> move;
        scramble(&Rubiks, move);
        Rubiks.print_cube();
        move_cnt++;
        if (Rubiks.is_solved()) break;
    }
    std::cout << "congratzzz u have solveedd thee cubeeee in " << move_cnt << "moves, take some rest now :P\n";

    return 0;
}