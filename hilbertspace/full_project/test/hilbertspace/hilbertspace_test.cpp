#include "hilbertspace/QuantumChannel.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockQuantumChannel : public QuantumChannel {
public:
    MOCK_METHOD(void, setMass, (double mass), (override));
    MOCK_METHOD(double, getMass, (), (const, override));
};

//using ::testing::AtLeast;
using ::testing::Return;
using ::testing::AtLeast;

TEST(QuantumChannelTest, SetMass) {
    MockQuantumChannel hspace;
    EXPECT_CALL(hspace, setMass(45)).Times(AtLeast(1));
    EXPECT_CALL(hspace, getMass()).Times(3).WillRepeatedly(Return(45));
    //EXPECT_EQ(45==testMass.getMass(), testMass.setMass(45));
}

/*
TEST(NewtonianSpaceTest, MultiplyMultipliesTwoInts) {
  EXPECT_EQ(12, Calc::Multiply(3, 4));
}
*/
