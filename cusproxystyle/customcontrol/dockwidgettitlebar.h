#pragma once
#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>
#include <QDockWidget>

class DockWidgetTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit DockWidgetTitleBar(QDockWidget *dock);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QToolButton* createButton(const QChar &icon);

    QDockWidget *m_dock;
    QLabel *m_icon;
    QLabel *m_title;
    QToolButton *m_btnFloat;
    QToolButton *m_btnClose;
};




