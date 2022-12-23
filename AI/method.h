#pragma once
#include "../cube.h"
#include "EO.h"
#include "cross.h"
#include "f2l.h"

// #include "Thistlethwaite_G2.h"
#include <vector>

/*
    TODO:
        0- orient all edges
        1- solve cross
        2- solve 1 f2l pair
        3- solve all of f2l
        4- orient yellow cross
        5- permute yellow cross
        6- permute yellow corners
        7- orient yellow corners
*/

class AI {
public:
private:

};

std::vector<std::string> available_moves = {"R ","L ","U ","D ","F ","B ",
                                            "R'","L'","U'","D'",
};




void solve(Cube *cube) {
    std::string solution = "";
    std::string temp="";
    
    // SOLVING EO
    solution = solve_EO(cube, 7);
    std::cout << "EO soln: " << solution << "\n";
    cube->scramble(solution);
    cube->print_cube();

    // // To domino reduction Thistlethwaite's 52 move algo, 2nd part
    // std::string temp = solve_G2(cube, 10);
    // std::cout << "G2 soln: " << temp << "\n";
    // cube->print_cube();


    // SOLVING DAISY
    temp = solve_Daisy(cube, 7);
    std::cout << "daisy soln: " << temp << "\n";
    cube->scramble(temp);
    cube->print_cube();
    // SOLVING CROSS pt2
    temp = solve_Cross(cube, 5);
    cube->scramble(temp);
    std::cout << "Cross soln: " << temp << "\n";
    cube->print_cube();

    // // solving f2l
    // temp = solve_pair_1(cube, 12);
    // cube->scramble(temp);
    // std::cout << "Cross+1 soln: " << temp << "\n";
    // cube->print_cube();
    // solution+=temp;

}