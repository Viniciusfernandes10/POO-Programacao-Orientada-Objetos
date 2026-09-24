#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
        int matricula;
        string nome;
        double prova1;
        double prova2;
        double trabalho;
    
    public:
        Aluno(int matricula, string nome, double prova1, double prova2, double trabalho){
            this->matricula = matricula;
            this->nome = nome;
            this->prova1 = prova1;
            this->prova2 = prova2;
            this->trabalho = trabalho;  
        }
    
    double media(){
        return ((prova1 * 2.5 + prova2 * 2.5) + (trabalho * 2) ) / 7;
    }
    
    double final(){
        if (media() >= 6){
            return 0;
        }
        if (media() < 4){
            return 0;
        }
        else{
            return 10 - media();
        }
    }
};

int main(){
    Aluno aluno1(123456789, "Vinícius", 5, 5, 5);
    cout << "Média: "<< aluno1.media() << endl;
    cout << "Quanto o aluno precisa para passar: "<< aluno1.final() << endl;
    return 0;
}