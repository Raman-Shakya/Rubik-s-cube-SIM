#pragma once

#include "../cube.h"
#include "../edge_sticker_map.h"

/*
    EO (Edge Orientation) orients all edges so that every of them can be solved using <R, L, U, D> moves to keep them in place
*/

// the coordinates where white, yellow, green, blue stickers are to be considered good edges
//    this is not always true for pieces with no white or green stickers
int EO_no_WYGB_spots[] ={
    3,1, 3,4, 3,7, 3,10,
    5,1, 5,4, 5,7, 5,10,
    4,6, 4,8, 4,0, 4,2,
};

// returns true if EO is solved
bool is_EO_solved(Cube *cube) {
    int a,b;
    
    for (int i=0; i<24; i+=2) {
        a = EO_no_WYGB_spots[i];
        b = EO_no_WYGB_spots[i+1];
        char temp_color = cube->grid[a][b];
        if (temp_color=='Y' || temp_color=='W') return false;
        // edge case, have to check for corresponding edge
        if (temp_color=='B' || temp_color=='G') {
            char temp_color_2 = cube->grid[connected_coor_edge[{a,b}][0]][connected_coor_edge[{a,b}][1]];
            if (temp_color_2=='O' || temp_color_2=='R') return false;
        }
    }
    return true;
}


// main method to solve EO (DFS) algorithm
std::string solve_EO(Cube *cube, int depth) {
    // base cases (either EO solved or depth limit exceeded)
    if (is_EO_solved(cube)) return " ";
    if (depth==0) return "";
    
    // perform one of the following move and use recursion/DFS to solve
    for (std::string move: {"L","R","F","B","U","D"}) {
        Cube temp(*cube);
        temp.move(move);
        std::string temp_soln = solve_EO(&temp, depth-1);
        if (temp_soln.length()!=0) return move+" "+temp_soln;   // backtracking
    }

    return "";  // solution not found

}