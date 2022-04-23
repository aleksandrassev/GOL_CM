#ifndef IRULE_H
#define IRULE_H

class IRules
{
public:
    virtual bool executeFirstRule(bool status, int live_neighb) = 0;
    virtual bool executeSecondRule(bool status, int live_neighb) = 0;
    virtual bool executeThirdRule(bool status, int live_neighb) = 0;
    virtual bool executeFourthRule(bool status, int live_neighb) = 0;

protected:
    virtual ~IRules() = default;
};

#endif // IRULE_H
