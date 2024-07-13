/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinquedDeque.h
 * Author: oscar
 *
 * Created on 22 / de març / 2021, 19:29
 */

#ifndef LINQUEDDEQUE_H
#define LINQUEDDEQUE_H

#include "DoubleNode.h"

class LinquedDeque {
public:
    LinquedDeque();
    virtual ~LinquedDeque();
    LinquedDeque(LinquedDeque& orig);
    void enqueueFront(const int& f);
    void enqueueBack(const int& f);
    void dequeueFront();
    void dequeueBack();
    
    bool isEmpty();
    void print();
    const int& getFront();
    const int& getBack();
    int size();
    
private:
    DoubleNode * head;
    DoubleNode * rear;
    int num_elements;
    
   
};

#endif /* LINQUEDDEQUE_H */

