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
    string filePath;
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
        perror("getcwd() error");
    }else{
        string s(cwd);
        filePath = s + "/images";
    }
    cout << filePath << endl; 
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    int lengthOfImage = fileSysTem::getImageLength(listImageFile[0]);
    cout << "Length of image: " << lengthOfImage << endl;
    return 0;
}
