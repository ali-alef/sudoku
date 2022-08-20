#include <bits/stdc++.h>

using namespace std;

#define N 9

void print(int ted[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << ted[i][j] << " ";
        cout << endl;
    }
}

bool isok(int ted[N][N], int x, int y, int num){
    
    for(int i = 0; i < 9; i++){
        if(ted[x][i] == num)
            return false;
    }

    for(int i = 0; i < 9; i++){
        if(ted[i][y] == num)
            return false;
    }
    
    x -= x % 3;
    y -= y % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(ted[x + i][y + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(int ted[N][N], int x, int y){

    if(x == N - 1 and y == N)
        return true;

    if(y == N){
        x++;
        y = 0;
    }

    if(ted[x][y] > 0)
        return solve(ted, x, y + 1);

    for(int i = 1; i < 10; i++){
        if(isok(ted, x, y, i)){
            ted[x][y] = i;

            if(solve(ted, x, y + 1))
                return true;
        }
        ted[x][y] = 0;
    }
    return false;
}

int main(){
    
    int ted[N][N];

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cin >> ted[i][j];
    }
    
    cout << endl;

    if(solve(ted, 0, 0))
        print(ted);
    else
        cout << -1 << endl;
}
