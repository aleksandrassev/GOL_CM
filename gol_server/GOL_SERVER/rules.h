#ifndef RULES_H
#define RULES_H

#include "irules.h"

class Rules : public IRules
{
public:
    Rules() = default;
    ~Rules() override = default;

    bool executeFirstRule(bool status, int live_neighb) override;
    bool executeSecondRule(bool status, int live_neighb) override;
    bool executeThirdRule(bool status, int live_neighb) override;
    bool executeFourthRule(bool status, int live_neighb) override;
};

#endif // RULES_H
