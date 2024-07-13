/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.cpp
 * Author: oscar
 * 
 * Created on 24 / de març / 2021, 12:18
 */

#include "ArrayDeque.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ArrayDeque::ArrayDeque(const int max) {
    _max_size = max;
    _size = 0;
    _data = vector<int>(max);
    _front = 0;
    _rear = 0;
}

void ArrayDeque::enqueueBack(const int key){
    int i;
    if(isFull()){
        throw invalid_argument("EXCEPTION: L'estructura està plena\n");                
    }
    else{
        _data[_rear] = key;
        _rear = (_rear + 1) % _max_size;
        _size ++;
    }
    return;
}

void ArrayDeque::dequeueFront(){
    int i;
    if(isEmpty()){
        throw invalid_argument("EXCEPTION: L'Estructura està buida\n");
    }
    else{
        _front = (_front + 1) % _max_size;
        _size --;
    }
    return;
}

bool ArrayDeque::isFull(){
    if(_size == _max_size) return true;
    else return false;
}

bool ArrayDeque::isEmpty(){
    if(_size == 0) return true;
    else return false;
}

void ArrayDeque::print(){
    int i;
    cout << "[";
    for(i = 0; i < _size; i++){
        cout << _data[(i+_front)%_max_size];
        if((i+_front)%_max_size != (_rear + _max_size -1)%_max_size) cout << ",";
    }
    
            
    cout << "]\n";
    return;
}

const int ArrayDeque:: getFront(){
    if(isEmpty()){
        throw invalid_argument("EXCEPTION: L'estructura està buida\n");
    }
    else{
        return _data[_front];  
    }
}

void ArrayDeque:: enqueueFront(const int valor){
    int i;
    if(isFull()){
        throw invalid_argument("EXCEPTION: L'estructura està plena\n");              
    }
    else{
        _front = (_front + _max_size -1)%_max_size;
        _data[_front] = valor;
        _size ++;
        
    }
    return;
    
}

void ArrayDeque:: dequeueBack(){
    if(isEmpty()){
        throw invalid_argument("EXCEPTION: L'estructura està buida\n");
    }
    else{
        _rear = (_rear + _max_size -1)%_max_size;
        _size --;
    }
    return;
}

const int ArrayDeque:: getBack(){
    if(isEmpty()){
        throw invalid_argument("EXCEPTION: L'estructura està buida\n");
    }
    else{
        return _data[(_rear + _max_size -1)%_max_size];  
    }
}

