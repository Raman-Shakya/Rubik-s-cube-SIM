#pragma once

#include "../cube.h"

bool is_pll_C_solved(Cube *cube) {
    if (
        cube->grid[5][3]==cube->grid[5][5] &&
        cube->grid[5][9]==cube->grid[5][11]
    ) return true;
    return false;
}

bool is_pll_E_solved(Cube *cube) {
    if (
        cube->grid[5][3]==cube->grid[5][4] && cube->grid[5][4]==cube->grid[5][5] &&
        cube->grid[5][6]==cube->grid[5][7] && cube->grid[5][6]==cube->grid[5][8]
    ) return true;
    return false;
}


std::string solve_PLL_C(Cube *cube, int depth) {
    if (is_pll_C_solved(cube)) return " ";
    if (depth==0) return "";
    
    std::string Aperm = "L2 B2 L F L' B2 L F' L";
    for (std::string move: {"","D ","D'","D2"}) {
        Cube temp(*cube);
        if (move!="") temp.move(move);
        temp.scramble(Aperm);
        std::string temp_soln = solve_PLL_C(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+Aperm+" "+temp_soln;
    }

    return "";

}


std::string solve_PLL_E(Cube *cube, int depth) {
    if (is_pll_E_solved(cube)) return " "; 
    if (depth==0) return "";
    
    std::string Uperm = "R' D R' D' R' D' R' D R D R2";
    for (std::string move: {"","D ","D'","D2"}) {
        Cube temp(*cube);
        if (move!="") temp.move(move);
        temp.scramble(Uperm);
        std::string temp_soln = solve_PLL_E(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+Uperm+" "+temp_soln;
    }

    return "";
}

std::string align_D(Cube *cube) {
    for (std::string setup: {"D ","D'","D2"}) {
        Cube temp(*cube);
        temp.move(setup);
        if (temp.is_solved()) return setup;
    }
    return "";
}

std::string solve_PLL(Cube *cube, int depth) {
    Cube temp(*cube);
    std::string solution="";
    solution = solve_PLL_C(cube,depth);
    temp.scramble(solution);
    
    std::string temp_soln = solve_PLL_E(&temp, depth);
    solution += temp_soln;
    temp.scramble(temp_soln);

    return solution + align_D(&temp);
}