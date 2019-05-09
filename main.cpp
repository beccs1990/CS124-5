//
//  main.cpp
//  Project
//
//  Created by Hoa on 5/7/19.
//  Copyright © 2019 Hoa Ly. All rights reserved.
//

#include <iostream>
#include "utility.hpp"


int main(int argc, const char * argv[]) {
    string filePath = "/Users/lythaihoa2311992/Desktop/CS/CS124/Project/Project/images";
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    int lengthOfImage = fileSysTem::getImageLength(listImageFile[0]);
    
    for (int i = 3; i < lengthOfImage; i++){
        
        
    }
    return 0;
}
