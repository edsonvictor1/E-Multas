#ifndef VEICULO_H
#define VEICULO_H

#include <QObject>

class Veiculo
{

private:
    QString placa;
    double velocidade;
    double limite;
    QString situacao;
    QString infracao;
    double multa;
    QString pontos;
    QString CNH;


public:
    Veiculo();
    QString getPlaca() const;
    void setPlaca(const QString &value);
    double getVelocidade() const;
    void setVelocidade(double value);
    double getLimite() const;
    void setLimite(double value);

    QString Situacao(double limite, double velocidade);
    QString getSituacao();
    QString Infracao(double limite, double velocidade);
    QString getInfracao();
    QString Multa(double limite, double velocidade);
    double getMulta();
    QString Pontos(double limite, double velocidade);
    QString getPontos();
    QString statusCNH(double limite, double velocidade);
    QString getStatusCNH();
};

#endif // VEICULO_H
