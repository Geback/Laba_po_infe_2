#include "maintree.h"
#include "ui_maintree.h"

MainTree::MainTree(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainTree)
{
    ui->setupUi(this);
}

MainTree::~MainTree()
{
    delete ui;
}
