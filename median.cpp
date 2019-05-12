#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include "median.hpp"


calculateMedian::calculateMedian(vector<int> dataList){
    numberList = dataList;
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
        if (listNumber[i] < minHeap.top() || minHeap.size() == 0){
            minHeap.push(listNumber[i]);
        }else{
            maxHeap.push(listNumber[i]);
        }
        reBalanceQueue();
    }
    
}
