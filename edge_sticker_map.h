#pragma once

#include <map>
#include <vector>

std::map<char, std::vector<std::vector<int>>> rotation_edge_map;
std::map<char, std::vector<int>> center_coor;

void set_rotation_edge_map_data() {
    rotation_edge_map['F'] = {
        {2,3, 2,4, 2,5},
        {3,6, 4,6, 5,6},
        {6,5, 6,4, 6,3},
        {5,2, 4,2, 3,2},
    };
    rotation_edge_map['R'] = {
        {5,5, 4,5, 3,5},
        {2,5, 1,5, 0,5},
        {3,9, 4,9, 5,9},
        {8,5, 7,5, 6,5}
    };
    rotation_edge_map['L'] = {
        {5,3, 4,3, 3,3},
        {8,3, 7,3, 6,3},
        {3,11, 4,11, 5,11},
        {2,3, 1,3, 0,3},
    };
    rotation_edge_map['U'] = {
        {3,5, 3,4, 3,3},
        {3,2, 3,1, 3,0},
        {3,11, 3,10, 3,9},
        {3,8, 3,7, 3,6}
    };
    rotation_edge_map['D'] = {
        {5,3, 5,4, 5,5},
        {5,6, 5,7, 5,8},
        {5,9, 5,10, 5,11},
        {5,0, 5,1, 5,2},
    };
    rotation_edge_map['B'] = {
        {3,8, 4,8, 5,8},
        {0,3, 0,4, 0,5},
        {5,0, 4,0, 3,0},
        {8,5, 8,4, 8,3},
    };

    center_coor['F'] = {4,4};
    center_coor['B'] = {4,10};
    center_coor['R'] = {4,7};
    center_coor['L'] = {4,1};
    center_coor['U'] = {1,4};
    center_coor['D'] = {7,4};
}