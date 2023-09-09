#include "cxmlhelper.h"


CXMLHelper::CXMLHelper()
{
    // Create an XML document with the XML declaration
    QDomNode xmlNode = m_xmlDocument.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    m_xmlDocument.insertBefore(xmlNode, m_xmlDocument.firstChild());
}

bool CXMLHelper::loadXML(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    if (!m_xmlDocument.setContent(&file))
    {
        file.close();
        return false;
    }

    file.close();
    return true;
}

bool CXMLHelper::saveXML(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << m_xmlDocument.toString();
    file.close();
    return true;
}

QDomElement CXMLHelper::rootElement() const
{
    return m_xmlDocument.documentElement();
}

QDomElement CXMLHelper::createElement(const QString& tagName)
{
    return m_xmlDocument.createElement(tagName);
}

void CXMLHelper::appendElement(QDomElement& parent, QDomElement& child)
{
    parent.appendChild(child);
}

QString CXMLHelper::readElementText(const QDomElement& element, const QString& tagName)
{
    QDomNodeList nodes = element.elementsByTagName(tagName);
    if (!nodes.isEmpty())
    {
        QDomElement tagElement = nodes.at(0).toElement();
        return tagElement.text();
    }
    return QString();
}

void CXMLHelper::writeElementText(QDomElement& element, const QString& tagName, const QString& text)
{
    QDomElement tagElement = m_xmlDocument.createElement(tagName);
    QDomText textNode = m_xmlDocument.createTextNode(text);
    tagElement.appendChild(textNode);
    element.appendChild(tagElement);
}
