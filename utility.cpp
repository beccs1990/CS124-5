
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <iterator>
#include "utility.hpp"

/**
 Return the list of image files
 @param filePath - path of images
 **/
vector<string> fileSysTem::listImageFile(string filePath){
    vector<string> listFile; 
    DIR* dirp = opendir(filePath.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        string fileName = dp->d_name;
        if (fileName == "." || fileName == "..")
            continue; 
        listFile.push_back(fileName);
    }
    closedir(dirp);
    return listFile;
}

/**
 Get file Length
 @param fileName image name
 @return length of file
 **/
int fileSysTem::getImageLength(string fileName){
    int numLine = 0;
    string line;
    ifstream is(fileName.c_str());
    while(getline(is, line)){
        numLine++;
    }
    is.close();
    return numLine;
}

/**
 Go to specifict line in image file;
 @param fileName
 @return info of that line
 **/

