#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
main(){
    vector<vector<float> > matrix(100);
    for ( int i = 0 ; i < 100 ; i++ ){
        matrix[i].resize(50);
    }
    matrix[0][0] = 3;
    matrix[0][1] = 2;
    matrix[0][2] = 5;
    matrix[0][3] = 1;
    matrix[0][11] = 55;
    matrix[1][0] = 2;
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[1][4] = 1;
    matrix[1][11] = 26;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 3;
    matrix[2][5] = 1;
    matrix[2][11] = 30;
    matrix[3][0] = 5;
    matrix[3][1] = 2;
    matrix[3][2] = 4;
    matrix[3][6] = 1;
    matrix[3][11] = 57;
    matrix[4][0] = 1;
    matrix[4][1] = 0;
    matrix[4][2] = 0;
    matrix[4][7] = -1;
    matrix[4][11] = 0;
    matrix[5][0] = 0;
    matrix[5][1] = 1;
    matrix[5][2] = 0;
    matrix[5][8] = -1;
    matrix[5][11] = 0;
    matrix[6][0] = 0;
    matrix[6][1] = 0;
    matrix[6][2] = 1;
    matrix[6][9] = -1;
    matrix[6][11] = 0;
    matrix[7][0] = -20;
    matrix[7][1] = -10;
    matrix[7][2] = -15;
    matrix[7][10] = 1;
    matrix[7][11] = 0;
    
    //hardcode operations
    //table 1 multiply row 4 by -1
    for (int i = 0; i < 12; i++)
    {
        matrix[4][i] *= -1;
        //cout << matrix[4][i] << endl;
    }
    //table 2 multiply row 5 by -1
    for (int i = 0; i < 12; i++)
    {
        matrix[5][i] *= -1;
        //cout << matrix[5][i] << endl;
    }
    //table 3 multiply row 6 by -1
    for (int i = 0; i < 12; i++)
    {
        matrix[6][i] *= -1;
        //cout << matrix[6][i] << endl;
    }
    //table 4 manipulate row operations to isolate x
    //table 5 manipulate row operations to isolate y
    //table 6 manipulate row operations to isolate z
    //easier to do on paper than on program.... stuck.
    
}