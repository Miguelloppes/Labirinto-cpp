#include "gerador.hpp"

using namespace std;

//  ██████╗ ███████╗████████╗    ███████╗    ███████╗███████╗████████╗
// ██╔════╝ ██╔════╝╚══██╔══╝    ██╔════╝    ██╔════╝██╔════╝╚══██╔══╝
// ██║  ███╗█████╗     ██║       █████╗      ███████╗█████╗     ██║   
// ██║   ██║██╔══╝     ██║       ██╔══╝      ╚════██║██╔══╝     ██║   
// ╚██████╔╝███████╗   ██║       ███████╗    ███████║███████╗   ██║   
//  ╚═════╝ ╚══════╝   ╚═╝       ╚══════╝    ╚══════╝╚══════╝   ╚═╝   
                                                                   

void Gerador::set_position_start(int value){
    start_position = value;
}
void Gerador::set_position_final(int value){
    final_position = value;
}


int Gerador::get_position_start(){
    return start_position;
}
int Gerador::get_position_final(){
    return final_position;
}


// ███████╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ███████╗███████╗    
// ██╔════╝██║   ██║████╗  ██║██╔════╝██╔═══██╗██╔════╝██╔════╝    
// █████╗  ██║   ██║██╔██╗ ██║██║     ██║   ██║█████╗  ███████╗    
// ██╔══╝  ██║   ██║██║╚██╗██║██║     ██║   ██║██╔══╝  ╚════██║    
// ██║     ╚██████╔╝██║ ╚████║╚██████╗╚██████╔╝███████╗███████║    
// ╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝    
                                                                
vector<vector<int>> Gerador::criarLab(int linhas, int colunas){ 
    vector<vector<int>> lab(linhas, vector<int>(colunas,0));

    for (int i = 0; i < linhas; i++){ 
        for (int j = 0; j < colunas; j++){
            if(i == 0){
                lab[i][j] = 1;
            }
            else if(i == (linhas - 1)){ 
                lab[i][j] = 1;
            }
            else if(j == 0){ 
                lab[i][j] = 1;
            }
            else if(j == (colunas - 1)){ 
                lab[i][j] = 1;
            }
            else{
                lab[i][j] = 0;
                //lab[i][j] = rand() % 2;
            }
        }
    }

    set_position_start(int(rand() % (linhas-2)));
    set_position_final(int(rand() % (linhas-2)));
    cout<< get_position_final() << endl;
    lab[get_position_start()][0] = 5;
    lab[get_position_final()][int(colunas-1)] = 2;

    return lab;
}

void Gerador::printLab(vector<vector<int>> lab, vector<int> operador){
    int linhas = lab.size();
    int colunas = lab.empty() ? 0: lab[0].size();
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == operador[0] && j == operador[1]){ 
                cout << " P ";
            }
            else if(lab[i][j] == 0){ 
                cout << " * ";
            }
            else if(lab[i][j] == 1){ 
                cout << " # ";
            }
            else if (lab[i][j] == 2){ 
                cout << "   ";
            }
            else if (lab[i][j] == 3){ 
                cout << " + ";
            }
            else if (lab[i][j] == 5){ 
                cout << " S ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
