#include "CityState.h"

SCityState::SCityState() {
	width = 0;
	height = 0;
	Field = nullptr;
}

SCityState::SCityState(int w, int h) {
	width = w;
	height = h;
	Field = new CBuilding**[height];
	for (int i = 0; i < height; ++i) {
		Field[i] = new CBuilding*[width];
		for (int j = 0; j < width; ++j)
			Field[i][j] = nullptr;
	}
	State = SState(10, 1, 5, 5);
}

SCityState::~SCityState() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (Field[i][j] != nullptr) {
				delete Field[i][j];
			}
		}
		delete Field[i];
	}
	delete Field;	
}