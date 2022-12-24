#include <iostream>
#include <string>
#include "cube.h"
#include "helper.h"
#include "rotations.h"
#include "edge_sticker_map.h"

#include "AI/method.h"

int main() {

    Cube Rubiks;

    set_color_palette();
    set_rotation_edge_map_data();
    
    std::string scramble = "R2 D R F2 U' F' D2 L B2 L2 U R2 U' L2 F2 U2 F2 D F2 L";
    std::cout << scramble << "\n";

    Rubiks.scramble(scramble);
    Rubiks.print_cube();

    solve(&Rubiks);

    // int move_cnt = 0;

    // while(true) {
    //     std::string move;
    //     std::cout << "enter move : ";
    //     std::cin >> move;
    //     Rubiks.scramble(move);
    //     Rubiks.print_cube();
    //     move_cnt++;
    //     std::cout << (is_belt_solved(&Rubiks) ? "EO_SOLVED" : "EO_ISN't SOLVED") << std::endl;
    //     if (Rubiks.is_solved()) break;
    // }
    // std::cout << "congratzzz u have solveedd thee cubeeee in " << move_cnt << "moves, take some rest now :P\n";

    return 0;
}