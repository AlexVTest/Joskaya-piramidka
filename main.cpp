//
//  main.cpp
//  joskaya-piramidka
//
//  Created by Alex on 9/8/16.
//  Copyright © 2016 Alex. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int maxOf(int, int);
int maxOf(int, int, int);

int main(void) {
    
    int temp;
    int col = 0;
    int row = 0;
    std::vector<int> vectOfNums;
    std::vector< std::vector<int> > vectOfRows;
    
    std::ifstream loadTriangle;
    loadTriangle.open("in.txt");
    while (loadTriangle >> temp) {
        vectOfNums.push_back(temp);
        if (col == row) {
            vectOfRows.push_back(vectOfNums);
            vectOfNums.clear();
            row++;
            col = 0;
        } else {
            col++;
        }
    }
    
    // DEBUG INPUT
    std::cout << "Input:" << std::endl;
    for (int row = 0; row < vectOfRows.size(); row++) {
        for (int col = 0; col < vectOfRows[row].size(); col++) {
            std::cout << vectOfRows[row][col] << " ";
        }
        std::cout << std::endl;
    }
    
    
    for (int row = 1; row < vectOfRows.size(); row++) {
        for (int col = 0; col < vectOfRows[row].size(); col++) {
            
            // Processing data
            if (col == 0 && row == 1) {
                vectOfRows[row][col] += vectOfRows[0][0];
            } else if (col == 0) {
                vectOfRows[row][col] += maxOf(vectOfRows[row-1][col], vectOfRows[row-1][col+1]);
            } else if (col == row-1) {
                vectOfRows[row][col] += maxOf(vectOfRows[row-1][col-1], vectOfRows[row-1][col]);
            } else if (col == row) {
                vectOfRows[row][col]+= vectOfRows[row-1][col-1];
            } else {
                vectOfRows[row][col] += maxOf(vectOfRows[row-1][col-1], vectOfRows[row-1][col], vectOfRows[row-1][col+1]);
            }
            
        }
    }
    
    
    // DEBUG OUTPUT
    std::cout << std::endl << "Output:" << std::endl;
    for (int row = 0; row < vectOfRows.size(); row++) {
        for (int col = 0; col < vectOfRows[row].size(); col++) {
            std::cout << vectOfRows[row][col] << " ";
        }
        std::cout << std::endl;
    }
    
    
    // Detect the MAX value
    std::vector<int> result = vectOfRows[vectOfRows.size()-1];
    std::sort(result.begin(), result.end());
    std::cout << std::endl << "RESULT IS: " << result[result.size()-1] << std::endl;
    
    return 0;
}

int maxOf(int a, int b) {
    int max = a;
    
    if (b > max) {
        max = b;
    }
    
    return max;
}

int maxOf(int a, int b, int c) {
    int max = a;
    
    if (b > max) {
        max = b;
    }
    
    if (c > max) {
        max = c;
    }
    
    return max;
}
