/*
* Bret Elphick
* CSC 230
* 10/06/20
* Project 1 - Read two integers from matrix file,
* use those integers to create a two dimensional char vector and bool vector,
* get words from user and check if the given words have matches in the character matrix,
* mark the bool vector if there are matches,
* print character matrix (with the matches colored in red) using the bool matrix
*/

#include <iostream>
#include <vector>
#include <string>
#include "colormod.h"
using namespace std;

void markSeparatingMatrix(int rowCount, int columnCount, vector<vector<bool>>& separatingMartix, int length, int rowIndicator, int columnIndicator){
    // after checkword returns true, this method marks the separating matrix of boolean type
    // indicator = 1 indicates a increment, indicator = -1 indicates a decrement, indicator = 0 indicates neither
    // eight if statements for each direction (up, down, left, right, and diagonals)
    
    // if statement marks the separating matrix in the upward direction
    if ((rowIndicator == 1) && (columnIndicator == 0)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount + i][columnCount] = true; 
        } 
    }
    // if statement marks the separating matrix in the downward direction
    else if ((rowIndicator == -1) && (columnIndicator == 0)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount - i][columnCount] = true; 
        } 
    }
    // if statement marks the separating matrix in the right direction
    else if ((rowIndicator == 0) && (columnIndicator == 1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount][columnCount + i] = true; 
        } 
    }
    // if statement marks the separating matrix in the left direction
    else if ((rowIndicator == 0) && (columnIndicator == -1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount][columnCount - i] = true; 
        } 
    }
    // if statement marks the separating matrix in the upper right diagonal direction
    else if ((rowIndicator == 1) && (columnIndicator == 1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount + i][columnCount + i] = true; 
        } 
    }
    // if statement marks the separating matrix in the lower left diagonal direction
    else if ((rowIndicator == -1) && (columnIndicator == -1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount - i][columnCount - i] = true; 
        } 
    }
    // if statement marks the separating matrix in the upper left diagonal direction
    else if ((rowIndicator == 1) && (columnIndicator == -1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount + i][columnCount - i] = true; 
        } 
    }
    // if statement marks the separating matrix in the lower right diagonal direction
    else if ((rowIndicator == -1) && (columnIndicator == 1)){
        for (int i = 0; i < length; i++){
            separatingMartix[rowCount - i][columnCount + i] = true; 
        } 
    }
}

bool checkWord(string str, string str2){
    // this method checks if the word from the matrix in some direction (up, down, left, right, or diagonals) matches the given word
    // returns true if it does, returns false otherwise

    for(unsigned int i = 0; i < str.length(); i++ ){
        if (str[i] != str2[i]){
            return false;
        }
    }
    return true;
}

void findWord(int row, int column, string str, vector<vector<char>>& charVector, vector<vector<bool>>& separatingMartix){
    // This method finds if the given word is in the matrix 
    string str2;
    int rowCount;
    int columnCount;
    unsigned int charCount;
    cout << str << endl;

    // creates a blank string with length equal to user entered word length
    for (unsigned int i = 0; i < str.length(); i++){
        str2.push_back(' ');
    }
                
    // the two outer loops parse through the entire matrix
    // there are eight inner for loops, each for loop is responsible for checking if the word in one of the eight directions matches the given word 
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (charVector[i][j] == str[0]){
                
                str2[0] = charVector[i][j];
                rowCount = i;
                columnCount = j;
                charCount = 1;

                // this for loop is responsible for checking the upward direction
                for(unsigned int k = 1; k < str.length(); k++){
                    // if statement checks if the word from the matrix goes out of bounds
                    if (rowCount + 1 >= row){
                        break;
                    }
                    // rowCount is incremented and the character at that postion is saved into str2
                    rowCount = rowCount + 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                // If the character count equals the length of the word then the increment/decrement did not go out of bounds, a check is neccessary
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), 1, 0);
                    }
                }
                
                // reset the values for each direction
                rowCount = i;
                columnCount = j;
                charCount = 1;
               
               // this for loop is responsible for checking the downward direction
               for(unsigned int k = 1; k < str.length(); k++){
                    if (rowCount - 1 < 0){
                        break;
                    }
                    rowCount = rowCount - 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), -1, 0);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;
               
               // this for loop is responsible for checking the right direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if (columnCount + 1 >= column){
                        break;
                    }
                    columnCount = columnCount + 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                        markSeparatingMatrix(i, j, separatingMartix, str.length(), 0, 1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;

                // this for loop is responsible for checking the left direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if (columnCount - 1 < 0){
                        break;
                    }
                    columnCount = columnCount - 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), 0, -1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;

                // this for loop is responsible for checking the upper right diagonal direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if ((rowCount + 1 >= row) || (columnCount + 1 >= column)){
                        break;
                    }
                    rowCount = rowCount + 1;
                    columnCount = columnCount + 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), 1, 1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;
                
                // this for loop is responsible for checking the lower left diagonal direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if ((rowCount - 1 < 0) || (columnCount - 1 < 0)){
                        break;
                    }
                    rowCount = rowCount - 1;
                    columnCount = columnCount - 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), -1, -1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;

                // this for loop is responsible for checking the upper left diagonal direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if ((rowCount + 1 >= row) || (columnCount - 1 < 0)){
                        break;
                        }

                    rowCount = rowCount + 1;
                    columnCount = columnCount - 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), 1, -1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 1;

                // this for loop is responsible for checking the lower right diagonal direction
                for(unsigned int k = 1; k < str.length(); k++){
                    if ((rowCount - 1 < 0) || (columnCount + 1 > column)){
                        break;
                    }
                    rowCount = rowCount - 1;
                    columnCount = columnCount + 1;
                    str2[k] = charVector[rowCount][columnCount];
                    charCount = charCount + 1;
                }
                if (str.length() == charCount){
                    if (checkWord(str, str2)){
                    markSeparatingMatrix(i, j, separatingMartix, str.length(), -1, 1);
                    }
                }

                rowCount = i;
                columnCount = j;
                charCount = 0;
            }
        }
    }
}


void fillMatrix(int row, int column, vector<vector<char>>& charVector, vector<vector<bool>>& separatingMartix){
    // method resizes the character matrix and separating matrix
    // leaves separating matrix with default values (false), fills the character matrix with given characters

    // resizes the character matrix
    charVector.resize(row);
    for (unsigned int i = 0; i < charVector.size(); i++){
        charVector[i].resize(column);
    }

    // resizes the seperating matrix, and fills it with default value (false)
    separatingMartix.resize(row);
    for (unsigned int i = 0; i < separatingMartix.size(); i++){
        separatingMartix[i].resize(column);
    }

    // fills the character matrix
    cout << endl << "Enter characters to fill array: " << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cin >> charVector[i][j];
        }
    }
}

void printColoredMatrix(int row, int column, vector<vector<char>>& charVector, vector<vector<bool>>& separatingMartix){
    // method prints the character matrix in color using the separating matrix

    cout << endl << "The colored matrix in row major order: " << endl;
    Color::Setting red(Color::FG_RED);
    Color::Setting def(Color::FG_DEFAULT);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (separatingMartix[i][j] == true){
                cout << red << charVector[i][j];
            }
            else{
                cout << charVector[i][j];
            }
        }
        cout << endl;
    } 
}

void printMatrix(int row, int column, vector<vector<char>>& charVector){
    // method prints the character matrix

    cout << endl << "The matrix in row major order: " << endl;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << charVector[i][j];
        }
        cout << endl;
    } 
}

int main(int argc, char *argv[]){
    int row;
    int column;
    string str[argc];
    vector<vector<char> > charVector;
    vector<vector<bool>> separatingMartix;
    
    cout << "Enter two integers (rows then columns): " << endl;
    cin >> row;
    cin >> column;

    fillMatrix(row, column, charVector, separatingMartix);
    printMatrix(row, column, charVector);

    cout << endl << "Enter words to check if it is in matrix: " << endl;
    for (int i = 1; i < argc; i++){
        str[i] = argv[i];
    }

    for (int i = 1; i < argc; i++){
        findWord(row, column, str[i], charVector, separatingMartix);
    }

    printColoredMatrix(row, column, charVector, separatingMartix);
}