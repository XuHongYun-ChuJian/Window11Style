#include "dockwidgettitlebar.h"
#include "ui_dockwidgettitlebar.h"
DockWidgetTitleBar::DockWidgetTitleBar(QDockWidget *dock)
    : QWidget(dock), m_dock(dock) {
    setFixedHeight(32);
    setAttribute(Qt::WA_StyledBackground, true);

    // 图标
    m_icon = new QLabel(this);
    m_icon->setFixedSize(16, 16);
    m_icon->setPixmap(dock->windowIcon().pixmap(16, 16));

    // 标题
    m_title = new QLabel(dock->windowTitle(), this);
    m_title->setStyleSheet("color:#202020; font-size:13px;");

    // 按钮
    m_btnFloat = createButton(QChar(0xE70F)); // Fluent: Pop-out
    m_btnClose = createButton(QChar(0xE8BB)); // Fluent: Close

    auto layout = new QHBoxLayout(this);
    layout->setContentsMargins(8, 0, 6, 0);
    layout->setSpacing(6);

    layout->addWidget(m_icon);
    layout->addSpacing(4);
    layout->addWidget(m_title);
    layout->addStretch();
    layout->addWidget(m_btnFloat);
    layout->addWidget(m_btnClose);

    connect(m_btnClose, &QToolButton::clicked, dock, &QDockWidget::close);
    connect(m_btnFloat, &QToolButton::clicked, this,
            [this] { m_dock->setFloating(!m_dock->isFloating()); });

    connect(dock, &QDockWidget::windowTitleChanged, m_title, &QLabel::setText);
    connect(
        dock, &QDockWidget::windowIconChanged, this,
        [this](const QIcon &icon) { m_icon->setPixmap(icon.pixmap(16, 16)); });
}

void DockWidgetTitleBar::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), QColor("#F9F9F9"));  // Fluent 背景

    p.setPen(QColor("#E5E5E5"));            // Fluent 分隔线
    p.drawLine(rect().bottomLeft(), rect().bottomRight());
}

QToolButton *DockWidgetTitleBar::createButton(const QChar &icon)
{
    auto btn = new QToolButton(this);
    btn->setText(icon);
    btn->setFont(QFont("Segoe Fluent Icons", 12));
    btn->setFixedSize(28, 28);
    btn->setStyleSheet(R"(
            QToolButton {
                background: transparent;
                border-radius: 4px;
                color: #202020;
            }
            QToolButton:hover {
                background: #E5E5E5;
            }
            QToolButton:pressed {
                background: #DADADA;
            }
        )");
    return btn;
}
