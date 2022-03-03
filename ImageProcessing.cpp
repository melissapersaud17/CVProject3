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
    //creating the mask array
    mask = new int**[8];
    for (int i = 0; i < 8; i++) {
        mask[i] = new int*[5];
 
        for (int j = 0; j < 5; j++) {
            mask[i][j] = new int[5];
        }
    }

    readMask(0,"mask1.txt");
    readMask(1,"mask2.txt");
    // readMask(2,"mask3.txt");
    // readMask(3,"mask4.txt");
    // readMask(4,"mask5.txt");
    // readMask(5,"mask6.txt");
    // readMask(6,"mask7.txt");
    // readMask(7,"mask8.txt");


    for(int a = 0 ; a < 8; a++){
        for(int i = 0; i < 5; i++){
            for(int x = 0; x < 5; x++){
                cout << mask[a][i][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
        

}

void ImageProcessing::readMask(int arrayNumber, string maskString){

    ifstream maskFile;
    maskFile.open(maskString);

    istringstream iss;
    string line;
    int number;

    int rows = 0;
    int columns = 0;

    //cout << "rows and columns " << rows << " " << columns << endl;

    if(maskFile.is_open()){
        //ignore the first line because we already have the size of the array's and values will 
        //only be composed of 1's and 0's
        getline(maskFile, line);

        //cout << line << endl;

        while(!maskFile.eof()){
            //gets row0
            getline(maskFile, line);

            iss.clear();
            iss.str(line);

            //cout << line;

            while(iss >> number){ 
                this->mask[arrayNumber][rows][columns] = number;
                //cout << this->mask[arrayNumber][rows][columns] << " ";
                columns++;
            }
            rows++;
            //cout << endl;
        }                   
    }
    maskFile.close();

}



