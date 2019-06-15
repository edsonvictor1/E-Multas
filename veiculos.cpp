#include "veiculos.h"
#include <algorithm>

Veiculos::Veiculos()
{

}

void Veiculos::inserirVeiculo(Veiculo a)
{
    veiculos.push_back(a);
}

Veiculo Veiculos::operator[](int i)
{
    return veiculos[i];
}

void Veiculos::ordenarPorPlaca()
{
    std::stable_sort(veiculos.begin(),veiculos.end(),compararPorPlaca);
}

void Veiculos::ordenarPorVelocidade()
{
    std::stable_sort(veiculos.begin(),veiculos.end(),compararPorVelocidade);
}

int Veiculos::size()
{
    return veiculos.size();
}


int Veiculos::getVeiculosMultados()
{
    veiculosMultados = 0;
    for (int i=0; i<veiculos.size(); i++){
       if (veiculos[i].Situacao(veiculos[i].getLimite(),veiculos[i].getVelocidade())== "Multado"){
        veiculosMultados++;
    }}

    return veiculosMultados;
}

double Veiculos::getSomaMultas()
{
    somaMultas = 0;
    for(int i=0; i<veiculos.size(); i++){
      somaMultas += double(veiculos[i].getMulta());
    }
        return somaMultas;
}

bool Veiculos::salvarVeiculos(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Veiculo a : veiculos){
        linha = a.getPlaca() + ',' + QString::number(a.getVelocidade()) + '\n';
        file.write(linha.toLocal8Bit());
    }
    return true;

}

bool Veiculos::carregarVeiculos(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Veiculo a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setPlaca(dados[0]);
        a.setVelocidade(dados[1].toDouble());
        inserirVeiculo(a);
    }
    return true;

}

    bool compararPorPlaca(Veiculo a, Veiculo b)
    {
        return a.getPlaca()<b.getPlaca();
    }
    bool compararPorVelocidade(Veiculo a, Veiculo b)
    {
        return a.getVelocidade()>b.getVelocidade();
    }

