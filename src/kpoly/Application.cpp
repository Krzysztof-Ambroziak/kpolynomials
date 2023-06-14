#include <QApplication>
#include "../gui/Window.hpp"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    
    Window window;
    window.show();
    
    return QApplication::exec();
}
