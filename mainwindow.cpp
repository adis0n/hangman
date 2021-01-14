#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Player &player, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handlebutton);
    this->player =&player;
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::handleletter);
    ui->label_2->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->label_5->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlebutton(){
    this->setFixedSize(1600,800);
    this->move(10,10);
    ui->pushButton->setVisible(false);
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->label_2->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->pushButton_2->setVisible(true);
    player->nick=ui->lineEdit->text().toStdString();
    ui->label_5->setText(QString::fromStdString(player->nick));
    ui->label_5->setVisible(true);


}

void MainWindow::handleletter(){
    QString temp;
    temp = ui->lineEdit_2->text();
    letter=temp.toStdString()[0];
    ui->lineEdit_2->setText("");
    this->editword(letter);
    cerr << "podano litere: " << letter << '\n';
}

void MainWindow::setword(string word){
    this->length = int(word.length());
    char* temp = new char[this->length-1];
    for (int i=0; i<=this->length-1; i++){
        temp[i]='_';
    }
    QString text;
    std::strcpy(this->word, word.c_str());
    text=QString::fromStdString(temp);
    ui->label_3->setText(text);
}

void MainWindow::editword(char letter){
    char* temp = new char[this->length-1];
    //to potem pojdzie na ekran
    string temp2=  ui->label_3->text().toStdString();//a to jest to co na ekranie bylo
    std::strcpy(temp,temp2.c_str());

    for (int i=0; i<=this->length-1; i++){  //sprawdz czy ta literka nie byla juz zgadywana
        if (letter==temp[i]){
            player->lifedown();                     //a jesli byla to zycie w dol
            cerr << player->lives;
            return;
        }
    }

    for (int i=0; i<= this->length-1; i++){
         // a teraz sprawdzamy czy literka wystepuje w wyrazie
        if (this->word[i]==letter){
            temp[i]=letter;
            player->addpoint();
        }
    }
    ui->label_3->setText(temp);

}
/*
void MainWindow::checkletter(char letter, char* word){
    char* temp = new char[length-1];
    for (int i = 0; i <= int(strlen(word)); i++) {
        if (letter==word[i]){
            temp[i]=letter;
        }
}
    this->setword(word);

}
*/
