#include "ccustomxml.h"

CCustomXML::CCustomXML(QWidget *parent): QWidget{parent}{
}

void CCustomXML::procSaveXML(const QString& fileName){
    CXMLHelper xmlHelper;

    // Write XML data to the file
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("library");

    // Write book elements
    xmlWriter.writeStartElement("book");
    xmlWriter.writeTextElement("title", "Sample Book 1");
    xmlWriter.writeTextElement("author", "Author 1");
    xmlWriter.writeTextElement("year", "2020");
    xmlWriter.writeEndElement(); // book

    xmlWriter.writeStartElement("book");
    xmlWriter.writeTextElement("title", "Sample Book 2");
    xmlWriter.writeTextElement("author", "Author 2");
    xmlWriter.writeTextElement("year", "2022");
    xmlWriter.writeEndElement(); // book

    xmlWriter.writeEndElement(); // library
    xmlWriter.writeEndDocument();
    file.close();
}

void CCustomXML::procLoadXML(const QString& fileName){
    QFile file(fileName);
    // Read and display XML data
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return ;
    }

    QXmlStreamReader xmlReader(&file);

    while (!xmlReader.atEnd() && !xmlReader.hasError()){
        xmlReader.readNext();
        if (xmlReader.isStartElement() && xmlReader.name() == "book") {
            QString title, author, year;
            while (!xmlReader.atEnd() && !(xmlReader.isEndElement() && xmlReader.name() == "book")){
                xmlReader.readNext();
                if (xmlReader.isStartElement()){
                    QString elementName = xmlReader.name().toString();
                    xmlReader.readNext();
                    if (xmlReader.isCharacters()){
                        QString elementValue = xmlReader.text().toString();
                        if (elementName == "title"){
                            title = elementValue;
                        } else if (elementName == "author"){
                            author = elementValue;
                        } else if (elementName == "year"){
                            year = elementValue;
                        }
                    }
                }
            }
            if (!title.isEmpty() && !author.isEmpty() && !year.isEmpty()){
                qDebug() << "Book:" << title << "Author:" << author << "Year:" << year;
            }
        }
    }
    file.close();

    if (xmlReader.hasError()){
        qDebug() << "XML error:" << xmlReader.errorString();
    }
}
