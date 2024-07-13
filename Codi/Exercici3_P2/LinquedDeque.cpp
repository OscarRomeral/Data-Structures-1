/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinquedDeque.cpp
 * Author: oscar
 * 
 * Created on 29 / de març / 2021, 16:44
 */

#include "LinquedDeque.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

using namespace std;

LinquedDeque::LinquedDeque() {
    this->head = nullptr;
    this->rear = nullptr;
    this->num_elements = 0;
}

LinquedDeque::LinquedDeque( const LinquedDeque& orig) {
    DoubleNode * aux_pointer =  orig.head;
    this->head = nullptr;
    this->rear = nullptr;
    this->num_elements = 0;
    while(aux_pointer != nullptr){
        this->enqueueBack(aux_pointer->getPatient());
        aux_pointer = aux_pointer->getNext();
    }
    
}

void LinquedDeque::enqueueFront(const Patient& f){
    DoubleNode * p = new DoubleNode(f);
    if(this->isEmpty()){
        this->head = p;
        this->rear = p;
    }
    
    else{
        p->setNext(head);
        this->head->setPrevious(p);
        this->head = p;
    }
    
    this->num_elements ++;
   
    return;
    
}

void LinquedDeque::enqueueBack(const Patient& f){
    DoubleNode * p = new DoubleNode(f);
    if(this->isEmpty()){
        this->head = p;
        this->rear = p;
    }
    this->rear->setNext(p);
    p->setPrevious(this->rear);
    this->rear = p;
    
    this->num_elements ++;
    
    return;
}

void LinquedDeque::print(){
    
    if(this->isEmpty()) cout << "Cua pacients buida\n"<< endl;
    else{
        cout << "Cua pacients:" ;
        DoubleNode *aux_pointer = this->head;
        while (aux_pointer != nullptr ){
            cout << "\n";
            aux_pointer->getPatient().print();
            aux_pointer = aux_pointer->getNext();
        }
    }
}

const Patient& LinquedDeque::getFront(){
    if(this->isEmpty()){
        throw out_of_range("getFront error: Cua buida");
    }
    else return this->head->getPatient();
}

const Patient& LinquedDeque::getBack(){
    if(this->isEmpty()){
        throw out_of_range("getBack error: Cua buida");
    }
    else return this->rear->getPatient();
}

int LinquedDeque::size(){
    return this->num_elements;
}


void LinquedDeque::dequeueFront(){
    if(this->isEmpty()){
        throw out_of_range("dequeueFront error: Cua buida");
    }
    else{
        DoubleNode * aux_pointer = this->head;
        this->head = this->head->getNext();
        this->head->setPrevious(nullptr);
        delete(aux_pointer);
        this->num_elements--;
    }
    return;
}

void LinquedDeque::dequeueBack(){
    if(this->isEmpty()){
        throw out_of_range("dequeueBack error: Cua buida");
    }
    else{
        DoubleNode * aux_pointer = this->rear;
        this->rear = this->rear->getPrevious();
        this->rear->setNext(nullptr);
        delete(aux_pointer);
        this->num_elements--;
    }
    return;
}

bool LinquedDeque::isEmpty(){
    if(num_elements == 0) return true;
    else return false;
                       
}

LinquedDeque::~LinquedDeque() {
    while (!isEmpty()){
        this->dequeueFront();
    }
}

