#ifndef FIELD_TEST_H
#define FIELD_TEST_H

#include "gtest/gtest.h"
#include "field.h"
#include <QDebug>

class Field_test : public ::testing::Test
{
protected:
    Field_test() = default;
    virtual ~Field_test() = default;
};

#endif // FIELD_TEST_H
