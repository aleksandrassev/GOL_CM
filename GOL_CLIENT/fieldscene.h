#ifndef FIELDSCENE_H
#define FIELDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QImage>
#include <vector>
#include <algorithm>
#include "encoder.h"

class FieldScene : public QGraphicsScene
{
public:
    explicit FieldScene(QObject *parent = nullptr);
    ~FieldScene() override;

    std::vector<std::vector<bool>> get_field() const;

    void createEmptyFieldImage();
    void createFieldImage();
    void decodeImage(QString &fieldString);
    void encodeImage(QString &fieldString);
    void clearImage();
    bool checkIfEmpty();
    void makeEmpty();

private:
    std::vector<std::vector<bool>> m_field;
    QPointF m_coordinates;
    int m_row;
    int m_col;
    int m_canvasSizeX;
    int m_canvasSizeY;
    int m_cellSize;
    QRgb m_liveValue;
    QRgb m_deadValue;

    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
};

#endif // FIELDSCENE_H
