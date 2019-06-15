#include "veiculo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

Veiculo::Veiculo()
{

}

QString Veiculo::getPlaca() const
{
    return placa;
}

void Veiculo::setPlaca(const QString &value)
{
    placa = value;
}

double Veiculo::getVelocidade() const
{
    return velocidade;
}

void Veiculo::setVelocidade(double value)
{

    velocidade = value;
}

double Veiculo::getLimite() const
{
    return limite;
}

void Veiculo::setLimite(double value)
{
    limite = value;
}

QString Veiculo::Situacao(double limite, double velocidade)
{
    QString situacao;

    if (velocidade > limite or velocidade < 0.5*(limite))
         situacao = "Multado";
     else
         situacao = "Isento";

    return situacao;
    //    return velocidade > limite ? "Multado" : "Isento" || velocidade < 0.5*(limite) ? "Multado" : "Isento";
}

QString Veiculo::getSituacao()
{
    return situacao;
}

QString Veiculo::Infracao(double limite, double velocidade)
{
    QString infracao;
    if (velocidade > limite){
        if (velocidade <= 1.2*limite)
            infracao = "Infração média";
        else if (velocidade <= 1.5*limite)
            infracao = "Infração grave";
        else
            infracao = "Infração gravíssima";
    }
    else if (velocidade < 0.5*(limite))
        infracao = "Infração média";
    else
        return "-";

    return infracao;
}

QString Veiculo::getInfracao()
{
    return infracao;
}
QString Veiculo::Multa(double limite, double velocidade)
{
    if(velocidade > limite){
        if(velocidade <= 1.2*limite)
            multa = 130.16;
        else if (velocidade <= 1.5*limite)
            multa = 195.23;
        else if (velocidade > 1.5*limite)
            multa = 880.41;
    }
    else if (velocidade < 0.5*limite)
        multa = 130.16;
    else
        return "-";

    return QString::number(multa);

}

double Veiculo::getMulta()
{
    return multa;
}

QString Veiculo::Pontos(double limite, double velocidade)
{
    int pontos;

    if(velocidade > limite){
        if(velocidade <= 1.2*limite)
            pontos = 4;
        else if (velocidade <= 1.5*limite)
           pontos = 5;
        else
            pontos = 7;
    }
    else if (velocidade < 0.5*limite)
        pontos = 4;
    else
        return "-";
    return QString::number(pontos);
}

QString Veiculo::getPontos()
{
    return pontos;
}

QString Veiculo::statusCNH(double limite, double velocidade)
{
    QString statusCNH;

    if(velocidade > limite){
        if(velocidade <= 1.2*limite)
             statusCNH = "-";
        else if (velocidade <= 1.5*limite)
           statusCNH = "-";
        else
            statusCNH = "Suspensa";
    }
    else if (velocidade < 0.5*limite)
        statusCNH = "-";
    else
        return "-";

    return statusCNH;
}

QString Veiculo::getStatusCNH()
{
    return CNH;
}


