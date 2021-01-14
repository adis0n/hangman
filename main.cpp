#include "mainwindow.h"
#include "game.h"
#include "player.h"
#include <QApplication>
#include <QtDebug>
#include <QDebug>
#include <QPixmap>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Player *player = new Player();
    MainWindow window(*player);
    window.setFixedSize(180,140);
    window.show();
    window.setWindowTitle("hangman");
    window.setword("dupskoo");
    return a.exec();
}
