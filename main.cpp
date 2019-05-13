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
    vector<map<int, string>> imagesList;
    ifstream openFile(listImageFile[0].c_str());
    string line;
    int lineNumber = 1;

    for (int i = 0; i < listImageFile.size(); i++) {
        imagesList.push_back(fileSysTem::getImageData(listImageFile[i]));
    }
    cout << "list length: " << imagesList.size() << endl;

    while(getline(openFile, line)){
        if (lineNumber < 4){
            lineNumber = lineNumber + 1;
            continue;
        }

        calculateMedian redPixelMedian; 
        calculateMedian greenPixelMedian;
        calculateMedian bluePixelMedian;
        int red, green, blue;
        string pixelLine;
        size_t pos, next_pos;

        for (auto const& image: listImageFile) {
//            pixelLine = fileSysTem::goToLine(image, lineNumber);
//            cout << "pixel line: " << endl;
//            pos = pixelLine.find(' ');
//            next_pos = pixelLine.find(' ', pos + 1);
//            red = stoi(pixelLine.substr(0, pos));
//            green = stoi(pixelLine.substr(pos + 1, next_pos));
//            blue = stoi(pixelLine.substr(next_pos));
//            redPixelMedian.addNumber(red);
//            greenPixelMedian.addNumber(green);
//            bluePixelMedian.addNumber(blue);
        }
//        cout <<"Line "<< lineNumber <<" "<< redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;
        lineNumber = lineNumber + 1;

    }
    return 0;
}
