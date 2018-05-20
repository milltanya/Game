#include "CityState.h"

SCityState::SCityState(const SCityState& s) {
	Field.resize(s.Field.size());
	for (int i = 0; i < Field.size(); ++i) {
		Field[i].resize(s.Field[i].size());
		for (int j = 0; j < Field[i].size(); ++j) {
			if (Field[i][j] != nullptr && s.Field[i][j] == nullptr) {
				delete Field[i][j];
			}
			Field[i][j] = s.Field[i][j];
		}
	}
	State = SState(s.State);
}

SCityState::SCityState() {
}

SCityState::SCityState(int width, int height) {
	Field.resize(height);
	for (int i = 0; i < height; ++i) {
		Field[i].resize(width);
		for (int j = 0; j < width; ++j)
			Field[i][j] = nullptr;
	}
	State = SState(10, 1, 5, 5);
}

SCityState::~SCityState() {
}