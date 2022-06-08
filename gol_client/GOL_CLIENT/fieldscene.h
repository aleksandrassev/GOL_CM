#ifndef FIELDSCENE_H
#define FIELDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <iostream>
#include <QImage>
#include <vector>
#include <algorithm>

class FieldScene : public QGraphicsScene
{
public:
    explicit FieldScene(QObject *parent = nullptr);
    ~FieldScene() override;

    std::vector<std::vector<bool>> m_field;

    std::vector<std::vector<bool>> get_field() const;

    void createEmptyFieldImage();
    void createFieldImage();
    void createFieldImage(QString fieldString);
    void stringToField(QString& stringField);
    void clear();
    bool checkEmpty();
    void makeEmpty();

private:
        QPointF m_coordinates;
        int m_row = 50;
        int m_col = 80;
        int m_canvasSizeX = 800;
        int m_canvasSizeY = 500;
        int m_cellSize = 10;
        QRgb m_liveValue = qRgb(240,248,25);
        QRgb m_deadValue = qRgb(210, 210, 210);

        void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

};

#endif // FIELDSCENE_H
