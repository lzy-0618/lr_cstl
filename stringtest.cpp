#include "mystring.hpp"
#include <gtest/gtest.h>

using namespace my;

class stringtest : public testing::Test {

public:
	stringtest() :t1("abc"), t2("123"), t3("abc123") {}
	
	virtual void SetUp() override {

	}

	virtual void TearDown() override {

	}

	my::string t1;
	my::string t2;
	my::string t3;
};


// ���Թ��캯�� �� ������С��غ���: size(),capacity(),c_str()
TEST_F(stringtest, attribute) {

	EXPECT_EQ(t1.size(), 3);
	EXPECT_EQ(t1.capacity(), 3);
	// strlen ���㳤�Ȳ����� '\0' 
	EXPECT_EQ(strlen(t1.c_str()), 3);
}

// �������캯��, ��ֵ�����
TEST_F(stringtest, constructor) {
	my::string t4(t3);
	EXPECT_EQ(t4.size(), t3.size());
	EXPECT_EQ(t4.capacity(), t3.capacity());
	EXPECT_TRUE(strcmp(t4.c_str(),t3.c_str())==0);

	my::string t5 = t3;
	EXPECT_EQ(t5.size(), t3.size());
	EXPECT_EQ(t5.capacity(), t3.capacity());
	EXPECT_TRUE(strcmp(t5.c_str(), t3.c_str()) == 0);
}

// �����������Է�����д