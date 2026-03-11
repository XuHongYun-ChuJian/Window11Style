#pragma once

#include <QPalette>
#include <QObject>

#if QT_VERSION < QT_VERSION_CHECK(6,6,0)
#define QPalette_Accent QPalette::NColorRoles + 1
#endif

class PaletteManager: public QObject
{
    Q_OBJECT
public:
    static PaletteManager& instance();
    void applyPalette(QPalette& palette, bool isDark = true) const;

private:
    explicit PaletteManager(): QObject(nullptr) {}

    void applyLight(QPalette& palette) const;
    void applyDark(QPalette& palette) const;
};
