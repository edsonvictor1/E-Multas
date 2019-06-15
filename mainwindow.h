#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QInputDialog>
#include <QWidget>

#include "veiculo.h"
#include "veiculos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Veiculo a;
private slots:

    void on_btnInserir_clicked();

    void on_btnOrdenarPlaca_clicked();

    void on_btnOrdenarVelocidade_clicked();

    void salvar();

    void carregar();

    void on_btnLimparTabela_clicked();

    void on_tabelaDados_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    Veiculos veiculos;
    void atualizarDados();
    void atualizarTabela();
    void inserirVeiculoNaTabela(Veiculo a, int row);


};
#endif // MAINWINDOW_H
