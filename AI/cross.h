#pragma once

#include "../cube.h"
#include <string>

/*
    CROSS: is the state in cube where all the 4 (white in this case) edges are solved
    ALGO HERE:
        solving Daisy first
        solving rest of cube later
*/

// returns true if the character is 'W' or 'Y', just is a bit helpful :P
bool is_WY(char a) {
    return a=='W' || a=='Y';
}


// daisy solved or not??
bool is_daisy_solved(Cube *cube) {
    if (
        cube->grid[6][4]=='W' &&
        cube->grid[7][5]=='W' &&
        cube->grid[7][3]=='W' &&
        cube->grid[8][4]=='W'
    )  return true;
    return false;
}


// cross solved!???
bool is_Cross_solved(Cube *cube) {
    if (
        cube->coor_is_solved(0,4) &&
        cube->coor_is_solved(1,5) &&
        cube->coor_is_solved(2,4) &&
        cube->coor_is_solved(1,3) &&

        cube->coor_is_solved(3,1) &&
        cube->coor_is_solved(3,4) &&
        cube->coor_is_solved(3,7) &&
        cube->coor_is_solved(3,10)
    )  return true;
    return false;
}


// function to solve Daisy (DFS)
std::string solve_Daisy(Cube *cube, int depth) {
    // base Case (either daisy solved or depth limit exceeded)
    if (is_daisy_solved(cube)) return " ";
    if (depth==0) return "";

    // perform these moves and use recursion/DFS to solve until Daisy solved
    for (std::string move: {"R ","L ","U ","D ","R'","L'","U'","D'","R2","L2"}) {
        Cube temp(*cube);
        temp.move(move);
        std::string temp_soln = solve_Daisy(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+temp_soln;   // backtracking
    }

    return "";  // solution not found
}


// function to solve cross (DFS)
std::string solve_Cross(Cube *cube, int depth) {
    // base case (either cross solved or depth limit exceeded)
    if (is_Cross_solved(cube)) return " ";
    if (depth==0) return "";

    Cube temp2(*cube);
    // prefix R2 D moves (guiding DFS)
    temp2.move("R2");
    temp2.move("D");

    // try for all U layer moves
    for (std::string move: {"","U ","U'","U2"}) {
        Cube temp(temp2);
        if (move!="") temp.move(move);
        std::string temp_soln = solve_Cross(&temp, depth-1);
        if (temp_soln.length()!=0) return "R2 D "+move+" "+temp_soln;   // backtracking
    }

    return "";  // solution not found

}