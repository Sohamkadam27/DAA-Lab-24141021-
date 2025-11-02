#include <windows.h>
#include <iostream>
#include <vector>     
#include <queue>      
#include <functional> 

using namespace std;

int optimalMerge_heap(vector<int>& files) {

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int fileSize : files) {
        minHeap.push(fileSize);
    }

    int totalCost = 0;

  
    while (minHeap.size() > 1) {
    
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();


        int cost = first + second;
        totalCost += cost;

  
        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    
    vector<int> files = {20, 30, 10, 5};

    int result = optimalMerge_heap(files);

    cout << "Minimum total cost of merging = " << result << endl;
    return 0;
}