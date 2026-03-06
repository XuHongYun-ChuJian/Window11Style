#pragma once

#include <QPalette>
#include <QObject>

enum class Theme
{
    Light,
    Dark
};

class ThemeManager: public QObject
{
    Q_OBJECT
public:
    static ThemeManager& instance();

    void setTheme(Theme theme);
    Theme theme() const;

    void applyPalette(QPalette& palette) const;

signals:
    void sigThemeChanged(Theme theme);

private:
    explicit ThemeManager(): QObject(nullptr) {}

    void applyLight(QPalette& palette) const;
    void applyDark(QPalette& palette) const;

private:
    Theme m_theme = Theme::Light;
};
