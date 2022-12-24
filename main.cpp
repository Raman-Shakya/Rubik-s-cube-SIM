#include <iostream>
#include <string>
#include "cube.h"
#include "helper.h"
#include "rotations.h"
#include "edge_sticker_map.h"

#include "AI/method.h"

std::string play(Cube*);

int main() {
    srand(time(NULL));

    Cube Rubiks;

    set_color_palette();
    set_rotation_edge_map_data();

    std::cout << "THIS IS A RUBIK'S CUBE SIMULATION MADE IN C++\nBy: Raman Shakya\n\n";

    bool will_play;
    char temp;

    std::cout << "Do you wanna play? (Y/N) : ";
    std::cin >> temp;
    
    will_play = temp=='Y' ? true : false;
    
    while (1) {
        std::string scramble = generate_scramble(20);
        std::string solution;

        if (will_play) {
            Rubiks.scramble(scramble);
            solution = play(&Rubiks);
        }

        Rubiks.scramble(scramble);


        std::cout << "scramble : " << scramble << "\n";
        Rubiks.print_cube();
        solution = solve(&Rubiks, true);
        std::cout << "solution : \n" << solution;
        std::cout << "\nsolved in : " << count_moves(solution) << " moves\n";

        char next;
        std::cout << "next solution? (Y/N)";
        std::cin >> next;

        if (next=='N') break;

    }

    return 0;
}



std::string play(Cube *cube) {
    std::string solution="";
    cube->print_cube();
    while(true) {
        std::string move;
        std::cout << "enter move : ";
        std::cin >> move;
        cube->scramble(move);
        cube->print_cube();
        solution+=move+" ";
        if (cube->is_solved()) break;
    }
    std::cout << "you have solved the cube!\n";
    std::cout << "your solution is : \n" << solution;
    std::cout << "you solved in : " << count_moves(solution) << " moves\n";
    return solution;   
}