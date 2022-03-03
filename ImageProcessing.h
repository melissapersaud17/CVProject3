#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <iostream>
using namespace std;

class ImageProcessing{
     private: 
        int numRows;
        int numCols;
        int minVal;
        int maxVal;

        int thresholdValue;

        int **frameAry;
	    int **outAry;
	    int **thrAry;

        int ***mask;
    public:

        //setter methods for rows, columns, min and max
        void setRows(int rows);
        void setCols(int cols);
        void setMin(int min);
        void setMax(int max);

        //getter methods for the min and max values
        int getMin();
        int getMax();

        //getter methods for rows and columns
        int getRows();
        int getCols();
        

        //setter method for thresholdValue
        void setThreshold(int threshold);
        int getThreshold();

        //setter methods for frameAry, outAry, thrAry
        void setFrameArray(int **frame);
        void setOutArray(int **out);
        void setThrArray(int **thr);

        //loadImage method
        void loadImage(ifstream& inFile1);

        //mirror framing method
        void mirrorFraming();

        //loadMask method
        void loadMask();

        //imgReformat method 
        void imgReformat(int **inAry, int newMin, int newMax, ofstream& outFile1);

        //threshold method
        void threshold(int **outArray, int **thresholdAry, int thresholdVal);

        //cornerPreserveAvg method
        void cornerPreserveAvg();
};      



#endif