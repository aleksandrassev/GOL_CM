#include "cycle_test.h"

#include "rules.h"
#include "encoder.h"

TEST_F(Cycle_test, next_generation)
{
    std::vector<std::vector<bool>> vector(3, std::vector<bool>(3));
    Field* field = new Field(vector);

    Encoder* encoder = new Encoder();
    Rules* rules = new Rules();
    Cycle cycle(encoder, rules);


    QString encodedField = cycle.nextGeneration(field);

    ASSERT_EQ("000\n000\n000\n", encodedField);

    delete field;
    delete rules;
    delete encoder;
}
