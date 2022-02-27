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

    if(inFile1.is_open()){
        while(!inFile1.eof()){
            getline(inFile1, line);

            iss.clear();
            iss.str(line);

            int rows = 2;
            int columns = 2;

            while(iss >> number){ 
              this->frameAry[rows][columns] = number;
             // cout << this->frameAry[rows][columns] << " ";
              columns++;
            }
            cout << endl;
            rows++;
        }            
            
    }
}



