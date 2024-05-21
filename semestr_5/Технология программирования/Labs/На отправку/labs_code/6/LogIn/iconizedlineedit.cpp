#include "iconizedlineedit.h"
#include <QStyle>
#include <QLabel>

IconizedLineEdit::IconizedLineEdit(QWidget *parent)
    : QLineEdit{parent}, m_mode{IconAlwaysVisible}
{
    m_iconLabel = new QLabel(this);
    m_iconLabel->installEventFilter(this);
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)), Qt::UniqueConnection);
}

void IconizedLineEdit::setIconVisiblity(IconVisibleMode mode) {
    m_mode = mode;

    switch (mode) {
    case IconAlwaysVisible:
        setIconVisible(true);
        break;
    case IconVisibleOnEmptyText:
    case IconVisibleOnTextPresence:
        textChanged(text());
        break;
    default:
        setIconVisible(false);
        break;
    }
}

bool IconizedLineEdit::isIconVisible() const {
    return m_iconLabel->isVisible();
}

void IconizedLineEdit::setIconPixmap(const QPixmap &pixmap) {
    m_iconLabel->setPixmap(pixmap.scaled(24, 24, Qt::KeepAspectRatio));
    m_iconLabel->setFixedSize(24, 24);
    updateIconPositionAndSize();
}

void IconizedLineEdit::setIconToolTip(const QString &toolTip) {
    m_iconLabel->setToolTip(toolTip);
}

void IconizedLineEdit::setIconClickable(bool clickable) {
    m_isIconClickable = clickable;
    if (m_isIconClickable) m_iconLabel->setCursor(Qt::PointingHandCursor);
    else m_iconLabel->setCursor(Qt::ArrowCursor);
}

void IconizedLineEdit::resizeEvent(QResizeEvent *event) {
    updateIconPositionAndSize();
    QWidget::resizeEvent(event);
}

bool IconizedLineEdit::eventFilter(QObject *obj, QEvent *event) {
    if (m_isIconClickable) {
        if ((obj == m_iconLabel) && (event->type() == QEvent::MouseButtonPress)) {
            emit iconPressed();
            return true;
        }
    }
    return false;
}

void IconizedLineEdit::textChanged(const QString &text) {
    if (m_mode == IconVisibleOnEmptyText) {
        setIconVisible(text.isEmpty());
    } else if (m_mode == IconVisibleOnTextPresence) {
        setIconVisible(!text.isEmpty());
    }
}

void IconizedLineEdit::updateIconPositionAndSize() {
    if (m_iconLabel->isVisible()) {
        setTextMargins(QMargins(1, 1, 25, 1));
    } else {
        setTextMargins(QMargins(1, 1, 1, 1));
    }
    m_iconLabel->setScaledContents(true);
    auto size = m_iconLabel->size();
    m_iconLabel->move(rect().right() - size.width() - 2, rect().top() + 2);

}

void IconizedLineEdit::setIconVisible(bool isVisible) {
    m_iconLabel->setVisible(isVisible);
}
