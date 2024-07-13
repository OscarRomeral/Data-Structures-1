/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayDeque.h
 * Author: oscar
 *
 * Created on 24 / de març / 2021, 12:18
 */

#ifndef ARRAYDEQUE_H
#define ARRAYDEQUE_H

#include <vector>
#include <stdexcept>

class ArrayDeque {
public:
    ArrayDeque(const int); // constructor on s'indica la mida
    void enqueueBack(const int key); // inserir al final de la cua
    void dequeueFront(); // eliminar el primer element de la cua
    bool isFull(); // cert si esta plena la cua, altrament fals
    bool isEmpty(); // cert si esta buida la cua, altrament fals
    void print(); // imprimir tot el contingut de la cua
    const int getFront(); // obtenir el primer element de la cua
    void enqueueFront(const int); // inserir a l'inici de la cua
    void dequeueBack(); //eliminar el darrer element de la cua
    const int getBack(); // eliminar el darrer element de la cua
    
private:
    int _max_size; // mida màxima de la cua
    int _size; // nombre d'elements actuals a la cua
    std::vector<int> _data;
    int _front;
    int _rear;
    // per guardar els elements de la cua
};

#endif /* ARRAYDEQUE_H */

