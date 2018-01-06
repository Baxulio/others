#ifndef STYLES_H
#define STYLES_H

#include <QWidget>
#include <QtWidgets>
class styles : public QWidget
{
    Q_OBJECT

public:
    styles(QWidget *parent = 0);
    ~styles();
public slots:
    void slotChangeStyle(const QString &str);
};

#endif // STYLES_H
