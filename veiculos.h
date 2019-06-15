#ifndef VEICULOS_H
#define VEICULOS_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "veiculo.h"

class Veiculos
{
private:
    QVector<Veiculo> veiculos;
    int veiculosMultados;
    double somaMultas;

public:
    Veiculos();
    void inserirVeiculo(Veiculo a);
    Veiculo operator[](int i);
    void ordenarPorPlaca();
    void ordenarPorVelocidade();
    int size();
    int getVeiculosMultados();
    double getSomaMultas();
    bool salvarVeiculos(QString arquivo);
    bool carregarVeiculos(QString arquivo);
};

bool compararPorPlaca(Veiculo a, Veiculo b);
bool compararPorVelocidade(Veiculo a, Veiculo b);

#endif // VEICULOS_H
