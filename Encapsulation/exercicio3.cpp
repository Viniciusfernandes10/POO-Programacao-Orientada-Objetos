#include <iostream>
#include <string>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    int getDia(){ return dia; }
    int getMes(){ return mes; }
    int getAno(){ return ano; }

    Data clone(){
        return Data(dia, mes, ano);
    }
};

class Voo {
private:
    int numeroVoo;
    Data data;
    bool cadeiras[100];

public:
    Voo(int numeroVoo, Data data) : data(data) {
        this->numeroVoo = numeroVoo;
        for (int i = 0; i < 100; i++){
            cadeiras[i] = false; 
        }
    }

    int proximoLivre(){
        for (int i = 0; i < 100; i++){
            if (!cadeiras[i]){
                return i + 1; 
            }
        }
        return -1; 
    }

    bool verifica(int numeroCadeira){
        return cadeiras[numeroCadeira - 1];
    }

    bool ocupa(int numeroCadeira){
        if (cadeiras[numeroCadeira - 1]){
            return false; 
        }
        cadeiras[numeroCadeira - 1] = true;
        return true; 
    }

    int vagas(){
        int livres = 0;
        for (int i = 0; i < 100; i++){
            if (!cadeiras[i]){
                livres++;
            }
        }
        return livres;
    }

    int getVoo(){
        return numeroVoo;
    }

    Data getData(){
        return data;
    }

    Voo clone(){
        Voo novoVoo(numeroVoo, data.clone());
        for (int i = 0; i < 100; i++){
            if (cadeiras[i]){
                novoVoo.ocupa(i + 1);
            }
        }
        return novoVoo;
    }
};

int main(){
    Data dataVoo(25, 8, 2026);
    Voo voo1(101, dataVoo);

    cout << "Vôo número: " << voo1.getVoo() << endl;
    cout << "Vagas disponíveis: " << voo1.vagas() << endl;
    cout << "Próxima cadeira livre: " << voo1.proximoLivre() << endl;

    voo1.ocupa(1);
    voo1.ocupa(2);

    cout << "Cadeira 1 ocupada? " << voo1.verifica(1) << endl;
    cout << "Vagas disponíveis: " << voo1.vagas() << endl;
    cout << "Próxima cadeira livre: " << voo1.proximoLivre() << endl;

    bool sucesso = voo1.ocupa(1); // já ocupada
    cout << "Ocupar cadeira 1 de novo: " << sucesso << endl; 
}
