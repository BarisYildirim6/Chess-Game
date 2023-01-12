#include "chessdisplay.h"
#include "ui_chessdisplay.h"

ChessDisplay::ChessDisplay(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChessDisplay)
{
    ui->setupUi(this);
}

ChessDisplay::~ChessDisplay()
{
    delete ui;
}

