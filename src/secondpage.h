#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>

namespace Ui {
class secondpage;
}

class secondpage : public QDialog
{
    Q_OBJECT

public:
    explicit secondpage(QWidget *parent = nullptr);
    ~secondpage();

private:
    Ui::secondpage *ui;
};

#endif // SECONDPAGE_H
