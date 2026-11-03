#include "resolver.hpp"

using namespace std;

// 0 - livre
// 1 - bloqueio
// 2 - chegada
// 3 - ja passei

//  ██████╗ ███████╗████████╗    ███████╗    ███████╗███████╗████████╗
// ██╔════╝ ██╔════╝╚══██╔══╝    ██╔════╝    ██╔════╝██╔════╝╚══██╔══╝
// ██║  ███╗█████╗     ██║       █████╗      ███████╗█████╗     ██║   
// ██║   ██║██╔══╝     ██║       ██╔══╝      ╚════██║██╔══╝     ██║   
// ╚██████╔╝███████╗   ██║       ███████╗    ███████║███████╗   ██║   
//  ╚═════╝ ╚══════╝   ╚═╝       ╚══════╝    ╚══════╝╚══════╝   ╚═╝   
                                                                   
void Resolver::set_operador_position(vector<int> value){
    operador = value;
}
vector<int> Resolver::get_operador_position(){
    return operador;
}

// ███████╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ███████╗███████╗    
// ██╔════╝██║   ██║████╗  ██║██╔════╝██╔═══██╗██╔════╝██╔════╝    
// █████╗  ██║   ██║██╔██╗ ██║██║     ██║   ██║█████╗  ███████╗    
// ██╔══╝  ██║   ██║██║╚██╗██║██║     ██║   ██║██╔══╝  ╚════██║    
// ██║     ╚██████╔╝██║ ╚████║╚██████╗╚██████╔╝███████╗███████║    
// ╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝    


// deve seguir as paredes, ou sejas: mao na parede e segue 
vector<vector<int>> Resolver::resolveLab(vector<vector<int>> lab){
    vector<int> operador = get_operador_position();
    int i = operador[0];
    int j = operador[1];

    // direita -- so vai se tem parede do lado
    if(lab[i][j + 1] == 2){ 
        j++;
        lab[i][j] = 3;
    }
    if(lab[i][j + 1] == 0 && (lab[i+1][j] == 1 || lab[i+1][j] == 2)){ 
        j += 1;
        lab[i][j] = 3;
    }
    //baixo -- so vai se tem parede do lado
    else if(lab[i+ 1][j] == 0 && (lab[i+1][j-1] == 1 || lab[i+1][j-1] == 2)){ 
        i+= 1;
        lab[i][j] = 3;
    }
    //cima
    else if(lab[i- 1][j] == 0 && (lab[i-1][j+1] == 1 || lab[i-1][j+1] == 2)){ 
        i-= 1;
        lab[i][j] = 3;
    }
    //esquerda 
    else if(lab[i][j - 1] == 0 && (lab[i-1][j] == 1 || lab[i-1][j] == 2)){ 
        j -= 1;
        lab[i][j] = 3;
    }

    //mesma coisa so q ja passado

    //direita
    else if(lab[i][j + 1] == 3 && (lab[i+1][j] == 1 || lab[i+1][j] == 2)){ 
        j += 1;
        lab[i][j] = 3;
    }
    //baixo -- so vai se tem parede do lado
    else if(lab[i+ 1][j] == 3 && (lab[i+1][j-1] == 1 || lab[i+1][j-1] == 2)){ 
        i+= 1;
        lab[i][j] = 3;
    }
    //cima
    else if(lab[i- 1][j] == 3 && (lab[i-1][j+1] == 1 || lab[i-1][j+1] == 2)){ 
        i-= 1;
        lab[i][j] = 3;
    }
    //esquerda 
    else if(lab[i][j - 1] == 3 && (lab[i-1][j+1] == 1 || lab[i-1][j] == 2)){ 
        j -= 1;
        lab[i][j] = 3;
    }

    operador[0] = i;
    operador[1] = j;
    set_operador_position(operador);
    return lab;

}