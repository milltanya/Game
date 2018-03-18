#include "../main.cpp"
#include <gtest/gtest.h>

TEST(strtoint, stringtointeger) {
	int* a = new int[10];
	inttostr("1234", a[0], a[1]);
	inttostr("12 34", a[2], a[3]);
	inttostr("  dfgs 12 sdfg 34 dfgs", a[4], a[5]);
	inttostr("12 34 45", a[6], a[7]);
	inttostr("sfg12gfds34", a[8], a[9]);
	EXPECT_EQ({-1, -1, 12, 34, 12, 34, -1, -1, 12, 34}, a);
	delete a;
}

TEST(city, constructor) {
	CCity city(20, 30);
	EXPECT_EQ({20, 30}, {city.height, city.width});
}

TEST(house, factories) {
	EXPECT_EQ('H', CHouseFactory.create()->symbol);
}

TEST(work, factories) {
	EXPECT_EQ('W', CWorkFactory.create()->symbol);
}

TEST(park, factories) {
	EXPECT_EQ('P', CParkFactory.create()->symbol);
}

TEST(house, actions) {
	State tmp;
	CBuilding* tmp = new CHouse;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp[0]->action(tmpstate);
	bool flag = (tmpstate.population != 101) || (tmpstate.happiness != 100) || (tmpstate.wealth != 97) || (tmpstate.money != 100);
	EXPECT_EQ(true, flag);
}

TEST(work, actions) {
	State tmp;
	CBuilding* tmp = new CWork;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp[0]->action(tmpstate);
	bool flag = (tmpstate.population != 100) || (tmpstate.happiness != 97) || (tmpstate.wealth != 101) || (tmpstate.money != 101);
	EXPECT_EQ(true, flag);
}

TEST(park, actions) {
	State tmp;
	CBuilding* tmp = new CPark;
	State tmpstate;
	tmpstate.time = clock() + 10*CLOCKS_PER_SEC;
	tmpstate.money = 100;
	tmpstate.happiness = 100;
	tmpstate.wealth = 100;
	tmpstate.population = 100;
	tmp[0]->action(tmpstate);
	bool flag = (tmpstate.population != 100) || (tmpstate.happiness != 101) || (tmpstate.wealth != 100) || (tmpstate.money != 100);
	EXPECT_EQ(true, flag);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
