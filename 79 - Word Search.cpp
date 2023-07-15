#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool search(string& word, vector<vector<char>>& board, int x, int y, int index) {
        //std::cout << word[index] << "\n";
        int width = board[0].size();
        int height = board.size();

        if (index >= word.length()) {
            return true;
        }

        if (x < 0 || x >= width || y < 0 || y >= height || word[index] != board[y][x]) {
            return false;
        }

        char temp = board[y][x];
        board[y][x] = '$';

        //Try every direction
        if (search(word, board, x + 1, y, index + 1) || search(word, board, x - 1, y, index + 1) || search(word, board, x, y + 1, index + 1) || search(word, board, x, y - 1, index + 1)) {
            return true;
        }
        else {
            board[y][x] = temp;
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int l = word.length();
        if (m * n < l)
            return false;
        //Search grid
        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                char c = board[j][i];
                if (c == word[0]) {
                    if (search(word, board, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};