#pragma once
#include <QWidget>
#include <QtWidgets>

class calcul : public QWidget
{
public:
    calcul();
    void onclickquiter(QKeyEvent *event);
    void onclickcalcul();

     QLineEdit* _operande1;
     QLineEdit* _operande2;
     QComboBox* _operateur;
     QLabel* _resultat;
     QPushButton* _calculer;
     QPushButton* _quitter;
};

