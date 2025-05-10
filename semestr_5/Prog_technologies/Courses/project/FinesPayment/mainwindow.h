#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class OwnersModel;
class OwnerFilterProxyModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    // === СОБСТВЕННИКИ === СОБСТВЕННИКИ === СОБСТВЕННИКИ ===
    void ownerChanged(int ownerId);

    // === ТС === ТС === ТС === ТС === ТС === ТС === ТС =====

private slots:
    // === СОБСТВЕННИКИ === СОБСТВЕННИКИ === СОБСТВЕННИКИ ===
    void handleClickAddOwnerBtn();
    void handleClickUpdateOwnerBtn();
    void handleClickRemoveOwnerBtn();
    void handleSelectionOwner(const QModelIndex &current,
                              const QModelIndex &previous);

    // === ТС === ТС === ТС === ТС === ТС === ТС === ТС =====
    void handleClickAddVehicleBtn();
    void handleClickUpdateVehicleBtn();
    void handleClickRemoveVehicleBtn();
    void handleSelectionVehicle(const QModelIndex &current,
                                const QModelIndex &previous);
    void handleOwnerChanging(int ownerId);

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::MainWindow *ui;

    // === СОБСТВЕННИКИ === СОБСТВЕННИКИ === СОБСТВЕННИКИ ===
    OwnersModel *m_mdlOwners;
    OwnerFilterProxyModel *m_mdlProxyOwners;

    // === ТС === ТС === ТС === ТС === ТС === ТС === ТС =====

    void enableOwnerCRUDBtns(bool enable);
    void enableVehicleCRUDBtns(bool enable);
};
#endif // MAINWINDOW_H
