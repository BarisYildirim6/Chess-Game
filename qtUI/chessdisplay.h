#ifndef CHESSDISPLAY_H
#define CHESSDISPLAY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChessDisplay; }
QT_END_NAMESPACE

class ChessDisplay : public QMainWindow
{
    Q_OBJECT

public:
    ChessDisplay(QWidget *parent = nullptr);
    ~ChessDisplay();

private:
    Ui::ChessDisplay *ui;
};
#endif // CHESSDISPLAY_H
