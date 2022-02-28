#include "ImageProcessing.h"
#include "ImageProcessing.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){

    //ImagProcessing object
    ImageProcessing ip;

    //inFile 1
    string file1 = argv[1];
    ifstream inFile1;
    inFile1.open(file1);

    //Obtaining the threshold value
    int thresholdValue = atoi (argv[2]);
    ip.setThreshold(thresholdValue);

    //outFile 1
    string outFile_1 = argv[3];
    ofstream outFile1;
    outFile1.open(outFile_1);

    //outFile 2
    string outFile_2 = argv[4];
    ofstream outFile2;
    outFile2.open(outFile_2);

    //read in numRows, numCols, minVal, maxVal
    int *imageHeader = new int[4]();

    int number;
    string line;
    istringstream iss;

    if(inFile1.good()){
        getline(inFile1, line);

            iss.clear();
            iss.str(line);

            int i = 0;

            while (iss >> number){ // only used for collecting the values from the image header
                imageHeader[i] = number;
                i++;
            }

            ip.setRows(imageHeader[0]);
            ip.setCols(imageHeader[1]);
            ip.setMin(imageHeader[2]);
            ip.setMax(imageHeader[3]);

            delete[] imageHeader;
   }

   //dynamically allocate frameAry
    int rows = ip.getRows() + 4;
    int columns = ip.getCols() + 4;
    int **frameArry =  new int*[rows];

    for(int i=0; i < rows; i++){
        frameArry[i] = new int[columns];
    }
    ip.setFrameArray(frameArry);

    //dynamically allocate outAry
    int **outputArry = new int*[rows];
    for(int i=0; i < rows; i++){
        outputArry[i] = new int[columns];
    }
    ip.setOutArray(outputArry);

    //dynamically allocate thrAry
    int **thresholdArry = new int*[rows];\
    for(int i=0; i < rows; i++){
        thresholdArry[i] = new int[columns];
    }
    ip.setThrArray(thresholdArry);

    //calling the loadImage method
    ip.loadImage(inFile1);

    ip.mirrorFraming();

    ip.loadMask();








   





    return 0;
}