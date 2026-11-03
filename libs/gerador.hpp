#ifndef GERADOR_HPP
#define GERADOR_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Gerador{
    public:
        vector<vector<int>> criarLab(int linhas, int colunas);
        void printLab(vector<vector<int>> lab,vector<int> operador);

        void set_position_start(int value);
        void set_position_final(int value);

        int get_position_start();
        int get_position_final();

    private:
        int start_position;
        int final_position;
};


#endif