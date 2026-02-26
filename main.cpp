#include <QApplication>
#include <QFont>
#include "MainWindow.h"
#include "CusProxyStyle.h"
#include "qboxlayout.h"
#include "qcombobox.h"

int main(int argc, char *argv[])
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#else
    //根据实际屏幕缩放比例更改
    qputenv("QT_SCALE_FACTOR", "1.5");
#endif
#endif

    QApplication a(argc, argv);

    QPalette appPalette = a.palette();

    QColor fluentAccentColor(0,103,192);
    // appPalette.setColor(QPalette::Accent, fluentAccentColor);

    a.setPalette(appPalette);

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
