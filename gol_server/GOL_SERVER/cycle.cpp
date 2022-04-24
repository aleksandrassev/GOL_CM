#include "cycle.h"
#include <QDebug>
#include "rules.h"

Cycle::Cycle(IEncoder* encoder, IRules* rules)
    :m_encoder(encoder), m_rules(rules)
{
}

Cycle::~Cycle()
{
}

QString Cycle::nextGeneration(Field* field)
{
    Field* currentField = field;

    for (int i = 0; i < currentField->getRowSize(); i++)
    {
        for (int j = 0; j < currentField->getColSize(); j++)
        {
            const auto alive_neib = currentField->findNeighbours(i, j);

            if (m_rules->executeFirstRule(field->getCellStatus(i, j), alive_neib))
            {
                field->setCellStatus(i, j, false);
            }
            else if (m_rules->executeSecondRule(field->getCellStatus(i, j), alive_neib))
            {
                field->setCellStatus(i, j, false);
            }
            else if (m_rules->executeThirdRule(field->getCellStatus(i, j), alive_neib))
            {
                field->setCellStatus(i, j, false);
            }
            else
            {
                m_rules->executeFourthRule(field->getCellStatus(i, j), alive_neib);
            }
        }
    }
    const auto encodedField = m_encoder->encode(field);

    return encodedField;
}
