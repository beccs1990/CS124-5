
#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <stdio.h>

using namespace std;

namespace fileSysTem {
    /**
     Return the list of image files
     @return the list of images file
     **/
    vector<string> listImageFile(string filePath);
    
    /**
     Get file Length
     @param fileName name
     @return length of file
     **/
    int getImageLength(string fileName);
    
    
    /**
     Split and convert current pixel string to integer
     @param stringLine - current string line
     @param delimeter - delimeter in that string
     @return vector of string which is already split
     **/
    vector<int> split(string stringLine, char delimeter);
    
    /**
     Go to specifict line in image file;
     @param fileName - name of Image file
     @param lineNumber - line number which is needed to go to
     @return info of that line
     **/
    string goToLine(string fileName, int lineNumber);

    /**
     Open up file to retrieve all image file data into hash map;
     @param fileName - name of Image file
     @return hash map of image data
     **/
    map<int, string> getImageData(string fileName);
}

#endif
