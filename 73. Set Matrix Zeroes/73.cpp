#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();

        bool firstrowflag = false;
        bool firstcolumnflag = false;

        // check first row
        for (int i = 0; i < column; i++) {
            if (matrix[0][i] == 0) {
                firstrowflag = true;
                break;
            }
        }
        // check first column
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstcolumnflag = true;
                break;
            }
        }

        // traverse matrix and mark first row and column
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // asign zero base of first row and column marking
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // check if there exist any zero in matrix row first
        if (firstrowflag) {
            for (int i = 0; i < column; i++) {
                matrix[0][i] = 0;
            }
        }
        // check if there exist any zero in matrix column first
        if (firstcolumnflag) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};