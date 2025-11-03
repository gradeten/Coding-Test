#include <bits/stdc++.h>
using namespace std;
int arr[105][105];

int rotate(int x1, int y1, int x2, int y2, int rows, int columns){
    int copy[105][105];
    int mn = 100000;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            copy[i][j] = arr[i][j];
        }
    }
    
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            if (i > x1 && i < x2 && j > y1 && j < y2) continue;
            else if (i < x2 && j == y1) arr[i][j] = copy[i+1][j];
            else if (i == x2 && j < y2) arr[i][j] = copy[i][j+1];
            else if (i > x1 && j == y2) arr[i][j] = copy[i-1][j];
            else if (i == x1 && j > y1) arr[i][j] = copy[i][j-1];
            mn = min(mn, arr[i][j]);
        }
    }
    
    return mn;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int num = 1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            arr[i][j] = num++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        answer.push_back
            (rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3], 
                    rows, columns));
    }
    
    return answer;
}