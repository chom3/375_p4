// The liquid portion of a diet is to provide at least 300 calories, 
// 36 units of vitamin A, and 90 units of vitamin C daily. 
// A cup of dietary drink X provides 60 calories, 12 units of vitamin A,
// and 10 units of vitamin C. A cup of dietary drink Y provides 60 calories,
// 6 units of vitamin A, and 30 units of vitamin C. 
// Now, suppose that dietary drink X costs $0.12 per cup
// and drink Y costs $0.15 per cup.
// How many cups of each drink should be consumed each day 
// to minimize the cost and still meet the stated daily requirements?

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
main(){
    //constraints
    //60x + 60y >= 300
    //12x+6y >= 36
    //10x + 30y >= 90
    //.12x + .15y = z
    //initialize a basic matrix
    vector<vector<float> > matrix(100);
    for ( int i = 0 ; i < 100 ; i++ ){
        matrix[i].resize(50);
    }
    //add the matrix values
    matrix[0][0] = 60;
    matrix[0][1] = 60;
    matrix[0][2] = 1;
    matrix[0][6] = 300;
    matrix[1][0] = 12;
    matrix[1][1] = 6;
    matrix[1][3] = 1;
    matrix[1][6] = 36;
    matrix[2][0] = 10;
    matrix[2][1] = 30;
    matrix[2][4] = 1;
    matrix[2][6] = 90;
    matrix[3][0] = -12;
    matrix[3][1] = -15;
    matrix[3][5] = 1;
    matrix[3][6] = 0;
    
    //we have the table now for simplex method
    //need to find pivot element
    //pivot column
    int minc = 0;
    int mincol = 0;
    for (int i = 0; i < 6; i++){
     if (matrix[3][i] < minc){
         minc = matrix[3][i];
         mincol = i;
     }    
    }
    //cout << minc << endl;
    //cout << mincol << endl;
    //pivot row
    int minr = 0;
    int minrow = 0;
    vector <int> pivotrow;
    for (int i =0; i < 4; i++)
    {
        // << matrix[i][mincol] << endl;
        //cout << matrix[i][6] / matrix[i][mincol] << endl;
        if (matrix[i][mincol] > 0){
            pivotrow.push_back(matrix[i][6]/matrix[i][mincol]);
        }
    }
    minr = *min_element(pivotrow.begin(), pivotrow.end());
    //cout << minr << endl;
    for (int i =0; i < 4; i++)
    {
        if (matrix[i][6]/matrix[i][mincol] == minr){
            minrow = i;
        }
    }
    //cout << minrow << endl;
    //cout << matrix[minrow][mincol] << " is the pivot element" << endl;
    
    //now we need to adjust all the values around the pivot element in the pivot column using row operations
    //hardcoded algorithm for this problem.
    for (int j = 0; j < 7; j++)
        {
            matrix[0][j] += matrix[minrow][j] * -2; 
            //cout << matrix[0][j] << endl;
        }
    for (int j = 0; j < 7; j++)
        {
            matrix[1][j] += matrix[minrow][j] * -.2; 
            //cout << matrix[1][j] << endl;
        }
    for (int j = 0; j < 7; j++)
        {
            matrix[3][j] += matrix[minrow][j] * .5; 
            //cout << matrix[3][j] << endl;
        }
    //all adjusted
    //now we can solve for x and y
    int xval = matrix[0][6] / matrix[0][0];
    //cout << xval << endl;
    //xval is 3, 60x + 60y = 300
    int yval = (300 - 60*xval)/60;
    //cout << yval << endl;
    //have both xval and yval
    //.12x + .15y = z
    float z = .12*(xval) + .15*(yval);
    cout << z << " is the minimum amount spent." << endl;
    cout << "There should be " << xval << " cups of drink X" << endl;
    cout << "There should be " << yval << " cups of drink Y" << endl;
}