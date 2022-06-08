#include "fieldscene.h"

#include <iostream>

FieldScene::FieldScene(QObject *parent)
    : QGraphicsScene{parent}
{
    m_field = std::vector<std::vector<bool>>(m_row, std::vector<bool>(m_col, false));
}

FieldScene::~FieldScene()
{
}

std::vector<std::vector<bool>> FieldScene::get_field() const
{
    return m_field;
}

void FieldScene::createEmptyFieldImage()
{
    QImage image(m_canvasSizeX, m_canvasSizeY, QImage::Format_RGB32);

    for (int x = 0; x < m_canvasSizeX; x++)
    {
        for(int y = 0; y < m_canvasSizeY; y++)
        {
            image.setPixel(x, y, m_deadValue);
        }
        for (int i = 0; i < m_field.size(); i++)
        {
            for (int j = 0; j < m_field[i].size(); j++)
            {
                image.setPixel(j * m_cellSize + 0, i * m_cellSize + 0, qRgb(0,0,0));
            }
        }
    }
    addPixmap(QPixmap::fromImage(image));
}

void FieldScene::createFieldImage()
{
    QImage image(m_canvasSizeX, m_canvasSizeY, QImage::Format_RGB32);
    QRgb value;

    for (int i = 0; i < m_field.size(); i++)
    {
        for (int j = 0; j < m_field[i].size(); j++)
        {
            if (m_field[i][j] == true)
            {
                 value = m_liveValue;
            }
            else
            {
                 value = m_deadValue;
            }
            for (int x = 0; x < m_cellSize; x++)
            {
                for(int y = 0; y < m_cellSize; y++)
                {
                    image.setPixel(j * m_cellSize + x, i * m_cellSize + y, value);
                }
            }
            image.setPixel(j * m_cellSize + 0, i * m_cellSize + 0, qRgb(0,0,0));
        }
    }
    addPixmap(QPixmap::fromImage(image));
}

void FieldScene::createFieldImage(QString fieldString)
{
    stringToField(fieldString);
    createFieldImage();
}

void FieldScene::stringToField(QString& stringField)
{
    m_field.clear();
    std::vector<bool> line;

    for (auto i : stringField)
    {
        if (i != '\n')
        {
            line.push_back(i.digitValue());
        }
        else
        {
            m_field.push_back(line);
            line.clear();
        }
    }
}

void FieldScene::clear()
{
    QList <QGraphicsItem*> itemList = items();
    while(!itemList.isEmpty())
    {
        delete itemList.first();
        itemList = items();
    }
}

bool FieldScene::checkEmpty()
{
    for (const auto& v : m_field)
    {
        for (auto x : v)
        {
            if(x != false)
            {
                return false;
            }
        }
    }
    return true;
}

void FieldScene::makeEmpty()
{
   m_field = std::vector<std::vector<bool>>(m_row, std::vector<bool>(m_col, false));
}

void FieldScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    int j = x / 10;
    int i = y / 10;

    if (m_field[i][j] == true)
    {
        m_field[i][j] = false;
    }
    else
    {
        m_field[i][j] = true;
    }
    clear();
    createFieldImage();
}
