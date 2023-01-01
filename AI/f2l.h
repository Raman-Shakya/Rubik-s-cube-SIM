#pragma once

#include "../cube.h"

/*
    F2L: it is the state in which first 2 layers of the cube is solved
*/


// is there a white corner in bottom right hand (DFR) corner??
int is_white_in_position_C(Cube *cube) {
    // 1=> white is facing right
    // 2=> white is facing front
    // 3=> white is facing down
    // 0=>white is not in position
    if (cube->grid[5][6]=='W') return 1;
    if (cube->grid[5][5]=='W') return 2;
    if (cube->grid[6][5]=='W') return 3;
    return 0;
}

// is corner relatively solved?
bool is_corner_solved(Cube *cube) {
    return (cube->grid[3][5]==cube->grid[3][4]);
}

// solving corner (kinda brute-force ig)
std::string solve_corner(Cube *cube, std::string alg) {
    // move u layer do alg, if not solved, try again
    for (std::string setup: {"","U ","U'","U2"}) {
        Cube temp(*cube);
        if (setup!="") temp.move(setup);
        temp.scramble(alg);
        if (is_corner_solved(&temp)) return setup;
    }
    return alg;
}


// solves a corner
std::string solve_bottom_corners(Cube *cube) {
    for (std::string down_layer: {" ","D ","D'","D2"}) {
        Cube temp(*cube);
        if (down_layer!="  ") temp.move(down_layer);
        int position = is_white_in_position_C(&temp);
      
        if (position==0) continue;

        std::string alg="";

        // if white is in bottom right
        alg = " L' U L D' L' U' L ";
        if (position==1) return down_layer+" "+solve_corner(&temp, alg) + alg;

        // if white is in bottom front
        alg = " L U2 L' D2 L U2 L' ";
        if (position==2) return down_layer+" "+solve_corner(&temp, alg) + alg;

        // if white is in bottom
        alg = " R' D' R D R' D' R D R' D' R ";
        if (position==3) return down_layer+" "+solve_corner(&temp, alg) + alg;
    }
    return "";
}

// align the first layer
std::string align_layer(Cube *cube) {
    for (std::string setup: {"U ","U'","U2"}) {
        Cube temp3(*cube);
        temp3.move(setup);
        if (temp3.grid[3][4]==temp3.grid[4][4]) return setup;
    }
    return "";
}

// main function to solve the F2L
std::string solve_f2l(Cube *cube) {
    std::string solution;
    Cube temp(*cube);

    // solve all the bottom corners first
    for (int i=0; i<4; i++) {
        std::string temp_soln = solve_bottom_corners(&temp);
        if (temp_soln=="") break;
        temp.scramble(temp_soln);
        solution += temp_soln;
    }
    // if m reading here, I didn't find a solution so, do U moves where I find white corner and do any 1 commutator algo and repeat the process
    for (std::string setup: {"","U ","U'","U2"}) {
        Cube temp2(temp);
        temp2.move(setup);
        if (!is_corner_solved(&temp2)) {
            std::string temp_alg = "L U2 L' D2 L U2 L' ";
            solution += setup + " " + temp_alg;
            temp2.scramble(temp_alg);
            solution += solve_f2l(&temp2);  // using recursion :sunglasses: lol
            break;
        }
    }
    Cube temp2(*cube);
    temp2.scramble(solution);
    return solution + align_layer(&temp2);  // finally aligning first layer
}