#include "Building.h"
#include "House.h"
#include "Work.h"
#include "Road.h"
#include "Park.h"
#include "City.h"
#include <gtest/gtest.h>

TEST(strtoint, numbers) {
	int x, y;
	std::string s = "1234";	
	strtoint(s, x, y);
	EXPECT_EQ(-1, x);
}
TEST(strtoint, right) {
	int x, y;
	std::string s = "12 34";
	strtoint(s, x, y);
	EXPECT_EQ(34, y);
}
TEST(strtoint, symbols) {
	int x, y;	
	std::string s = "  dfgs 12 sdfg 34 dfgs";
	strtoint(s, x, y);
	EXPECT_EQ(12, x);
}
TEST(strtoint, manynumbers) {
	int x, y;
	std::string s = "12 34 45";
	strtoint(s, x, y);
	EXPECT_EQ(-1, y);
}

TEST(factories, house) {
	CHouseFactory Factory;	
	CBuilding* tmp = Factory.create();
	EXPECT_EQ("House", tmp->getType());
	delete tmp;
}

TEST(factories, work) {
	CWorkFactory Factory;		
	CBuilding* tmp = Factory.create();
	EXPECT_EQ("Work", tmp->getType());
	delete tmp;
}

TEST(factories, park) {
	CParkFactory Factory;		
	CBuilding* tmp = Factory.create();
	EXPECT_EQ("Park", tmp->getType());
	delete tmp;
}

TEST(actions, house) {
	CBuilding* tmp = new CHouse;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(101, tmpstate.population);
	delete tmp;
}

TEST(actions, work) {
	CBuilding* tmp = new CWork;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(97, tmpstate.happiness);
	delete tmp;
}

TEST(actions, park) {
	CBuilding* tmp = new CPark;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp->action(tmpstate);
	EXPECT_EQ(101, tmpstate.happiness);
	delete tmp;
}

int main(int argc, char *argv[]) {
  	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
