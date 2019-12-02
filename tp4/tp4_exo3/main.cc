#include <iostream>
#include <calcul.hh>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    calcul c;
    c.show();
    return app.exec();
}


