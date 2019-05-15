
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
vector<map<int, vector<int>>> fileSysTem::getListOfMap(vector<string> listImage){
    vector<map<int, vector<int>>> listMapOfImage;
    for (int i = 0; i < listImage.size(); i++) {
        listMapOfImage.push_back(getImageData(listImage[i]));
    }
    return listMapOfImage; 
}

vector<string> fileSysTem::split(string stringLine, char delimeter){
    stringstream ss(stringLine);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delimeter)) {
        istringstream iss (item);
        tokens.push_back(item);
    }
    return tokens;
}

/**
 Open up file to retrieve all image file data into hash map;
 @param fileName - name of Image file
 @return hash map of image data
 **/
map<int, vector<int>> fileSysTem::getImageData(string fileName) {
    map<int, vector<int>> imageData;
    ifstream imageFile(fileName);
    string line;
    int lineNumber = 1;
    vector<string> lineList;
    while(!imageFile.eof()) {
        getline (imageFile,line);
        vector<string> currentLine = split(line, ' ');
        lineList.insert(lineList.end(), currentLine.begin(), currentLine.end());
        lineNumber++;
    }
    cout <<"Size of image list: " << lineList.size() << endl;
    imageFile.close();
    
    /**
     Put info to hash
     **/
    int i = 0;
    int counter = 0;
    int hashLineNumber = 0;
    int sizeLineLiist = lineList.size();
    while (i < sizeLineLiist){
        vector<int>rbgList;
        if (counter < 4){
            counter = counter + 1;
            i = i + 1;
            continue;
        }
        for (int j = 0; j < 3; j++){
            if (i < sizeLineLiist){
                rbgList.push_back(stoi(lineList[i]));
            }
            i = i + 1;
        }
        imageData[hashLineNumber] = rbgList;
        hashLineNumber = hashLineNumber + 1;
        
    }
    cout <<"Size of image map: " << imageData.size() << endl;
    return imageData;
}
