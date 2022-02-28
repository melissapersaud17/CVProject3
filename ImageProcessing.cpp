#include "ImageProcessing.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//setter methods for rows, columns, minVal and MaxVal
void ImageProcessing::setRows(int rows){
    this->numRows = rows;
}

void ImageProcessing::setCols(int cols){
    this->numCols = cols;
}

void ImageProcessing::setMin(int min){
    this->minVal = min;
}

void ImageProcessing::setMax(int max){
    this->maxVal = max;
}

//getter methods for rows and cols
int ImageProcessing::getRows(){
    return this->numRows;
}

int ImageProcessing::getCols(){
    return this->numCols;
}

//setter method for thresholdValue
void ImageProcessing::setThreshold(int threshold){
    this->thresholdValue = threshold;
}

int ImageProcessing::getThreshold(){
    return this->thresholdValue;
}

//setter methods for frameAry, outAry, thrAry
void ImageProcessing::setFrameArray(int **frame){
    this->frameAry = frame;
}

void ImageProcessing::setOutArray(int **out){
    this->outAry = out;
}

void ImageProcessing::setThrArray(int **thr){
    this->thrAry = thr;
}

//loadImage methd
void ImageProcessing::loadImage(ifstream& inFile1){

    //variables used to obtain the values from the inFile
    string line;
    istringstream iss;
    int number; 

     int rows = 2;
     int columns = 2;

    if(inFile1.is_open()){
        while(!inFile1.eof()){
            getline(inFile1, line);

            iss.clear();
            iss.str(line);

            while(iss >> number){ 
              this->frameAry[rows][columns] = number;
              //cout << this->frameAry[rows][columns] << " ";
              columns++;
            }
            //cout << endl;
            rows++;
            columns = 2;
        }                   
    }

}

void ImageProcessing::mirrorFraming(){
   
   //mirror row 0 with row 3 starting at (2,2)
   int row0 = 0;
   int row3 = 3;

    for(int column = 2; column < numCols + 4; column++){
        frameAry[row0][column] = frameAry[row3][column];
    }
   
    //mirror row 1 with row 2 starting at (2,2)
    int row1 = 1;
    int row2 = 2;

    for(int column = 2; column < numCols + 4; column++){
        frameAry[row1][column] = frameAry[row2][column];
    }

    //mirrow row(46) with row45
    int row46 = numRows + 2;
    int row45 = numRows + 1;

    for(int column = 2; column < numCols + 4; column++){
        frameAry[row46][column] = frameAry[row45][column];
    }

    //mirror 48 with 47
    int row48 = numRows + 3;
    int row47 = numRows;

    for(int column = 2; column < numCols + 4; column++){
        frameAry[row48][column] = frameAry[row47][column];
    }

//---------------------------------------------------------------------------------------------
    //mirroring the columns, col 0 with col 3 starting at the second row
    int col0 = 0;
    int col3 = 3;

    for(int i=0; i < numRows+4; i++){
        frameAry[i][col0] = frameAry[i][col3];
    }

    //col 1 with col 2
    int col1 = 1;
    int col2 = 2;

     for(int i=0; i < numRows+4; i++){
        frameAry[i][col1] = frameAry[i][col2];
    }

    //mirror col 46 with col45
    int col46 = numCols + 2;
    int col45 = numCols + 1;

    for(int i=0; i < numRows+4; i++){
        frameAry[i][col46] = frameAry[i][col45];
    }

    //mirror 48 with 47
    int col48 = numCols + 3;
    int col47 = numCols;

    for(int i=0; i < numRows+4; i++){
        frameAry[i][col48] = frameAry[i][col47];
    }

    // for(int i=0; i < numRows + 4; i++){
    //     for(int x = 0; x < numCols+4; x++){
    //         cout << frameAry[i][x] << " ";
    //     }
    //     cout << endl;
    // }

}

//loadMask method
void ImageProcessing::loadMask(){
    //[8][5][5] 8 rows, 5 columns, 5 elements inside

    mask = new int**[8];

    for (int i = 0; i < 8; i++) {
        mask[i] = new int*[5];
 
        for (int j = 0; j < 5; j++) {
            mask[i][j] = new int[5];
        }
    }

    

    int maskArray[8][5][5] = {
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
        { {3, 4, 2, 3, 5}, {0, -3, 9, 11, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5}, {23, 12, 23, 2, 5} },
    };

    //mask = maskArray;

    mask[0][0][0] = {3};


     for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
 
                // Assign values to the
                // memory blocks created
                cout << mask[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

//    int test[2][3][4] = {3, 4, 2, 3, 0, -3, 9, 11, 23, 12, 23, 
//                  2, 13, 4, 56, 3, 5, 9, 3, 5, 5, 1, 4, 9};
//     //Mask1: 
    // this->mask = { 
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },

    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //         { {3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}, {23, 12, 23, 2}, {23, 12, 23, 2} },
    //     };



}



