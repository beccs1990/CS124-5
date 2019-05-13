#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include "median.hpp"
#include <iostream>
using namespace std;

calculateMedian::calculateMedian(vector<int> dataList){
    addNumber(dataList);
}

void calculateMedian::reBalanceQueue(){
    if (minHeap.size() + 1 > maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }else if (maxHeap.size() + 1 > minHeap.size()){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    
}

void calculateMedian::addNumber(vector<int> listNumber){
    for (int i = 0; i < listNumber.size(); i++){
        if (minHeap.size() == 0 || listNumber[i] < minHeap.top() ){
            minHeap.push(listNumber[i]);
        }else{
            maxHeap.push(listNumber[i]);
        }
       reBalanceQueue();
    }
    
}

int calculateMedian::getMedian(){
    int pixelMedian;
    if (minHeap.size() == 0 && maxHeap.size() == 0){
        return 0;
    }
    
    if (minHeap.size() == maxHeap.size()){
        pixelMedian = (maxHeap.top() - minHeap.top())/2;
    }else{
        pixelMedian = maxHeap.top();
    }
    return pixelMedian;
    
}
