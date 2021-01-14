#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include "QPushButton"
#include <QDebug>
#include <cstring>
#include <string.h>
#include <iostream>
#include "player.h"
#include <QPixmap>



using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Player *player;
    MainWindow(Player &player, QWidget *parent = nullptr);
    ~MainWindow();
    void handlebutton();
    void handleletter();
    char letter;
    void setword(string word);
    void editword(char letter);
    int length;
    void checkletter(char letter, char* word);
    char* word = new char;

private:
    Ui::MainWindow *ui;};
#endif // MAINWINDOW_H
