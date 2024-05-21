#ifndef PERSONLISTWIDGET_H
#define PERSONLISTWIDGET_H

#include <QWidget>

namespace Ui {
class PersonListWidget;
}

class PersonsModel;
class PersonFilterProxyModel;

class PersonListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PersonListWidget(QWidget *parent = nullptr);
    ~PersonListWidget();

private slots:
    /// Обработка нажатия кнопки Добавить.
    /// Запускает диалоговое окно редактирования данных нового собственника
    void addBtnClicked();
    /// Обработка нажатия кнопки Изменить.
    /// Запускает диалоговое окно редактирования данных выбранного собственника
    void updateBtnClicked();
    void removeBtnClicked();
    void personSelected(const QModelIndex &current,
                        const QModelIndex &previous);

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::PersonListWidget *ui;

    PersonsModel *m_model;
    PersonFilterProxyModel *m_filterModel;

    void enableCRUDButtons(bool enable);
};

#endif // PERSONLISTWIDGET_H
