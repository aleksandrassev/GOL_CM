#ifndef IRULE_H
#define IRULE_H

class IRule
{
public:
  virtual bool execute(bool status, int live_neighb) = 0;
};

#endif // IRULE_H
