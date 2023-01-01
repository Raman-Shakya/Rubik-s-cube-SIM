#include <iostream>
#include <string>
#include <time.h>

#include "cube.h"
#include "helper.h"
#include "rotations.h"
#include "edge_sticker_map.h"

#include "AI/method.h"  // for AI

bool info_display();        // function to show first information
std::string play(Cube*);    // function for solving (humans)

int main() {
    srand(time(NULL));      // for randomizing pseudo random number generator based on time

    Cube Rubiks;            // instantiating cube

    // initial setups
    set_color_palette();
    set_rotation_edge_map_data();

    // if user will play or not
    bool will_play = info_display();

    // main loop
    while (1) {
        Rubiks.reset_to_solved_state();                     // resetting cube to solved state
        std::string scramble = generate_scramble(20);       // generating random scramble
        std::string solution;                               // variable to keep track of solution

        if (will_play) {    // user's turn to solve
            Rubiks.scramble(scramble);      // scrambling for user
            solution = play(&Rubiks);       // users' solution
        }

        // scrambling for AI
        Rubiks.scramble(scramble);

        std::cout << "scramble : " << scramble << "\n";                             // printing scramble
        Rubiks.print_cube();                                                        // printing cube_state
        solution = solve(&Rubiks, !will_play);                                      // letting AI solve

        std::cout << "scramble : " << scramble << "\n";                             // printing scramble
        std::cout << "solution : " << solution;                                     // printing solution
        std::cout << "\nsolved in : " << count_moves(solution) << " moves\n";       // counting moves

        // checking for next scramble
        char next;
        std::cout << "next solution? (Y/N) : ";
        std::cin >> next;

        if (next=='N' || next=='n') break;

    }

    return 0;
}



std::string play(Cube *cube) {
    std::string solution = "";   // solution will be recorded in this variable
    cube->print_cube();          // printing cube (scrambled)
    std::string move;            // temp_move

    // loops until user solves the cube
    while(true) {
        // asking for user to enter their move
        std::cout << "enter move : ";
        std::cin >> move;

        cube->scramble(move);   // performing move (move can be scramble too)
        cube->print_cube();     // printing cube after performing the move
        solution += move + " "; // appending move in solution
        if (cube->is_solved()) break;   // if cube is solved
    }
    // solved message
    std::cout << "you have solved the cube!\n";
    std::cout << "your solution is : \n" << solution;
    std::cout << "you solved in : " << count_moves(solution) << " moves\n";
    return solution;   
}


bool info_display () {
    std::cout << "THIS IS A RUBIK'S CUBE SIMULATION MADE IN C++\nBy: Raman Shakya\n\n";

    bool will_play;
    char temp;

    std::cout << "If you want to solve press Y, if you want the AI to solve press N: ";
    std::cin >> temp;
    
    return (temp=='Y' || temp=='y') ? true : false;
}