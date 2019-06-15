#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()),this,SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()),this,SLOT(carregar()));
}

void MainWindow::atualizarDados()
{
    ui->total_veiculos->setText(QString::number(veiculos.getVeiculosMultados()));
    ui->total_multas->setText(QString::number(veiculos.getSomaMultas()));

}

void MainWindow::atualizarTabela()
{
    ui->tabelaDados->clearContents();
    for(int i=0; i<veiculos.size();i++){
        inserirVeiculoNaTabela(veiculos[i],i);
    }

}

void MainWindow::inserirVeiculoNaTabela(Veiculo a, int row)
{
    ui->tabelaDados->setItem(row,0,new QTableWidgetItem(a.getPlaca()));
    ui->tabelaDados->setItem(row,1,new QTableWidgetItem(QString::number(a.getVelocidade())));
    ui->tabelaDados->setItem(row,2,new QTableWidgetItem(a.Situacao(a.getLimite(),a.getVelocidade())));
    ui->tabelaDados->setItem(row,3,new QTableWidgetItem(a.Infracao(a.getLimite(),a.getVelocidade())));
    ui->tabelaDados->setItem(row,4,new QTableWidgetItem(a.Multa(a.getLimite(),a.getVelocidade())));
    ui->tabelaDados->setItem(row,5,new QTableWidgetItem(a.Pontos(a.getLimite(),a.getVelocidade())));
    ui->tabelaDados->setItem(row,6,new QTableWidgetItem(a.statusCNH(a.getLimite(),a.getVelocidade())));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnInserir_clicked()
{
    Veiculo veiculo;

    if(ui->entradaPlaca->text().size() != 0  and ui->entradaVelocidade->text().size() != 0  and ui->cb_limite->currentText() != "Selecione uma opção"){
        veiculo.setPlaca(ui->entradaPlaca->text());
        veiculo.setVelocidade(ui->entradaVelocidade->text().toDouble());
        QString str = ui->cb_limite->currentText();
        double lim = str.toDouble();
        veiculo.setLimite(lim);
        veiculo.Multa(veiculo.getLimite(), veiculo.getVelocidade());
    int row = ui->tabelaDados->rowCount();
    ui->tabelaDados->insertRow(row);
    inserirVeiculoNaTabela(veiculo,row);

    veiculos.inserirVeiculo(veiculo);
    ui->entradaPlaca->clear();
    ui->entradaVelocidade->clear();
    ui->cb_limite->setCurrentText("Selecione uma opção");
    atualizarDados();

}}

void MainWindow::on_btnOrdenarPlaca_clicked()
{
    veiculos.ordenarPorPlaca();
    atualizarTabela();
}

void MainWindow::on_btnOrdenarVelocidade_clicked()
{
    veiculos.ordenarPorVelocidade();
    atualizarTabela();
}

void MainWindow::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                       "Lista de veículos",
                                                       "",
                                                       "CSV(*.csv)");
    veiculos.salvarVeiculos(nomeArquivo);

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                       "Lista de veículos",
                                                       "",
                                                       "CSV(*.csv)");
    veiculos.carregarVeiculos(nomeArquivo);
    for(int i=0;i<veiculos.size();i++){
        ui->tabelaDados->insertRow(i);
        a.setPlaca(veiculos[i].getPlaca());
        a.setVelocidade(veiculos[i].getVelocidade());
        a.setLimite(veiculos[i].getLimite());
        a.Situacao(veiculos[i].getVelocidade(), veiculos[i].getLimite());
        a.Infracao(veiculos[i].getVelocidade(), veiculos[i].getLimite());
        a.Multa(veiculos[i].getVelocidade(), veiculos[i].getLimite());
        a.Pontos(veiculos[i].getVelocidade(), veiculos[i].getLimite());
        a.statusCNH(veiculos[i].getVelocidade(), veiculos[i].getLimite());
        inserirVeiculoNaTabela(veiculos[i],i);
    }
}

void MainWindow::on_btnLimparTabela_clicked()
{
      for (int i = 0; i<veiculos.size(); i++){
          ui->tabelaDados->removeRow(i);
      }
 }

void MainWindow::on_tabelaDados_cellDoubleClicked(int row, int column)
{
    if(column == 0){
       QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você deseja editar a placa?");

       if(resp == QMessageBox::Yes){
           bool ok;
           QString txt = QInputDialog::getText(this, "Alterar Placa", "Placa", QLineEdit::Normal,"",&ok);
           if(ok and !txt.isEmpty()){
              a.setPlaca(txt);
              a.setVelocidade(veiculos[row].getVelocidade());
              a.setLimite(veiculos[row].getLimite());
              a.Situacao(a.getLimite(), a.getVelocidade());
              a.Infracao(a.getLimite(), a.getVelocidade());
              a.Multa(a.getLimite(), a.getVelocidade());
              a.Pontos(a.getLimite(), a.getVelocidade());
              a.statusCNH(a.getLimite(), a.getVelocidade());
           }
           }

           inserirVeiculoNaTabela(a, row);

           }
    else if(column == 1){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você deseja editar a velocidade do veículo?");

        if(resp == QMessageBox::Yes){
            bool ok;
            QString txt = QInputDialog::getText(this, "Alterar Velocidade", "Velocidade", QLineEdit::Normal,"",&ok);
            if(ok and !txt.isEmpty()){
                a.setVelocidade(txt.toDouble());
                a.setPlaca(veiculos[row].getPlaca());
                a.setLimite(veiculos[row].getLimite());
                a.Situacao(a.getLimite(), a.getVelocidade());
                a.Infracao(a.getLimite(), a.getVelocidade());
                a.Multa(a.getLimite(), a.getVelocidade());
                a.Pontos(a.getLimite(), a.getVelocidade());
                a.statusCNH(a.getLimite(), a.getVelocidade());
            }
            inserirVeiculoNaTabela(a,row);

    }
}}
