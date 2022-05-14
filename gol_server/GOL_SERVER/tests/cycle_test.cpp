#include "cycle_test.h"

#include "rules.h"
#include "encoder.h"

TEST_F(Cycle_test, apply_rule)
{
    std::vector<std::vector<bool>> vector(8, std::vector<bool>(8));
    Field field(vector);
    Field nextField(vector);
    Encoder encoder;
    Rules rules;
    Cycle cycle(&encoder, &rules, &field, &nextField);

    field.setCellStatus(1,2, true);
    field.setCellStatus(2,3, true);
    field.setCellStatus(3,1, true);
    field.setCellStatus(3,2, true);
    field.setCellStatus(3,3, true);

    ASSERT_FALSE(nextField.getCellStatus(3, 2));

    cycle.applyRule(3, 2, &field, &nextField);

    ASSERT_TRUE(nextField.getCellStatus(3, 2));
}


TEST_F(Cycle_test, next_generation)
{
    std::vector<std::vector<bool>> vector(8, std::vector<bool>(8));
    Field field(vector);
    Field nextField(vector);
    Encoder encoder;
    Rules rules;
    Cycle cycle(&encoder, &rules, &field, &nextField);

    field.setCellStatus(1,2, true);
    field.setCellStatus(2,3, true);
    field.setCellStatus(3,1, true);
    field.setCellStatus(3,2, true);
    field.setCellStatus(3,3, true);

    QString nextFieldString = cycle.nextGeneration();
    QString notExpectedString = "00000000\n"
                             "00100000\n"
                             "00010000\n"
                             "01110000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n";
    QString expectedString = "00000000\n"
                             "00000000\n"
                             "01010000\n"
                             "00110000\n"
                             "00100000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n";

    ASSERT_NE(nextFieldString, notExpectedString);
    ASSERT_EQ(nextFieldString, expectedString);
}
