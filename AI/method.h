#pragma once

#include "../cube.h"
#include "EO.h"
#include "cross.h"
#include "belt.h"
#include "f2l.h"
#include "oll.h"

#include <vector>

/*
    TODO:
        0- orient all edges                 -1
        1- solve cross                      -1
        2- solve belt                       -1
        3- solve first layer corners        -0
        4- solve OLL                        -0
        5- solve corners                    -0
        6- solve edges                      -0
*/

class AI {
public:
private:

};

std::vector<std::string> available_moves = {"R ","L ","U ","D ","F ","B ",
                                            "R'","L'","U'","D'",
};




void solve(Cube *cube) {
    std::string temp="";
    
    // SOLVING EO
    temp = solve_EO(cube, 7);
    std::cout << "EO soln: " << temp << "\n";
    cube->scramble(temp);
    cube->print_cube();

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

    // solving Belt
    temp = solve_Belt(cube, 5);
    cube->scramble(temp);
    std::cout << "belt soln: " << temp << "\n";
    cube->print_cube();

    // solving F2L
    temp = solve_f2l(cube);
    cube->scramble(temp);
    std::cout << "f2l soln: " << temp << "\n";
    cube->print_cube();

    // solving OLL
    temp = solve_OLL(cube, 4);
    cube->scramble(temp);
    std::cout << "oll soln: " << temp << "\n";
    cube->print_cube();

}