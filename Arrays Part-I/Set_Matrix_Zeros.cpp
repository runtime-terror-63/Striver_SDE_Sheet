#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int rows, int cols, int rowIdx) {
    // set all non-zero elements as -1 in the row rowIdx:
    for (int j = 0; j < cols; j++) {
        if (matrix[rowIdx][j] != 0) {
            matrix[rowIdx][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int rows, int cols, int colIdx) {
    // set all non-zero elements as -1 in the col colIdx:
    for (int i = 0; i < rows; i++) {
        if (matrix[i][colIdx] != 0) {
            matrix[i][colIdx] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int rows, int cols) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, rows, cols, i);
                markCol(matrix, rows, cols, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, rows, cols);

    cout << "The Final matrix is: \n";
    for (auto row : ans) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }
    return 0;
}
