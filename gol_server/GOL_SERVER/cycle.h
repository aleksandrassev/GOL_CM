#ifndef CYCLE_H
#define CYCLE_H

#include "icycle.h"
#include "ifield.h"
#include "iencoder.h"
#include "irules.h"


class Cycle : public ICycle
{
public:
  Cycle(IEncoder* encoder, IRules* rules);
  ~Cycle() override;

  QString nextGeneration(Field* field) override;

private:
  IEncoder* m_encoder;
  IRules* m_rules;


};

#endif // CYCLE_H
