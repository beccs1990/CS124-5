//
//  main.cpp
//  Project
//
//  Created by Hoa on 5/7/19.
//  Copyright © 2019 Hoa Ly. All rights reserved.
//

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
        filePath = s + "/images";
    }
    //cout << filePath << endl;
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    vector<map<int, string>> imagesList = fileSysTem::getListOfMap(listImageFile);

    int sizeImage = imagesList[0].size();
    int imageListSize = imagesList.size();
    for (int lineNumber = 1; lineNumber < sizeImage; lineNumber++){
    
        if (lineNumber < 4){
            continue;
        }
        calculateMedian redPixelMedian; 
        calculateMedian greenPixelMedian;
        calculateMedian bluePixelMedian;

        for (int i = 0; i < imageListSize; i++) {
            int red, green, blue;
            size_t pos, next_pos;
            string pixelLine = imagesList[i][lineNumber];
            //cout << "image number: " << i;
            //cout << " pixel line: " << lineNumber << " " << pixelLine << endl;
            pos = pixelLine.find(' ');
            next_pos = pixelLine.find(' ', pos + 1);
            red = stoi(pixelLine.substr(0, pos));
            green = stoi(pixelLine.substr(pos + 1, next_pos));
            blue = stoi(pixelLine.substr(next_pos));
            redPixelMedian.addNumber(red);
            greenPixelMedian.addNumber(green);
            bluePixelMedian.addNumber(blue);
        }
        cout <<"Line "<< lineNumber <<" "<< redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;

    }
    return 0;
}
