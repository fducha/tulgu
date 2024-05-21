#include "ledindicator.h"
#include <QPainter>
#include <QPainterPath>
#include <QPaintEvent>

const int LED_RADIUS = 15;
const int LED_SPACING = 5;

LedIndicator::LedIndicator(QWidget *parent)
    : QWidget{parent}, m_isTurnedOn{false}
{

}

QString LedIndicator::text() const {
    return m_text;
}

bool LedIndicator::isTurnedOn() const {
    return m_isTurnedOn;
}

QSize LedIndicator::minimumSizeHint() const {
    return QSize(LED_RADIUS * 2 + fontMetrics().horizontalAdvance(m_text) + LED_SPACING,
                 LED_SPACING * 2);
}

void LedIndicator::setText(const QString &text) {
    m_text = text;
}

void LedIndicator::setTurnedOn(bool turned) {
    if (isTurnedOn() == turned) return;

    m_isTurnedOn = turned;
    emit stateToggled(m_isTurnedOn);
    update();
}

void LedIndicator::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPoint ledCenter(LED_RADIUS + 1, height() / 2);

    QPainterPath path;
    path.addEllipse(ledCenter, LED_RADIUS, LED_RADIUS);
    painter.save();

    QRadialGradient gradient(ledCenter, LED_RADIUS);

    if (m_isTurnedOn) {
        painter.setPen(QPen(Qt::darkGreen));
        gradient.setColorAt(0.2, "#70FF70");
        gradient.setColorAt(1, "#00CC00");
    } else {
        painter.setPen(QPen(Qt::black));
        gradient.setColorAt(0.2, Qt::gray);
        gradient.setColorAt(1, Qt::darkGray);
    }

    painter.fillPath(path, QBrush(gradient));
    painter.drawPath(path);

    painter.restore();
    painter.setFont(font());

    QRect textRect(LED_RADIUS * 2 + LED_SPACING, 0,
                   width() - (LED_RADIUS * 2 + LED_SPACING), height());
    painter.drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, m_text);
}
