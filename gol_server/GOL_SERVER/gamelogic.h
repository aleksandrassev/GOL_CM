#ifndef CYCLE_H
#define CYCLE_H

#include "igamelogic.h"
#include "ifield.h"
#include "iencoder.h"
#include "irules.h"


class GameLogic : public IGameLogic
{
public:
  GameLogic(IEncoder* encoder, IRules* rules, IField* field, IField* nextField);
  ~GameLogic() override;

  QString nextGeneration() override;
  void applyRule(int cellPosX, int cellPosY, IField* field, IField* nextField);
  int findNeighbours(int positionX, int positionY, IField* field) const override;

private:
  IEncoder* m_encoder;
  IRules* m_rules;
  IField* m_field;
  IField* m_nextField;


};

#endif // CYCLE_H
