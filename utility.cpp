
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>
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
        string fullPath = filePath + "/" + fileName;
        listFile.push_back(fullPath);
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
 Split and convert current pixel string to integer
 @param stringLine - current string line
 @param delimeter - delimeter in that string
 @return vector of string which is already split
 **/
vector<int> fileSysTem::split(string stringLine, char delimeter){
    stringstream ss(stringLine);
    string item;
    vector<int> tokens;
    while (getline(ss, item, delimeter)) {
        istringstream iss (item);
        int intergerNumber;
        iss >> intergerNumber;
        tokens.push_back(intergerNumber);
    }
    return tokens;
    
}

/**
 Go to specific line in image file;
 @param fileName - name of the image
 @param lineNumber - line which need to go to
 @return info of that line
 **/
string fileSysTem::goToLine(string fileName, int lineNumber){
    vector<int> pixelList;
    ifstream imageFile(fileName);
    string line;
    int countLine = 1;
    getline (imageFile,line);
    while(!imageFile.eof()){
        getline (imageFile,line);
        if (countLine == lineNumber){
            return line;
        }
        countLine = countLine + 1;
    }
    // return line;
}
