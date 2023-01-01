#pragma once

#include "../cube.h"
#include "../helper.h"

#include "EO.h"
#include "cross.h"
#include "belt.h"
#include "f2l.h"
#include "oll.h"
#include "pll.h"

#include <vector>

/*
    TODO:
        0- orient all edges                 -1
        1- solve cross                      -1
        2- solve belt                       -1
        3- solve first layer corners        -1
        4- solve OLL                        -1
        5- solve corners                    -1
        6- solve edges                      -1
YEYYY CUBE SOLVEDDD!!!
*/


// function to solve the cube by AI
std::string solve(Cube *cube, bool show_steps) {
    std::string temp="", solution="";
    Cube dummy(*cube);  // dummy cube to not overwrite the original cube
    
    // SOLVING EO
    temp = solve_EO(&dummy, 7);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "EO soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // SOLVING DAISY
    temp = solve_Daisy(&dummy, 7);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "daisy soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // SOLVING CROSS pt2
    temp = solve_Cross(&dummy, 6);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "Cross soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // solving Belt
    temp = solve_Belt(&dummy, 5);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "belt soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // solving F2L
    temp = solve_f2l(&dummy);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "f2l soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // solving OLL
    temp = solve_OLL(&dummy, 4);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "oll soln: " << temp << "\n";
        dummy.print_cube();
    }
    solution+=temp;

    // solving PLL
    temp = solve_PLL(&dummy, 2);
    dummy.scramble(temp);
    if (show_steps) {
        std::cout << "pll soln: " << temp << "\n";
        dummy.print_cube();    
    }
    solution+=temp;

    return cleanify(solution);  // goto helper.h for more abt cleanify
}