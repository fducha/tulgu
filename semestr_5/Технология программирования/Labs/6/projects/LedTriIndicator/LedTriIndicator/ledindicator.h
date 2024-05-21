#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

#include <QWidget>

class LedIndicator : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool turnedOn READ isTurnedOn WRITE setTurnedOn NOTIFY stateToggled)
    Q_PROPERTY(IndicatorState state READ state WRITE setState NOTIFY stateChanged)

public:
    enum IndicatorState {
        OFF = 0,
        MIDDLE,
        ON
    };

    explicit LedIndicator(QWidget *parent = nullptr);

    QString text() const;
    bool isTurnedOn() const;

    virtual QSize minimumSizeHint() const override;

    IndicatorState state() const;

signals:
    void stateToggled(bool);

    void stateChanged(IndicatorState state);

public slots:
    void setText(const QString &text);
    void setTurnedOn(bool turned);
    void setTristate(bool isTristate);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private slots:
    void setState(IndicatorState state);

private:
    QString m_text;
    bool m_isTristate{false};

    IndicatorState m_state{IndicatorState::OFF};
};

#endif // LEDINDICATOR_H
