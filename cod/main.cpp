//MILENA HELOÍSA DE AMORIM SILVÉRIO
#include <iostream>
#include <string>
#include <vector>
#include "Pilha.h"


using namespace std;

bool verificacao(char vef) {
    return vef == 'S' || vef == ' ';
}

int main() {
    vector<string> labirinto = {
        "XXXXXXXXXXXXXXXXXXXXX",
        "X     X     X     X X",
        "XX XX XXXXX X X X   X",
        "X   X       XXX XXX X",
        "X X X XXXXXXX   X   X",
        "X X   X   X X X   X X",
        "X XXXXX X X   XXXXX X",
        "X X     X XXX  X    X",
        "X X X X X   XX XX XXX",
         "X X XXX X X     X   X",
        "E X X X X XXXXX XXX X",
         "X     X X   X X X   X",
        "X XXXXX XXX X XXX X X",
        "X X       X X   X X X",
        "X   XXX X X XXX X X X",
        "XXX X X X X X X X XXX",
        "X X   X X   X   X   X",
        "X XXX XXXXXXXXX XXX X",
        "X                 X X",
        "XXXXXXXXXXXXXXXXXXXSX"
    };

    vector<string> labirinto_mostra = {
        "XXXXXXXXXXXXXXXXXXXXX",
        "X     X     X     X X",
        "XX XX XXXXX X X X   X",
        "X   X       XXX XXX X",
        "X X X XXXXXXX   X   X",
        "X X   X   X X X   X X",
        "X XXXXX X X   XXXXX X",
        "X X     X XXX  X    X",
        "X X X X X   XX XX XXX",
         "X X XXX X X     X   X",
        "E X X X X XXXXX XXX X",
         "X     X X   X X X   X",
        "X XXXXX XXX X XXX X X",
        "X X       X X   X X X",
        "X   XXX X X XXX X X X",
        "XXX X X X X X X X XXX",
        "X X   X X   X   X   X",
        "X XXX XXXXXXXXX XXX X",
        "X                 X X",
        "XXXXXXXXXXXXXXXXXXXSX"
    };

    int x = 10;
    int y = 0;

    Pilha px;
    Pilha py;
    int i = 0;
    int i_ = 0;

    /* LEGENDA:
            x+1 = DESCE UMA CASA
            x-1 = SOBE UMA CASA
            y+1 = VAI PRA DIREITA UMA CAS
            y-1 = VAI PRA ESQUERDA UMA CASA
             *  = REPRESENTA O CAMINHO PERCORRIDO
                    */

    cout << "\n* * * LABIRINTO * * * " << endl;
    cout << "  PEDA/2021 - PUCPR " << endl;
    cout << "   Milena Silverio" << endl << endl;

    cout << "Localizacao da E (Entrada): " << "( " << x << ", " << y << " )" << endl << endl;

    while (labirinto[x][y] != 'S') {
        if (verificacao(labirinto[x+1][y])) {
            ++x;
            px.push(x);
            py.push(y);
            if (labirinto[x][y] != 'S') {
                labirinto[x][y] = '*';
                labirinto_mostra[x][y] = '*';
            }
            ++i;
            ++i_;
        }
        else if (verificacao(labirinto[x-1][y])) {
            --x;
            px.push(x);
            py.push(y);
            if (labirinto[x][y] != 'S') {
                labirinto[x][y] = '*';
                labirinto_mostra[x][y] = '*';
            }
            ++i;
            ++i_;
        }
        else if (verificacao(labirinto[x][y+1])) {
            ++y;
            px.push(x);
            py.push(y);
            if (labirinto[x][y] != 'S') {
                labirinto[x][y] = '*';
                labirinto_mostra[x][y] = '*';
            }
            ++i;
            ++i_;
        }
        else if (verificacao(labirinto[x][y-1])) {
            --y;
            px.push(x);
            py.push(y);
            if (labirinto[x][y] != 'S') {
                labirinto[x][y] = '*';
                labirinto_mostra[x][y] = '*';
            }
            ++i;
            ++i_;
        }
        else {
            x = px.topo();
            px.pop();
            y = py.topo();
            py.pop();
            --i_;
            labirinto_mostra[x][y] = ' ';
        }
    }

    for (int i = 0; i < labirinto_mostra.size(); ++i) {
        cout << labirinto_mostra[i] << endl;
    }

    cout << endl << "Localizacao da S (Saida): " << "( " << px.topo() << ", " << py.topo() << " )" << endl << endl;
    cout << "Quantidade de movimentos utilizados para chegar ao S (Saida): " << i_ << endl << endl;
}

// -----------------------------------------------------------

Pilha::Pilha() {                        //Nao sao independentes, sao matodos pertencentes a classe 
    topo_ = -1;                         //indica que a pilha não está vazia
}

void Pilha::push(TipoDado elem) {       //leva pro topo da pilha
    if (!cheia()) {
        ++topo_;
        pilha[topo_] = elem;
    }
    else
        cerr << "PILHA CHEIA!" << endl;
}

void Pilha::pop() {                     //tira(descrementa) o elem do topo da pilha
    if (!vazia()) {
        --topo_;
    }
    else
        cerr << "PILHA VAZIA!" << endl;
}

TipoDado Pilha::topo() {
    if (!vazia())                       //retorna elem no topo da pilha 
        return pilha[topo_];
    else {
        cerr << "PILHA VAZIA!" << endl;
        return -1;
    }
}

bool Pilha::vazia() {
    return (topo_ == -1);

    //if(topo_ == -1)
    //    return true;
    //else 
    //    return false;
}

bool Pilha::cheia() {
    return (topo_ == MAXPILHA - 1);

    //if(topo_ == MAXPILHA -1)
    //   return true;
    //else
    //    return false;
}