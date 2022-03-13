//
// Created by 王月艺 on 2022/3/13.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        vector<int> Heap(k);
        for(int i = 0; i != k; i++){
            heapInsert(Heap,nums[i], i);
        }
        for(int i = k; i != nums.size(); i++){
            if(nums[i] > Heap[0]){
                Heap[0] = nums[i];
                heapify(Heap,0,k);
            }
        }
        for(int i = 0; i != k; i++){
            std::cout<<Heap[i]<<endl;
        }
        return Heap[0];
    }

    void heapInsert(vector<int> & nums, int val, int index){
        nums[index] = val;
        while(index != 0){
            int parent = (index - 1) / 2;
            if(nums[parent] > nums[index]){
                swap(nums, parent, index);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void heapify(vector<int> & nums, int index, int size){
        int left = index * 2 +1;
        int right = index * 2 +2;
        int smallest = index;
        while(left < size){
            if(nums[left] < nums[index]){
                smallest = left;
            }
            if(right < size && nums[right] < nums[smallest]){
                smallest = right;
            }
            if(smallest != index){
                swap(nums, smallest, index);
            }else{
                break;
            }
            index = smallest;
            left = index *2 +1;
            right = index*2+2;
        }
    }
    void swap(vector<int>& nums, int index1, int index2){
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
};
