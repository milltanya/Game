#include "Memento.h"

#include "CityState.h"
#include "Graphics.h"

CMemento::CMemento() {
	///Конструктор по умолчанию
	state = SCityState();
}

CMemento::CMemento(SCityState s) {
	///Конструктор по состоянию города s
	state = SCityState(s);
}

SCityState CMemento::getState() {
	///Возвращает стостояние
    return state;
}

CCaretaker::CCaretaker() {
	///Конструктор по умолчанию
	memento = CMemento();
}

CMemento CCaretaker::getMemento() {
	///Возвращает сохраненное состояние
    return memento;
}

void CCaretaker::setMemento(CMemento m) {
	///Сохраняет состояние
    memento = CMemento(m);
}
