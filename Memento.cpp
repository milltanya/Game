#include "Memento.h"

#include "CityState.h"

CMemento::CMemento() {
	state = SCityState();
}

CMemento::CMemento(SCityState s) {
    state = s;
}

SCityState CMemento::getState() {
    return state;
}

CCaretaker::CCaretaker(CMemento m) {
	memento = m;
}

CMemento CCaretaker::getMemento() {
    return memento;
}

void CCaretaker::setMemento(CMemento memento) {
    memento = memento;
}
