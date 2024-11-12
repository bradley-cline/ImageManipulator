#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage m_originalImage = QImage();
    QImage m_processedImage = QImage();
    QString m_imageFile;
    bool m_processing = false;
    void RefreshImages();

private slots:
    void Average();
    void Browse();
    void Flip();
    void Greyscale();
    void Process();
    void Reset();

};
#endif // MAINWINDOW_H
