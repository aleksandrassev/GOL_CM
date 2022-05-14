#ifndef CYCLE_H
#define CYCLE_H

#include "icycle.h"
#include "ifield.h"
#include "iencoder.h"
#include "irules.h"


class Cycle : public ICycle
{
public:
  Cycle(IEncoder* encoder, IRules* rules, IField* field, IField* nextField);
  ~Cycle() override;

  QString nextGeneration() override;
  void applyRule(int cellPosX, int cellPosY, IField* field, IField* nextField);

private:
  IEncoder* m_encoder;
  IRules* m_rules;
  IField* m_field;
  IField* m_nextField;


};

#endif // CYCLE_H
