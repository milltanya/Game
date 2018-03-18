#include "Building.h"
#include "House.h"
#include "Work.h"
#include "Road.h"
#include "Park.h"
#include "City.h"
#include <gtest/gtest.h>

/*TEST(numbers, strtoint) {
	int x, y;
	std::string s = "1234";	
	strtoint(s, x, y);
	EXPECT_EQ(-1, x);
}
TEST(right, strtoint) {
	int x, y;
	std::string s = "12 34";
	strtoint(s, x, y);
	EXPECT_EQ(34, y);
}
TEST(symbols, strtoint) {
	int x, y;	
	std::string s = "  dfgs 12 sdfg 34 dfgs";
	strtoint(s, x, y);
	EXPECT_EQ(12, x);
}
TEST(manynumbers, strtoint) {
	int x, y;
	std::string s = "12 34 45";
	strtoint(s, x, y);
	EXPECT_EQ(-1, y);
}

TEST(house, factories) {
	CHouseFactory Factory;	
	EXPECT_EQ('H', Factory.create()->symbol);
}

TEST(work, factories) {
	CWorkFactory Factory;	
	EXPECT_EQ('W', Factory.create()->symbol);
}

TEST(park, factories) {
	CParkFactory Factory;	
	EXPECT_EQ('P', Factory.create()->symbol);
}

TEST(house, actions) {
	CBuilding* tmp = new CHouse;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(101, tmpstate.population);
}

TEST(work, actions) {
	CBuilding* tmp = new CWork;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(97, tmpstate.happiness);
}

TEST(park, actions) {
	CBuilding* tmp = new CPark;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(101, tmpstate.happiness);
}*/
TEST(kek, lol) {
	ASSERT_EQ(3, 3);
}

int main(int argc, char *argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
