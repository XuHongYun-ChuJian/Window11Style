#pragma once

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

private slots:
    // void on_horizonalBtn_clicked();
    // void on_verticalBtn_clicked();

private:
    void init();
    void initMenuAndToolBar();

    void updateActionIcons();
    void loadChangelog();

private:
    Ui::MainWindow *ui;

    QToolBar* m_toolBar{nullptr};
};
