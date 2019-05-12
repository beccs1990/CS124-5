//
//  median.hpp
//  Project
//
//  Created by Hoa on 5/10/19.
//  Copyright © 2019 Hoa Ly. All rights reserved.
//

#ifndef median_hpp
#define median_hpp

#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stdio.h>

using namespace std;

struct calculateMedian {
private:
    vector<int> numberList;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /**
     Default constructor;
     **/
    calculateMedian();
    
    /**
     Constructor for calculating Median
     @param listNumber - list of number which will be added to Constructor
     **/
    calculateMedian(vector<int> listNumber);
    
    /**
     Add number to queue
     @param listNumber - number which will be added to Min/Max Queue
     **/
    void addNumber(vector<int> listNumber);
    
    /**
     Rebalance max and min heap
     **/
    void reBalanceQueue();
};

#endif /* median_hpp */
