#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include "median.hpp"
#include <iostream>
using namespace std;


/**Default construtor **/
calculateMedian::calculateMedian(){}
/**
Function to rebalance max and min heap
It will make sure both heap is equal
 or just more/less than 1 elements
 **/
void calculateMedian::reBalanceQueue(){
    if (minHeap.size() + 1 > maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }else if (maxHeap.size() + 1 > minHeap.size()){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    
}
/**
 Function to add number to queue, then
 it will rebalance it to make sure
 no max and min heap will be equal
 or more/less than one element
 @param number - number which will be added to Min/Max Queue
 **/
void calculateMedian::addNumber(int number){
        if (minHeap.size() == 0 || number < minHeap.top() ){
            minHeap.push(number);
        }else{
            maxHeap.push(number);
        }
       reBalanceQueue();
}
/**
 Get median from Min and Max Heap
 If size of both heap is equal, then it will get
 top of both min and max, then devide by 2.
 Otherwise, it will get from max heap
 **/
int calculateMedian::getMedian(){
    int pixelMedian;
    if (minHeap.size() == 0 && maxHeap.size() == 0){
        return 0;
    }
    
    if (minHeap.size() == maxHeap.size()){
        pixelMedian = (maxHeap.top() + minHeap.top())/2;
    }else{
        pixelMedian = maxHeap.top(); 
    }
    return pixelMedian;
    
}
