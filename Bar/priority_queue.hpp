//
//  priority_queue.h
//  Bar
//
//  Created by Jay Shah on 11/7/18.
//  Copyright © 2018 Jay Shah. All rights reserved.
//

#ifndef priority_queue_h
#define priority_queue_h

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "Key.h"
#include "Event.hpp"
#include "eventComparision.h"

using namespace std;


class Priority_Queue
{
public:
    
    Priority_Queue(){
        items = NULL;
    }
    Priority_Queue(Event vals[10])
    {
        items = new Event[capacity];
        for(int i = 0; i < 10; i++){
            items[i] = vals[i];
            size++;
        }
    }
    
    void insert(Event v){
        size++;
        ensureCapacity();
        items[size-1] = v;
        swim();
    }
    
    Event del_min(){
        if(size == 1){
            size = 0;
            Event deleted = items[0];
            items[0] = NULL;
            size--;
            return deleted;
        }
        int curMin = 0;
        for(int i = 1; i < size; i++){
    
            if(items[curMin] > items[i])
            {
                curMin = i;
            }
            
        }
        
        Event itemDel = items[curMin];
        for(int i = curMin; i < size-1; i++){
            items[i] = items[i+1];
        }
        items[size-1] = NULL;
        size--;
        return itemDel;
    }
    
    bool isEmpty(){
        if(size == 0){
            return true;
        }
        else
            return false;
    }
    
    Event min(){
        if(size == 1){
            return items[0];
        }
        else{
            int curMin = 0;
            for(int i = 1; i <size; i++){
                if(items[curMin] > items[i])
                {
                    curMin = i;
                }
            }
            return items[curMin];
        }
    }
    
    int sizeofQueue(){
        return size;
    }
    
    void swim(){
        int index = size-1;
        while(hasParent(index) && parent(index) > items[index])
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }
        
    void sink(){
        int index = 0;
        while(hasLeftChild(index)){
            int smallerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && rightChild(index) < leftChild(index)){
                smallerChildIndex = getRightChildIndex(index);
            }
            if(items[index] < items[smallerChildIndex])
            {
                break;
            }
            else{
                swap(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }
    }

    //bool less(int i, int j);
   // void exch(int i, int j);
    
    
    
    int getLeftChildIndex(int parentIndex){
        return 2* parentIndex +1;
    }
    int getRightChildIndex(int parentIndex){
        return 2 * parentIndex +2;
    }
    int getParentIndex(int childIndex){
        return (childIndex - 1) / 2;
    }
    bool hasLeftChild(int index){
        return getLeftChildIndex(index) < size;
    }
    bool hasRightChild(int index){
        return getRightChildIndex(index) < size;
    }
    bool hasParent(int index){
        return getParentIndex(index) >= 0;
    }
    Event leftChild(int index){
        return items[getLeftChildIndex(index)];
    }
    Event rightChild(int index){
        return items[getRightChildIndex(index)];
    }
    Event parent(int index){
        return items[getParentIndex(index)];
    }
    
    void swap(int index1, int index2){
        Event temp = items[index1];
        items[index1] = items[index2];
        items[index2] = temp;
    }
    
    void ensureCapacity(){
        if(size == capacity){
            int capacityNew = capacity*2;
            Event* newArr = new Event[capacityNew];
            
            for(int i = 0; i < size; i ++){
                newArr[i] = items[i];
            }
            delete[] items;
            items = newArr;
        }
    }
    
    Event peek(){
        if(size == 0)
            return NULL;
        else
            return items[0];
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout<<&items[i] <<endl;
        }
    }


private:
    int capacity = 10;
    int size = 0;
    Event *items;
};


#endif /* priority_queue_h */
