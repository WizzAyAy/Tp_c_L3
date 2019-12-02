#include "calcul.hh"
#include <string>
#include <iostream>

calcul::calcul()
    :QWidget(){
    QHBoxLayout* layouth = new QHBoxLayout;;
    _operande1 = new QLineEdit("", this);
    _operande2 = new QLineEdit("", this);
    _operateur = new QComboBox(this);
    _operateur->addItem("+");
    _operateur->addItem("-");
    _operateur->addItem("*");
    _operateur->addItem("/");
    _calculer = new QPushButton("=", this);
    _resultat = new QLabel("", this);
    _quitter = new QPushButton("Leave", this);
    layouth->addWidget(_operande1);
    layouth->addWidget(_operateur);
    layouth->addWidget(_operande2);
    layouth->addWidget(_calculer);
    layouth->addWidget(_resultat);
    layouth->addWidget(_quitter);
    setLayout(layouth);

    QObject::connect(_quitter, &QPushButton::released, this, &calcul::close);
    QObject::connect(_calculer, &QPushButton::clicked, this, &calcul::onclickcalcul);
    QObject::connect(_operateur, &QComboBox::currentTextChanged, this, &calcul::onclickcalcul);
    QObject::connect(_operande1, &QLineEdit::textChanged, this, &calcul::onclickcalcul);
    QObject::connect(_operande2, &QLineEdit::textChanged, this, &calcul::onclickcalcul);



}

void calcul::onclickcalcul()
{
    QString op1 = _operande1->text();
    std::string o1 = op1.toStdString();
    if(o1 == "") o1 = "0";
    QString op2 = _operande2->text();
    std::string o2 = op2.toStdString();
    if(o2 == "") o2 = "0";
    float x1;
    try{
        x1 = std::stof(o1);
    }
    catch(std::invalid_argument){
        std::cout << "mauvais arg\n";
    }
    std::cout << "x1 = " << x1 << std::endl;
    float x2;
    try{
    x2 = std::stof(o2);
    }
    catch(std::invalid_argument){
        std::cout << "mauvais arg\n";
    }
    std::cout << "x2 = " << x2 << std::endl;

    QString operateur = _operateur->currentText();
    std::string ope = operateur.toStdString();
    std::cout << "ope = " << ope << std::endl;

    float result;

    if(ope == "+") result = x1 + x2;
    if(ope == "-") result = x1 - x2;
    if(ope == "*") result = x1 * x2;
    if(ope == "/"){
    if (x2 == 0) result = 0;
        else     result = x1 / x2;
    }

    std::cout << result << std::endl;

    std::string resu = std::to_string(result);
    QString re = QString::fromStdString(resu);
    _resultat->setText(re);

}
