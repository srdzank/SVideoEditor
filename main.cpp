
#include "mainwindow.h"

#include <QApplication>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get the path to the executable
    QString exePath = QCoreApplication::applicationDirPath();

    // Construct the path to the icon file relative to the executable
    QString iconPath = QDir(exePath).filePath("start.png");

    // Load the icon from the file
    QIcon icon(iconPath);
    // Set the application icon
    QApplication::setWindowIcon(icon);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
