
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <dirent.h>
#include "utility.hpp"

/**
 Function to return the list of image files
 It will go to entire directory and put each .ppm
 file to vector list
 @param filePath - path of images
 @param listFile - return list of image file
 **/
vector<string> fileSysTem::listImageFile(string filePath){
    vector<string> listFile; 
    DIR* dirp = opendir(filePath.c_str());
    struct dirent * dp;
    /**Open the directory and make sure that directory is not empty**/
    while ((dp = readdir(dirp)) != NULL) {
        string fileName = dp->d_name;
        /**If element is . or .., then skip them**/
        if (fileName == "." || fileName == "..")
            continue;
        string fullPath = filePath + "/" + fileName;
        /**Put each image file to vector with full path**/
        listFile.push_back(fullPath);
    }
    closedir(dirp);
    return listFile;
}

/**
 Function to get List of Map for image
 It will put each map which represent for each image
 to list
 @param listImage - vector of image
 @return list of hash which contain image data
 **/
vector<map<int, vector<int>>> fileSysTem::getListOfMap(vector<string> listImage){
    vector<map<int, vector<int>>> listMapOfImage;
    /**Go to list of image file, put their data into map. Then, putting map to vector list**/
    for (int i = 0; i < listImage.size(); i++) {
        listMapOfImage.push_back(getImageData(listImage[i]));
    }
    return listMapOfImage; 
}
/**
 Function to split and convert current pixel string to integer
 based on their delinmeter
 @param stringLine - current string line
 @param delimeter - delimeter in that string
 @return vector of string which is already split
 **/
vector<string> fileSysTem::split(string stringLine, char delimeter){
    stringstream ss(stringLine);
    string item;
    vector<string> tokens;
    /**Seperate delimeter and put them to list**/
    while (getline(ss, item, delimeter)) {
        istringstream iss (item);
        tokens.push_back(item);
    }
    return tokens;
}

/**
 Function to convert string vector to map
 It will go to 3 elements (red, green, blue )at a tinme
 then put it to vector list. After that, it will put it to map
 in the form map<lineNumber, {red, green, blue}>
 @param pixelList - current pixel vector
 @return imageData - return approriate hash which contain pixel
 **/

map<int, vector<int>> fileSysTem::convertVectorToMap(vector<string> pixelList){
    map<int, vector<int>> imageData;
    int i = 0;
    int counter = 0;
    int hashLineNumber = 0;
    int sizePixelList = pixelList.size();
    /**Loop through string list**/
    while (i < sizePixelList){
        vector<int>rbgList;
        /**The first 3 lines are headers, so no need to record these line **/
        if (counter < 4){
            counter = counter + 1;
            i = i + 1;
            continue;
        }
        /**Put 3 elemetns red, green, blue to the list, then putting them to map**/
        for (int j = 0; j < 3 && i < sizePixelList; j++){
            rbgList.push_back(stoi(pixelList[i]));
            i = i + 1;
        }
        /**Put list of red, green, blue to map. Key would be hash line number**/
        imageData[hashLineNumber] = rbgList;
        hashLineNumber = hashLineNumber + 1;
    }
    return imageData;
}

/**
 Open up file to retrieve all image file data into hash map;
 @param fileName - name of Image file
 @return hash map of image data
 **/
map<int, vector<int>> fileSysTem::getImageData(string fileName) {
    ifstream imageFile(fileName);
    string line;
    vector<string> lineList;
    /**Go through entire image file**/
    while(!imageFile.eof()) {
        getline (imageFile,line);
        /**Put each line to vector string**/
        vector<string> currentLine = split(line, ' ');
        lineList.insert(lineList.end(), currentLine.begin(), currentLine.end());
    }
    imageFile.close();
    /**Convert string vector to map**/
    map<int, vector<int>> imageData = convertVectorToMap(lineList);
    return imageData;
}

/**
 Function to intialize the image. It will get the first 3 header
 lines in the image and write to new file
 @param imageName - name of Image
 @param imageFrom - image which will be copied header from
 **/
void fileSysTem::initializedImage (string imageName, string imageFrom){
    /**Create new file and open current file**/
    ofstream outputFile (imageName);
    ifstream imageFile(imageFrom);
    string line;
    int counting = 1;
    /**Open current image file and write the first 3 header lines
     to new files. Then exit the loop.
     **/
    while(!imageFile.eof()) {
        getline (imageFile,line);
        if (counting < 4){
            outputFile << line << "\n";
        }else{
            break;
        }
        counting = counting + 1;
    }
    /**Close the files**/
    outputFile.close();
    imageFile.close(); 
}
