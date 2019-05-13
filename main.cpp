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
    ifstream openFile(listImageFile[0].c_str());
    string line;
    int lineNumber = 1;
    while(getline(openFile, line)){
        if (lineNumber < 4){
            lineNumber = lineNumber + 1;
            continue;
        }
        vector<int> redPixelList;
        vector<int> greenPixelList;
        vector<int> bluePixelList;
        
        for (auto const& image: listImageFile){
            vector<int> currentImagePixel = fileSysTem::goToLine(image, lineNumber);
            redPixelList.push_back(currentImagePixel[0]);
            greenPixelList.push_back(currentImagePixel[1]);
            bluePixelList.push_back(currentImagePixel[2]); 
        }
        calculateMedian redPixelMedian = calculateMedian(redPixelList);
        calculateMedian greenPixelMedian = calculateMedian(greenPixelList);
        calculateMedian bluePixelMedian = calculateMedian(bluePixelList);
        cout <<"Line "<< lineNumber <<" "<< redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;
        lineNumber = lineNumber + 1;

    }
    return 0;
}
