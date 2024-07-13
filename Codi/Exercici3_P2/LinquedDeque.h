/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinquedDeque.h
 * Author: oscar
 *
 * Created on 29 / de març / 2021, 16:44
 */

#ifndef LINQUEDDEQUE_H
#define LINQUEDDEQUE_H

#include "DoubleNode.h"
#include "Patient.h"

using namespace std;

class LinquedDeque {
public:
    LinquedDeque();
    virtual ~LinquedDeque();
    LinquedDeque(const LinquedDeque& orig);
    void enqueueFront( const Patient& f);
    void enqueueBack( const Patient& f);
    void dequeueFront();
    void dequeueBack();
    
    bool isEmpty();
    void print();
    const Patient& getFront();
    const Patient& getBack();
    int size();
    
private:
    DoubleNode * head;
    DoubleNode * rear;
    int num_elements;
    
   
};

#endif /* LINQUEDDEQUE_H */

