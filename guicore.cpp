#include "guicore.h"
#include "ui_guicore.h"

guicore::guicore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guicore)
{
    ui->setupUi(this);
}

guicore::~guicore()
{
    delete ui;
}

