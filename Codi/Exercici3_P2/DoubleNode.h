/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoubleNode.h
 * Author: oscar
 *
 * Created on 29 / de març / 2021, 16:43
 */

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include "Patient.h"
using namespace std;

class DoubleNode {
private:
    Patient pacient;
    DoubleNode *next;
    DoubleNode *prev;
        
public:
    DoubleNode(Patient p);
    const Patient& getPatient()const;
    DoubleNode * getNext() const;
    void setNext (DoubleNode *p);
    DoubleNode * getPrevious() const;
    void setPrevious (DoubleNode *p);
    virtual ~DoubleNode();


};

#endif /* DOUBLENODE_H */

