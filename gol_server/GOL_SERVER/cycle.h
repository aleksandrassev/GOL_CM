#ifndef CYCLE_H
#define CYCLE_H


#include "icycle.h"
#include "field.h"
#include "encoder.h"
//#include "rule_1.h"
//#include "rule_2.h"
//#include "rule_3.h"
//#include "rule_4.h"

class Cycle : public ICycle
{
public:
  Cycle();
  ~Cycle() override;

  QString nextGeneration() override;

private:
  Field* m_field;
  Field* m_currentField;

};

#endif // CYCLE_H
