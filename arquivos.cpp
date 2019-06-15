/*#include "arquivos.h"

arquivos::arquivos()
{

}


bool arquivos::salvarVeiculos(QString &arquivo, veiculos &lista)
{
    {
        QFile arq(arquivo);

        if(!arq.open(QIODevice::WriteOnly))
            return false;

        QTextStream out(&arq);

        for(int i = 0; i < veiculos.size(); i++){
            out << lista[i].getPlaca() << ","
                << lista[i].getVelocidade() << ","
                << lista[i].getSituacao() << ","
                << lista[i].getInfracao() << ","
                << lista[i].getMulta() << ","
                << lista[i].getPontos() << ",";
                << lista[i].getStatusCNH() << "\n";
        }

           arq.close();
           return true;
    }
}

bool arquivos::carregarVeiculos(QString &arquivo, Veiculos &lista)
{
    QFile arq(arquivo);

       if(!arq.open(QIODevice::ReadOnly)){
           return false;
       }

       QTextStream opa(&arq);

       QString line;

       while(!opa.atEnd()){
           line = opa.readLine();

           QStringList separados = line.split(",");

           if(separados.size() < 6){
               Filme f(separados[0],separados[1],separados[2].toFloat(),separados[3].toFloat(),separados[4].toInt());
               lista.inserirFilme(f);
           }else{
               Filme f(separados[0],separados[1],separados[2].toFloat(),separados[3].toFloat(),separados[4].toInt(),separados[5]);
               lista.inserirFilme(f);
           }

       }
       arq.close();
       return true;
}
*/
