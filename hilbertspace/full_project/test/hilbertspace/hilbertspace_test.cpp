#include "hilbertspace/QuantumChannel.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockQuantumChannel : public QuantumChannel {
public:
    MOCK_METHOD(void, setmessageDescriptor, (int bhi, string msg), (override));
    MOCK_METHOD(int, getBlockIndex, (), (const, override));
    MOCK_METHOD(string, getMessageHeader, (), (const, override));
};

//using ::testing::AtLeast;
using ::testing::Return;
using ::testing::AtLeast;

TEST(QuantumChannelTest, MessageDescriptor) {
    MockQuantumChannel hspace;
    EXPECT_CALL(hspace, setmessageDescriptor(1,"TestBlock")).Times(AtLeast(3));
    EXPECT_CALL(hspace, getBlockIndex()).Times(3).WillRepeatedly(Return(1));
    EXPECT_CALL(hspace, getMessageHeader()).Times(3).WillRepeatedly(Return("TestBlock"));
    //EXPECT_EQ(45==testMass.getMass(), testMass.setMass(45));
}

/*
TEST(NewtonianSpaceTest, MultiplyMultipliesTwoInts) {
  EXPECT_EQ(12, Calc::Multiply(3, 4));
}
*/
