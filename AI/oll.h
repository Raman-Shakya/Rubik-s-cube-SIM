#pragma once

#include "../cube.h"

/*
    OLL: the state in which all last layer edges and corners are solved, or the last layer stickers is solved (not pieces)
*/

// oll solve!??
bool is_oll_solved(Cube *cube) {
    if (
        cube->coor_is_solved(6,3) &&
        cube->coor_is_solved(6,5) &&
        cube->coor_is_solved(8,3) &&
        cube->coor_is_solved(8,5)
    ) return true;
    return false;
}

// main function to solve OLL (DFS)
std::string solve_OLL(Cube *cube, int depth) {
    // base case (either oll solved or soln not found)
    if (is_oll_solved(cube)) return " ";
    if (depth==0) return "";
    
    std::string sune = "R' D' R D' R' D2 R";    // protagonist
    // just perfom sune until its solved not a big deal LOL
    for (std::string move: {"","D ","D'","D2"}) {
        Cube temp(*cube);
        if (move!="") temp.move(move);
        temp.scramble(sune);
        std::string temp_soln = solve_OLL(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+sune+" "+temp_soln;  // yey soln found!
    }

    return "";  // WTH! soln not found :'(

}