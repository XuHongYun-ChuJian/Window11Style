#include <QApplication>
#include <QFont>
#include <QMenu>
#include <QTextEdit>
#include "MainWindow.h"
#include "CusProxyStyle.h"
#include "qboxlayout.h"
#include "qcombobox.h"
#include "qdebug.h"
#include "qevent.h"
#include "qlineedit.h"

int main(int argc, char *argv[])
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#else
    qputenv("QT_SCALE_FACTOR", "1.5");
#endif
#endif

    QApplication a(argc, argv);

    QFont font = qApp->font();
    font.setPixelSize(13);
    font.setFamily("Microsoft YaHei");
    font.setHintingPreference(QFont::PreferNoHinting);
    qApp->setFont(font);

    // 设置自定义 Win11 样式
    qApp->setStyle(new CusProxyStyle());
    // a.setStyle("windows11");

    // 创建并显示主窗口
    MainWindow w;

    w.show();

    return a.exec();
}

//menu popup会有阴影，如果不想要阴影，可以重写contextMenuEvent事件，直接调用exec()方法显示菜单，而不是popup()方法
//已知QLineEdit, QComboBox, QTextEdit
// void QLineEdit::contextMenuEvent(QContextMenuEvent *event)
// {
//     if (QMenu *menu = createStandardContextMenu()) {
//         menu->setAttribute(Qt::WA_DeleteOnClose);
//         // menu->popup(event->globalPos());
//         menu->exec(event->globalPos());
//     }
// }

// void QTextEdit::contextMenuEvent(QContextMenuEvent *e)
// {
//     if (QMenu *menu = createStandardContextMenu()) {
//         menu->setAttribute(Qt::WA_DeleteOnClose);
//         // menu->popup(event->globalPos());
//         menu->exec(e->globalPos());
//     }
// }

// void QComboBox::contextMenuEvent(QContextMenuEvent *e)
// {
//     Q_D(QComboBox);
//     if (lineEdit()) {
//         if (QMenu *menu = lineEdit()->createStandardContextMenu()) {
//             menu->setAttribute(Qt::WA_DeleteOnClose);
//             // menu->popup(event->globalPos());
//             menu->exec(e->globalPos());
//         }
//     }
// }
