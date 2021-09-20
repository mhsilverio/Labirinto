#pragma once
#include <array>

#ifndef PILHA_H
#define PILHA_H

const int MAXPILHA = 200;
using TipoDado = int;

class Pilha {
private:
    // std::array<TipoDado, MAXPILHA> pilha;
    TipoDado pilha[MAXPILHA];
    int topo_;

public:
    Pilha();
    void push(TipoDado elem);
    void pop();
    TipoDado topo(); //retorna
    bool vazia();
    bool cheia();
    int tamanho_pilha();
};

#endif
#pragma once
