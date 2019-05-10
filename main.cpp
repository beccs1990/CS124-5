//
//  main.cpp
//  Project
//
//  Created by Hoa on 5/7/19.
//  Copyright © 2019 Hoa Ly. All rights reserved.
//

#include <iostream>
#include "utility.hpp"
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
    int lengthOfImage = fileSysTem::getImageLength(listImageFile[0]);
    //lengthOfImage = 5;
    for (int lineNumber = 4; lineNumber <= lengthOfImage; lineNumber++){
        vector<int> redPixelList;
        vector<int> greenPixelList;
        vector<int> bluePixelList;
        for (int j = 0; j < listImageFile.size(); j++){
            vector<int> currentImagePixel = fileSysTem::goToLine(listImageFile[j], lineNumber);
            redPixelList.push_back(currentImagePixel[0]);
            greenPixelList.push_back(currentImagePixel[1]);
            bluePixelList.push_back(currentImagePixel[2]); 
        }
        //for (int i = 0; i < redPixelList.size(); i++){
        //    cout << redPixelList[i] << " ";
        //}
        //cout << endl;
        //
        //for (int i = 0; i < greenPixelList.size(); i++){
        //    cout << greenPixelList[i] << " ";
        //}
        //cout << endl;
        //
        //for (int i = 0; i < bluePixelList.size(); i++){
        //    cout << bluePixelList[i] << " ";
        //}
        //cout << endl;
    }
    return 0;
}
