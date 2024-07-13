/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoubleNode.h
 * Author: oscar
 *
 * Created on 22 / de març / 2021, 19:47
 */

#ifndef DOUBLENODE_H
#define DOUBLENODE_H


class DoubleNode {
private:
    int pacient;
    DoubleNode *next;
    DoubleNode *prev;
        
public:
    DoubleNode(int p);
    const int& getPatient()const;
    DoubleNode * getNext() const;
    void setNext (DoubleNode *p);
    DoubleNode * getPrevious() const;
    void setPrevious (DoubleNode *p);
    virtual ~DoubleNode();


};

#endif /* DOUBLENODE_H */

