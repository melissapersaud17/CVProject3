#include "ImageProcessing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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

//getter methods for min and max values
int ImageProcessing::getMin(){
    return this->minVal;
}

int ImageProcessing::getMax(){
    return this->maxVal;
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

void ImageProcessing::getFrameArray(){
    for (int i = 0; i < numRows+4; i++){
        for (int x = 0; x < numCols + 4; x++){
            cout << frameAry[i][x] << " ";
        }
        cout << endl;
        /* code */
    }
    
}

void ImageProcessing::setOutArray(int **out){
    this->outAry = out;
}

void ImageProcessing::setThrArray(int **thr){
    this->thrAry = thr;
}

void ImageProcessing::getThrArray(){
   for (int i = 0; i < numRows+4; i++){
        for (int x = 0; x < numCols + 4; x++){
            cout << thrAry[i][x] << " ";
        }
        cout << endl;
        /* code */
    } 
}

void ImageProcessing::getoutArray(){
    for(int i =0; i < numRows + 4; i++){
        for(int x = 0; x < numCols + 4; x++){
            cout << outAry[i][x] << " ";
        }

        cout << endl;
    }
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

    //mask1
    mask[0][0][0] = 0;
    mask[0][0][1] = 0;
    mask[0][0][2] = 0; 
    mask[0][0][3] = 0; 
    mask[0][0][4] = 0;

    mask[0][1][0] = 0;
    mask[0][1][1] = 0;
    mask[0][1][2] = 0; 
    mask[0][1][3] = 0; 
    mask[0][1][4] = 0;

    mask[0][2][0] = 0;
    mask[0][2][1] = 0;
    mask[0][2][2] = 1; 
    mask[0][2][3] = 0; 
    mask[0][2][4] = 0;

    mask[0][3][0] = 0;
    mask[0][3][1] = 1;
    mask[0][3][2] = 1; 
    mask[0][3][3] = 1; 
    mask[0][3][4] = 0;

    mask[0][4][0] = 1;
    mask[0][4][1] = 1;
    mask[0][4][2] = 1; 
    mask[0][4][3] = 1; 
    mask[0][4][4] = 1;

    //mask 2
    mask[1][0][0] = 1;
    mask[1][0][1] = 0;
    mask[1][0][2] = 0; 
    mask[1][0][3] = 0; 
    mask[1][0][4] = 0;

    mask[1][1][0] = 1;
    mask[1][1][1] = 1;
    mask[1][1][2] = 0; 
    mask[1][1][3] = 0; 
    mask[1][1][4] = 0;

    mask[1][2][0] = 1;
    mask[1][2][1] = 1;
    mask[1][2][2] = 1; 
    mask[1][2][3] = 0; 
    mask[1][2][4] = 0;

    mask[1][3][0] = 1;
    mask[1][3][1] = 1;
    mask[1][3][2] = 0; 
    mask[1][3][3] = 0; 
    mask[1][3][4] = 0;

    mask[1][4][0] = 1;
    mask[1][4][1] = 0;
    mask[1][4][2] = 0; 
    mask[1][4][3] = 0; 
    mask[1][4][4] = 0;

    //mask 3
    mask[2][0][0] = 1;
    mask[2][0][1] = 1;
    mask[2][0][2] = 1; 
    mask[2][0][3] = 1; 
    mask[2][0][4] = 1;

    mask[2][1][0] = 0;
    mask[2][1][1] = 1;
    mask[2][1][2] = 1; 
    mask[2][1][3] = 1; 
    mask[2][1][4] = 0;

    mask[2][2][0] = 0;
    mask[2][2][1] = 0;
    mask[2][2][2] = 1; 
    mask[2][2][3] = 0; 
    mask[2][2][4] = 0;

    mask[2][3][0] = 0;
    mask[2][3][1] = 0;
    mask[2][3][2] = 0; 
    mask[2][3][3] = 0; 
    mask[2][3][4] = 0;
    
    mask[2][4][0] = 0;
    mask[2][4][1] = 0;
    mask[2][4][2] = 0; 
    mask[2][4][3] = 0; 
    mask[2][4][4] = 0;

    //mask4
    mask[3][0][0] = 0;
    mask[3][0][1] = 0;
    mask[3][0][2] = 0; 
    mask[3][0][3] = 0; 
    mask[3][0][4] = 1;

    mask[3][1][0] = 0;
    mask[3][1][1] = 0;
    mask[3][1][2] = 0; 
    mask[3][1][3] = 1; 
    mask[3][1][4] = 1;

    mask[3][2][0] = 0;
    mask[3][2][1] = 0;
    mask[3][2][2] = 1; 
    mask[3][2][3] = 1; 
    mask[3][2][4] = 1;

    mask[3][3][0] = 0;
    mask[3][3][1] = 0;
    mask[3][3][2] = 0; 
    mask[3][3][3] = 1; 
    mask[3][3][4] = 1;
    
    mask[3][4][0] = 0;
    mask[3][4][1] = 0;
    mask[3][4][2] = 0; 
    mask[3][4][3] = 0; 
    mask[3][4][4] = 1;

    //mask5
    mask[4][0][0] = 1;
    mask[4][0][1] = 1;
    mask[4][0][2] = 1; 
    mask[4][0][3] = 0; 
    mask[4][0][4] = 0;

    mask[4][1][0] = 1;
    mask[4][1][1] = 1;
    mask[4][1][2] = 1; 
    mask[4][1][3] = 0; 
    mask[4][1][4] = 0;

    mask[4][2][0] = 1;
    mask[4][2][1] = 1;
    mask[4][2][2] = 1; 
    mask[4][2][3] = 0; 
    mask[4][2][4] = 0;

    mask[4][3][0] = 0;
    mask[4][3][1] = 0;
    mask[4][3][2] = 0; 
    mask[4][3][3] = 0; 
    mask[4][3][4] = 0;
    
    mask[4][4][0] = 0;
    mask[4][4][1] = 0;
    mask[4][4][2] = 0; 
    mask[4][4][3] = 0; 
    mask[4][4][4] = 0;

    //mask6
    mask[5][0][0] = 0;
    mask[5][0][1] = 0;
    mask[5][0][2] = 1; 
    mask[5][0][3] = 1; 
    mask[5][0][4] = 1;

    mask[5][1][0] = 0;
    mask[5][1][1] = 0;
    mask[5][1][2] = 1; 
    mask[5][1][3] = 1; 
    mask[5][1][4] = 1;

    mask[5][2][0] = 0;
    mask[5][2][1] = 0;
    mask[5][2][2] = 1; 
    mask[5][2][3] = 1; 
    mask[5][2][4] = 1;

    mask[5][3][0] = 0;
    mask[5][3][1] = 0;
    mask[5][3][2] = 0; 
    mask[5][3][3] = 0; 
    mask[5][3][4] = 0;
    
    mask[5][4][0] = 0;
    mask[5][4][1] = 0;
    mask[5][4][2] = 0; 
    mask[5][4][3] = 0; 
    mask[5][4][4] = 0;

    //mask7
    mask[6][0][0] = 0;
    mask[6][0][1] = 0;
    mask[6][0][2] = 0; 
    mask[6][0][3] = 0; 
    mask[6][0][4] = 0;

    mask[6][1][0] = 0;
    mask[6][1][1] = 0;
    mask[6][1][2] = 0; 
    mask[6][1][3] = 0; 
    mask[6][1][4] = 0;

    mask[6][2][0] = 0;
    mask[6][2][1] = 0;
    mask[6][2][2] = 1; 
    mask[6][2][3] = 1; 
    mask[6][2][4] = 1;

    mask[6][3][0] = 0;
    mask[6][3][1] = 0;
    mask[6][3][2] = 1; 
    mask[6][3][3] = 1; 
    mask[6][3][4] = 1;
    
    mask[6][4][0] = 0;
    mask[6][4][1] = 0;
    mask[6][4][2] = 1; 
    mask[6][4][3] = 1; 
    mask[6][4][4] = 1;

    //mask8
    mask[7][0][0] = 0;
    mask[7][0][1] = 0;
    mask[7][0][2] = 0; 
    mask[7][0][3] = 0; 
    mask[7][0][4] = 0;

    mask[7][1][0] = 0;
    mask[7][1][1] = 0;
    mask[7][1][2] = 0; 
    mask[7][1][3] = 0; 
    mask[7][1][4] = 0;

    mask[7][2][0] = 1;
    mask[7][2][1] = 1;
    mask[7][2][2] = 1; 
    mask[7][2][3] = 0; 
    mask[7][2][4] = 0;

    mask[7][3][0] = 1;
    mask[7][3][1] = 1;
    mask[7][3][2] = 1; 
    mask[7][3][3] = 0; 
    mask[7][3][4] = 0;
    
    mask[7][4][0] = 1;
    mask[7][4][1] = 1;
    mask[7][4][2] = 1; 
    mask[7][4][3] = 0; 
    mask[7][4][4] = 0;
}

void ImageProcessing::imgReformat(int **inAry, int newMin, int newMax, ofstream& outFile1){

    if(outFile1.is_open()){
        outFile1 << numRows << " "  << numCols << " " << newMin << " " << newMax << endl;

        string str = to_string(newMax);
        int width = str.length();

        int r = 1;

        while(r <= numRows +2 ){
        int c = 1;
            while(c <= numCols+2 ){
                outFile1 << inAry[r][c];
                str = to_string(inAry[r][c]);
                int ww = str.length();

                while(ww < width){
                    outFile1 << " ";
                    ww++;
                }
                c++;
            }
            outFile1 << endl;
            r++;
        }

    }

}

//theshold method
void ImageProcessing::threshold(int **outArray, int **thresholdAry, int thresholdVal){
    for(int i = 0; i < numRows + 4; i++){
        for(int j = 0; j < numCols + 4; j++){
            if(outArray[i][j] >= thresholdVal){
                thresholdAry[i][j] = 1;
            }else{
                thresholdAry[i][j] = 0;
            }
        }
    }
}

//cornerPreserveAvg method
void ImageProcessing::cornerPreserveAvg(){
    int r = 2;
    int c = 2;
    

    while( r < numRows + 2){
        while(c < numCols + 2){
            int maskIndex = 0;  //starting with mask 0
            int minAvg = frameAry[r][c];  //looking at frameAry[2][2]
            int minDiff = 9999;

            while(maskIndex < 8){
                int result = convolution5x5(r,c,maskIndex) / 9;

                int diff = abs(result - frameAry[r][c]);

                if(diff < minDiff){
                    minDiff = diff;
                    minAvg = result;
                }
                maskIndex++;
            }

            outAry[r][c] = minAvg;
            c++; 
        }
        r++;
        c = 2;
    }

}

int ImageProcessing::convolution5x5(int r, int c, int maskIndex){
    int average = 0;
    int rowStart = r - 2;
    int colStart = c - 2;
    int col = c;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
        
        if (mask[maskIndex][i][j] == 1){
            average += frameAry[rowStart][colStart];
        }
        colStart++;
    }
    rowStart++;
    colStart = c - 2;
    }
    return average;
}
