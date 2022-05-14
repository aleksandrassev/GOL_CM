#include "cycle.h"
#include <QDebug>
#include "rules.h"

Cycle::Cycle(IEncoder* encoder, IRules* rules, IField* field, IField* nextField)
    :m_encoder(encoder)
    ,m_rules(rules)
    ,m_field(field)
    ,m_nextField(nextField)
{
    if (field == nullptr || rules == nullptr || encoder == nullptr || nextField == nullptr)
    {
      qCritical("missing pointer in Cycle class");
    }
}

Cycle::~Cycle()
{
}

QString Cycle::nextGeneration()
{

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

void Cycle::applyRule(int cellPosX, int cellPosY, IField* field, IField* nextField)
{
    const auto alive_neib = m_field->findNeighbours(cellPosX, cellPosY);

    if (m_rules->executeFirstRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, false);
        qDebug()<<"FirstRuleApplied!";
    }
    else if (m_rules->executeSecondRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, false);
        qDebug()<<"2RuleApplied!";
    }
    else if (m_rules->executeThirdRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, true);
        qDebug()<<"3RuleApplied!";
    }
    else if (m_rules->executeFourthRule(m_field->getCellStatus(cellPosX, cellPosY), alive_neib))
    {
        m_nextField->setCellStatus(cellPosX, cellPosY, true);
        qDebug()<<"4RuleApplied!";
    }
}

