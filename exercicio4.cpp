#include <iostream>
using namespace std;

class Gabarito {
public:
    char respostaQuestao(int numeroQuestao){
        char gabaritoReal[16] = {' ', 
            'A','B','C','D','E','A','B','C','D','E',
            'A','B','C','D','E'};
        return gabaritoReal[numeroQuestao];
    }
};

class Prova {
private:
    Gabarito gabarito;
    char respostasAluno[15];
    int questaoAtual;

public:
    Prova(Gabarito gabarito) : gabarito(gabarito) {
        this->questaoAtual = 0;
    }

    void respostaAluno(char resposta){
        if (questaoAtual < 15){
            respostasAluno[questaoAtual] = resposta;
            questaoAtual++;
        }
    }

    int acertos(){
        int total = 0;
        for (int i = 0; i < 15; i++){
            if (respostasAluno[i] == gabarito.respostaQuestao(i + 1)){
                total++;
            }
        }
        return total;
    }

    double nota(){
        double soma = 0;
        for (int i = 0; i < 10; i++){ 
            if (respostasAluno[i] == gabarito.respostaQuestao(i + 1)){
                soma += 0.5;
            }
        }
        for (int i = 10; i < 15; i++){ 
            if (respostasAluno[i] == gabarito.respostaQuestao(i + 1)){
                soma += 1.0;
            }
        }
        return soma;
    }

    double maior(Prova outraProva){
        if (this->acertos() > outraProva.acertos()){
            return this->nota();
        }
        if (this->acertos() < outraProva.acertos()){
            return outraProva.nota();
        }
        
        if (this->nota() >= outraProva.nota()){
            return this->nota(); 
        }
        return outraProva.nota();
    }
};

int main(){
    Gabarito gab;
    Prova prova1(gab);
    Prova prova2(gab);

    // prova1 acerta tudo
    char respostasP1[15] = {'A','B','C','D','E','A','B','C','D','E','A','B','C','D','E'};
    for (int i = 0; i < 15; i++){
        prova1.respostaAluno(respostasP1[i]);
    }

    // prova2 erra as 5 últimas (as que valem mais)
    char respostasP2[15] = {'A','B','C','D','E','A','B','C','D','E','X','X','X','X','X'};
    for (int i = 0; i < 15; i++){
        prova2.respostaAluno(respostasP2[i]);
    }

    cout << "Prova1 - acertos: " << prova1.acertos() << " | nota: " << prova1.nota() << endl;
    cout << "Prova2 - acertos: " << prova2.acertos() << " | nota: " << prova2.nota() << endl;
    cout << "Maior nota entre as duas: " << prova1.maior(prova2) << endl;
}