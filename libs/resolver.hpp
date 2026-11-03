#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include <iostream>
#include <vector>

using namespace std;

class Resolver{
    public: 
        vector<vector<int>> resolveLab(vector<vector<int>> lab);
        void set_operador_position(vector<int> value);
        vector<int> get_operador_position();

    private: 
        vector<int> operador;
};


#endif