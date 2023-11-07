#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(std::vector<std::vector<int>>& board, int col, int n) {
    if (col == n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, n)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        printBoard(board);
    } else {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
