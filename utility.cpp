
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
 Get List of Map
 @param listImage - vector of image
 @return list of hash which contain image data
 **/
vector<map<int, string>> fileSysTem::getListOfMap(vector<string> listImage){
    vector<map<int, string>> listMapOfImage;
    for (int i = 0; i < listImage.size(); i++) {
        listMapOfImage.push_back(getImageData(listImage[i]));
    }
    return listMapOfImage; 
}


/**
 Open up file to retrieve all image file data into hash map;
 @param fileName - name of Image file
 @return hash map of image data
 **/
map<int, string> fileSysTem::getImageData(string fileName) {
    map<int, string> imageData;
    ifstream imageFile(fileName);
    string line;
    int lineNumber = 1;
    while(!imageFile.eof()){
        getline (imageFile,line);
        imageData[lineNumber] = line;
        //cout << "data: " << lineNumber << "line: " << imageData[lineNumber] << endl;
        lineNumber++;
    }
    return imageData;
}
