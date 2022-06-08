#include "gamelogic.h"
#include <QDebug>
#include "rules.h"

GameLogic::GameLogic(IEncoder* encoder, IRules* rules, IField* field, IField* nextField)
    :m_encoder(encoder)
    ,m_rules(rules)
    ,m_field(field)
    ,m_nextField(nextField)
{
    if (field == nullptr || rules == nullptr || encoder == nullptr || nextField == nullptr)
    {
      qCritical("missing pointer in GameLogic constructor");
    }
}

GameLogic::~GameLogic()
{
}

QString GameLogic::nextGeneration()
{
    if (m_field == nullptr || m_nextField == nullptr || m_encoder == nullptr)
    {
      qCritical("missing pointer in GameLogic::nextGeneration()");
      return "";
    }

    for (int i = 0; i < m_field->getRowSize(); i++)
    {
        for (int j = 0; j < m_field->getColSize(); j++)
        {
          applyRule(i, j, m_field, m_nextField);
        }
    }
    const QString encodedField = m_encoder->encode(m_nextField);

    return encodedField;
}

void GameLogic::applyRule(int cellPosX, int cellPosY, IField* field, IField* nextField)
{
    if (field == nullptr || nextField == nullptr || m_rules == nullptr)
    {
      qCritical("missing pointer in GameLogic::applyRule");
      return;
    }

    const auto alive_neib = findNeighbours(cellPosX, cellPosY, m_field);

    if (m_rules->executeFirstRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, false);
    }
    else if (m_rules->executeSecondRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, false);
    }
    else if (m_rules->executeThirdRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, true);
    }
    else if (m_rules->executeFourthRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, true);
    }
}

int GameLogic::findNeighbours(int row, int col, IField* field) const
{
    if (field == nullptr)
    {
      qCritical("missing pointer in GameLogic::findNeighbours");
      return -1;
    }
    int alive_neib = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int row_mod = (row + i + field->getRowSize()) % field->getRowSize();
            int col_mod = (col + j + field->getColSize()) % field->getColSize();

            if (field->getCellStatus(row_mod, col_mod))
            {
                alive_neib++;
            }
        }
    }
    return (alive_neib - field->getCellStatus(row, col));
}
