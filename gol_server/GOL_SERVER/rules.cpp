#include "rules.h"


bool Rules::executeFirstRule(bool status, int live_neighb)
{
    if (live_neighb < 2 && status)
    {
        return true;
    }
    return false;
}

bool Rules::executeSecondRule(bool status, int live_neighb)
{
    if (live_neighb > 3 && status)
    {
        return true;
    }
    return false;
}

bool Rules::executeThirdRule(bool status, int live_neighb)
{
    if (live_neighb == 3 && !status)
    {
        return true;
    }
    return false;
}

bool Rules::executeFourthRule(bool status, int live_neighb)
{
    if ((live_neighb == 3 || live_neighb == 2) && status)
    {
        return true;
    }
    return false;
}
