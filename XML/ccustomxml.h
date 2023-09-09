#ifndef CCUSTOMXML_H
#define CCUSTOMXML_H

#include <QWidget>
#include "cxmlhelper.h"

class CCustomXML : public QWidget
{
    Q_OBJECT
public:
    explicit CCustomXML(QWidget *parent = nullptr);
    void procSaveXML(const QString& fileName);
    void procLoadXML(const QString& fileName);

signals:

};

#endif // CCUSTOMXML_H
