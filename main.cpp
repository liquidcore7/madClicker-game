#include "mainImpl.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MadClicker wnd;
    wnd.show();
    return app.exec();
}
