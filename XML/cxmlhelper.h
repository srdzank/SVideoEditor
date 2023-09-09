#ifndef CXMLHELPER_H
#define CXMLHELPER_H
#include <QtXml>


//<library>
//    <book>
//    <title>Sample Book 1</title>
//    <author>Author 1</author>
//    <year>2020</year>
//    </book>
//    <book>
//    <title>Sample Book 2</title>
//    <author>Author 2</author>
//    <year>2022</year>
//    </book>
// </library>

class CXMLHelper
{
public:
    CXMLHelper();

    // Method to load an XML file
    bool loadXML(const QString& filePath);

    // Method to save the XML document to a file
    bool saveXML(const QString& filePath);

    // Method to get the root element of the XML document
    QDomElement rootElement() const;

    // Methods to create and append elements to the XML document
    QDomElement createElement(const QString& tagName);
    void appendElement(QDomElement& parent, QDomElement& child);

    // Methods to read and write data from/to XML elements
    QString readElementText(const QDomElement& element, const QString& tagName);
    void writeElementText(QDomElement& element, const QString& tagName, const QString& text);

private:
    QDomDocument m_xmlDocument;
};


#endif // CXMLHELPER_H
