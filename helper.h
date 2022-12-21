#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>


std::map<char, std::string> color_palette;


void set_color_palette() {
    color_palette['R'] = "\033[1;31m█\033[0m";
    color_palette['G'] = "\033[1;32m█\033[0m";
    color_palette['Y'] = "\033[1;33m█\033[0m";
    color_palette['B'] = "\033[1;34m█\033[0m";
    color_palette['W'] = "\033[1;37m█\033[0m";
    color_palette['O'] = "\033[1;38;5;208m█\033[0m";
    color_palette[' '] = " ";
}



void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
