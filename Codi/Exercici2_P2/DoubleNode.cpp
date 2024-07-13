/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoubleNode.cpp
 * Author: oscar
 * 
 * Created on 22 / de març / 2021, 19:47
 */

#include "DoubleNode.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DoubleNode::DoubleNode(int p) {
    this->pacient = p;
    this->next = nullptr;
    this->prev = nullptr;
}

const int& DoubleNode::getPatient()const{
    return this->pacient;
}

DoubleNode * DoubleNode::getNext() const{
    return this->next;
}

void DoubleNode::setNext (DoubleNode *p){
    this->next = p;
    return;
}

DoubleNode * DoubleNode::getPrevious() const{
    return this->prev;
}

void DoubleNode::setPrevious (DoubleNode *p){
    this->prev = p;
    return;
}


DoubleNode::~DoubleNode() {
}

