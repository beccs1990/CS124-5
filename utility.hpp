
#ifndef utility_hpp
#define utility_hpp

#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
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
     Go to specifict line in image file;
     @param fileName
     @return info of that line
     **/
    vector<int> goToLine(string fileName, int lineNumber); 
}
#endif
