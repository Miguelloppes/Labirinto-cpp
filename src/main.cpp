#include <iostream>
#include "gerador.hpp"
#include "resolver.hpp"
#include <unistd.h>

using namespace std;

#define LINHAS 10
#define COLUNAS 10

int main(){ 
    srand(time(nullptr));
    Gerador gerador;
    Resolver resolver;
    vector<vector<int>> lab = gerador.criarLab(LINHAS, COLUNAS);
    resolver.set_operador_position({gerador.get_position_start(), 0});
    vector<int> operador = resolver.get_operador_position();
    while ((operador[0] !=  gerador.get_position_final()) || (operador[1] != (COLUNAS - 1))){
        operador = resolver.get_operador_position();
        gerador.printLab(lab, operador);
        lab = resolver.resolveLab(lab);
        sleep(1);
    }
    cout << "Chego" << endl;
    return 0;
}
