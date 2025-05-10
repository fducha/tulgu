#ifndef ICONIZEDLINEEDIT_H
#define ICONIZEDLINEEDIT_H

#include <QLineEdit>
#include <QEvent>

class QLabel;

class IconizedLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    enum IconVisibleMode {
        IconAlwaysVisible = 0,
        IconVisibleOnHover,
        IconVisibleOnTextPresence,
        IconVisibleOnEmptyText,
        IconAlwaysHidden,
    };

    explicit IconizedLineEdit(QWidget *parent = nullptr);

    void setIconVisiblity(IconVisibleMode mode);

    bool isIconVisible() const;
    void setIconPixmap(const QPixmap &pixmap);
    void setIconToolTip(const QString &toolTip);
    void setIconClickable(bool clickable);

signals:
    void iconPressed();

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void textChanged(const QString &text);

private:
    void updateIconPositionAndSize();
    void setIconVisible(bool isVisible);

    QLabel *m_iconLabel;
    IconVisibleMode m_mode;
    bool m_isIconClickable;
};

#endif // ICONIZEDLINEEDIT_H
