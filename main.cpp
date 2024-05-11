#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

const int MAX = 100;

class Disciplina {
private:
    int codigo, creditos, ano, semestre;
    double nota1, nota2, media;
    string nome, professor;

public:
    void ler();
    void calculoMedia();
    int getCodigo();
    int getCreditos();
    int getAno();
    int getSemestre();
    double getMedia();
    string getNome();
    string getProfessor();
};

class Historico {
private:
    Disciplina vetor[MAX];
    int quantidade = 0;
    double cr;

public:
    Historico();
    int menu();
    void coeficienteRendimento();
    void inserir(Disciplina disciplina);
    void remover();
    void alterar(Disciplina disciplina);
    void listarDisciplinas();
    void listarPorAno();
    void listarPorNome();
    void listarHistorico();
};

void Disciplina::ler() {
    cin >> codigo;
    cin.ignore();
    getline(cin, nome);
    getline(cin, professor);
    cin >> creditos >> ano >> semestre >> nota1 >> nota2;
}

void Disciplina::calculoMedia() {
    media = (nota1 + 2 * nota2) / 3;
}

int Disciplina::getCodigo() {
    return codigo;
}

int Disciplina::getCreditos() {
    return creditos;
}

int Disciplina::getAno() {
    return ano;
}

int Disciplina::getSemestre() {
    return semestre;
}

double Disciplina::getMedia() {
    return media;
}

string Disciplina::getNome() {
    return nome;
}

string Disciplina::getProfessor() {
    return professor;
}

Historico::Historico() {
    quantidade = 0;
}

int Historico::menu() {
    int opcaoMenu;

    do {
        cout << "1 - inserir nova disciplina" << endl;
        cout << "2 - remover disciplina pelo codigo" << endl;
        cout << "3 - alterar disciplina pelo codigo" << endl;
        cout << "4 - listar todas as disciplinas" << endl;
        cout << "5 - listar disciplinas de um ano/semestre" << endl;
        cout << "6 - listar disciplinas pelo nome/professor" << endl;
        cout << "7 - Historico" << endl;
        cout << "8 - sair" << endl;
        cout << "Entre com a sua opcao:" << endl;
        cin >> opcaoMenu;
    } while(opcaoMenu < 1 || opcaoMenu > 8);

    return opcaoMenu;
}

void Historico::coeficienteRendimento() {
    int somaCreditos = 0;
    cr = 0;

    for(int i = 0; i < quantidade; i++) {
        cr += vetor[i].getMedia() * vetor[i].getCreditos();
        somaCreditos += vetor[i].getCreditos();
    }

    somaCreditos == 0 ? cr = 0 : cr = cr / somaCreditos;
}

void Historico::inserir(Disciplina disciplina) {
    vetor[quantidade] = disciplina;
    quantidade++;

    cout << "Disciplina inserida com sucesso!" << endl;
}

void Historico::remover() {
    int codigo, i, j;
    bool removeu = false;

    cin >> codigo;

    for(i = 0; i < quantidade; i++) {
        if(vetor[i].getCodigo() == codigo) {
            for(j = i; j < quantidade - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            quantidade--;
            removeu = true;
            cout << "Disciplina removida com sucesso!" << endl;
        }
    }

    if(!removeu) {
        cout << "Disciplina não encontrada!" << endl;
    }
}


void Historico::alterar(Disciplina disciplina) {
    int codigo, i;
    bool alterou = false;

    cin >> codigo;

    for(i = 0; i < quantidade; i++) {
        if(vetor[i].getCodigo() == codigo) {
            disciplina.ler();
            vetor[i] = disciplina;
            disciplina.calculoMedia();
            cout << "Disciplina alterada com sucesso!" << endl;
            alterou = true;
        }
    }

    if(!alterou) {
        cout << "Disciplina nao encontrada!" << endl;
    }
}

void Historico::listarDisciplinas() {
    string ok;

    cout << setprecision(2) << fixed;
    cout << "Cod. " << left << setw(50) << setfill(' ') << "Nome" << " Cred " << " Ano/S " << "Media" << endl;
    for(int i = 0; i < quantidade; i++) {
        cout << right << setw(4) << setfill('0') << vetor[i].getCodigo() << " " << left << setw(50) << setfill(' ') << vetor[i].getNome() << " " << right << setw(4) << setfill(' ') << vetor[i].getCreditos() << " " << setw(4) << vetor[i].getAno() << "/" << setw(1) << vetor[i].getSemestre() << " " << right << setw(5) << setfill('0') << vetor[i].getMedia() << endl;
    }

    cin >> ok;
    if(ok != "Ok") {
        cin >> ok;
    }
}

void Historico::listarPorAno() {
    int ano, semestre;
    string ok;

    cin >> ano >> semestre;

    cout << setprecision(2) << fixed;
    cout << "Cod. " << left << setw(50) << setfill(' ') << "Nome" << " Cred " << " Ano/S " << "Media" << endl;
    for(int i = 0; i < quantidade; i++) {
        if(ano == vetor[i].getAno() && semestre == vetor[i].getSemestre()) {
            cout << right << setw(4) << setfill('0') << vetor[i].getCodigo() << " " << left << setw(50) << setfill(' ') << vetor[i].getNome() << " " << right << setw(4) << setfill(' ') << vetor[i].getCreditos() << " " << setw(4) << vetor[i].getAno() << "/" << setw(1) << vetor[i].getSemestre() << " " << right << setw(5) << setfill('0') << vetor[i].getMedia() << endl;
        }
    }

    cin >> ok;
    if(ok != "Ok") {
        cin >> ok;
    }
}

void Historico::listarPorNome() {
    string nome;
    string ok;

    cin.ignore();
    getline(cin, nome);

    cout << setprecision(2) << fixed;
    cout << "Cod. " << left << setw(50) << setfill(' ') << "Nome" << " Cred " << " Ano/S " << "Media" << endl;
    for(int i = 0; i < quantidade; i++) {
        if(vetor[i].getNome().find(nome) != string::npos || vetor[i].getProfessor().find(nome) != string::npos) {
            cout << right << setw(4) << setfill('0') << vetor[i].getCodigo() << " " << left << setw(50) << setfill(' ') << vetor[i].getNome() << " " << right << setw(4) << setfill(' ') << vetor[i].getCreditos() << " " << setw(4) << vetor[i].getAno() << "/" << setw(1) << vetor[i].getSemestre() << " " << right << setw(5) << setfill('0') << vetor[i].getMedia() << endl;
        }
    }

    cin >> ok;
    if(ok != "Ok") {
        cin >> ok;
    }
}

void Historico::listarHistorico() {
    string ok;

    cout << setprecision(2) << fixed;
    cout << "Cod. " << left << setw(50) << setfill(' ') << "Nome" << " Cred " << " Ano/S " << "Media" << endl;
    for(int i = 0; i < quantidade; i++) {
        cout << right << setw(4) << setfill('0') << vetor[i].getCodigo() << " " << left << setw(50) << setfill(' ') << vetor[i].getNome() << " " << right << setw(4) << setfill(' ') << vetor[i].getCreditos() << " " << setw(4) << vetor[i].getAno() << "/" << setw(1) << vetor[i].getSemestre() << " " << right << setw(5) << setfill('0') << vetor[i].getMedia() << endl;
    }
    cout << left << setw(68) << setfill(' ') << "Coeficiente de Rendimento" << right << setw(5) << setfill('0') << cr << endl;

    cin >> ok;
    if(ok != "Ok") {
        cin >> ok;
    }
}

int main() {
    Disciplina disciplina;
    Historico historico;
    bool terminou = false;

    while(!terminou) {
        switch (historico.menu()) {
            case 1:
                disciplina.ler();
                disciplina.calculoMedia();
                historico.inserir(disciplina);
                break;

            case 2:
                historico.remover();
                historico.coeficienteRendimento();
                break;

            case 3:
                historico.alterar(disciplina);
                historico.coeficienteRendimento();
                break;

            case 4:
                historico.listarDisciplinas();
                break;

            case 5:
                historico.listarPorAno();
                break;

            case 6:
                historico.listarPorNome();
                break;

            case 7:
                historico.coeficienteRendimento();
                historico.listarHistorico();
                break;

            case 8:
                cout << "Obrigado por utilizar o programa de cadastro, volte sempre!" << endl;
                terminou = true;
                break;
        }
    }

    return 0;
}