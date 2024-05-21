#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

#include <QWidget>

class LedIndicator : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool turnedOn READ isTurnedOn WRITE setTurnedOn NOTIFY stateToggled)

public:
    explicit LedIndicator(QWidget *parent = nullptr);

    QString text() const;
    bool isTurnedOn() const;

    virtual QSize minimumSizeHint() const override;

signals:
    void stateToggled(bool);

public slots:
    void setText(const QString &text);
    void setTurnedOn(bool turned);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QString m_text;
    bool m_isTurnedOn;
};

#endif // LEDINDICATOR_H
