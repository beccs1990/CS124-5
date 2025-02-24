#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include "utility.hpp"
#include "median.hpp"
#include "unistd.h"


int main(int argc, const char * argv[]) {
    
    /**Get current working directory**/
    string filePath;
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
        perror("getcwd() error");
    }else{
        string s(cwd);
        filePath = s + "/image1";
    }
    /**Get list of the image, then sort it by alphabetical**/
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    sort(listImageFile.begin(), listImageFile.end());
    
    /**Put list of map which contains image data**/
    vector<map<int, vector<int>>> imagesList = fileSysTem::getListOfMap(listImageFile);

    int sizeImage = imagesList[0].size();
    int imageListSize = imagesList.size();
    
    /**
     Initialize new image with header
     **/
    string imageName = "result.ppm";
    fileSysTem::initializedImage(imageName, listImageFile[0]);
    
    /**
     Continue writing to file
     **/
    ofstream outputFile;
    outputFile.open(imageName, ios::app);
    
    
    /**Start calculating median and write to result.ppm**/
    for (int lineNumber = 0; lineNumber < sizeImage; lineNumber++){
    
       calculateMedian redPixelMedian;
       calculateMedian greenPixelMedian;
       calculateMedian bluePixelMedian;
    
       /**Loop thorugh 9 images and collecting data each nine image, then calculating
        median and write to new file**/
       for (int i = 0; i < imageListSize; i++) {

           vector<int> pixelLineList = imagesList[i][lineNumber];
           redPixelMedian.addNumber(pixelLineList[0]);
           greenPixelMedian.addNumber(pixelLineList[1]);
           bluePixelMedian.addNumber(pixelLineList[2]);
        }
        /**Write median to new file**/
        outputFile << redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << "\n";
        
        cout << redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;;

    }
    outputFile.close();
    return 0;
}
