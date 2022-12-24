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
    
    std::string scramble = "D' B2 U2 R L B' D U2 R F2 L2 B2 L' U2 R' U2 R F2 R' D";
    std::cout << scramble << "\n";

    Rubiks.scramble(scramble);
    Rubiks.print_cube();

    std::cout << "scramble : " << scramble << "\n";
    std::cout << "solution : " << solve(&Rubiks, true) << "\n";

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