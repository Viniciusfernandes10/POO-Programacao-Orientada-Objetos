#include <iostream>
#include <string>

using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

    bool ehBissexto(int ano){
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }

    bool dataValida(int dia, int mes, int ano){
        if (mes < 1 || mes > 12){
            return false;
        }
        if (dia < 1){
            return false;
        }

        int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int limite = diasNoMes[mes - 1];

        if (mes == 2 && ehBissexto(ano)){
            limite = 29;
        }

        if (dia > limite){
            return false;
        }

        return true; 
    }

public:
    Data(int dia, int mes, int ano) {
        if (dataValida(dia, mes, ano)) {
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        } else {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1;
        }
    }

    int compara(Data outraData){
        if (ano == outraData.ano && mes == outraData.mes && dia == outraData.dia){
            return 0;
        }
        if (ano != outraData.ano){
            return (ano > outraData.ano) ? 1 : -1;
        }
        if (mes != outraData.mes){
            return (mes > outraData.mes) ? 1 : -1;
        }
        return (dia > outraData.dia) ? 1 : -1;
    }

    int getDia(){
        return dia;
    }

    int getMes(){
        return mes;
    }

    string getMesExtenso(){
        string meses[12] = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        };
        return meses[mes - 1];
    }

    int getAno(){
        return ano;
    }

    bool isBissexto(){
        return ehBissexto(ano);
    }

    Data clone(){
        return Data(dia, mes, ano);
    }
};

int main(){
    Data data1(25, 8, 2026);
    cout << "Dia: "  << data1.getDia() << endl;
    cout << "Mes: " << data1.getMes() << endl;
    cout << "Mes por extenso: " << data1.getMesExtenso() << endl;
    cout << "Ano: " << data1.getAno() << endl;
    if (data1.isBissexto()){
        cout << "Ano Bissexto" << endl;
    } else {
        cout << "Ano não Bissexto" << endl;
    }

    Data data2(10, 8, 2024);
    cout << "Comparação: " << data1.compara(data2) << endl;
}
