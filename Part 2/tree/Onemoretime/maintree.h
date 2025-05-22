#ifndef MAINTREE_H
#define MAINTREE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainTree;
}
QT_END_NAMESPACE

class MainTree : public QMainWindow
{
    Q_OBJECT

public:
    MainTree(QWidget *parent = nullptr);
    ~MainTree();

private:
    Ui::MainTree *ui;
};
#endif // MAINTREE_H
