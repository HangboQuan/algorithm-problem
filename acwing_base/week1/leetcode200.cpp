//
// Created by quanhangbo on 2023/3/8 21:42.
//
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {

    // 边界条件
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
        return ;
    }

    grid[i][j] = '0';

    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    for (int i = 0; i < grid.size(); i ++ ) {
        for (int j = 0; j < grid[0].size(); j ++ ) {
            if (grid[i][j] == '1') {
                num ++;
                dfs(grid, i, j);
            }
        }
    }
    return num;
}

int main(void) {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '1', '1', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;
}