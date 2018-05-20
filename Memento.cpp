#include "Memento.h"

#include "CityState.h"
#include "Graphics.h"

CMemento::CMemento() {
	///����������� �� ���������
	state = SCityState();
}

CMemento::CMemento(SCityState s) {
	///����������� �� ��������� ������ s
	state = SCityState(s);
}

SCityState CMemento::getState() {
	///���������� ����������
    return state;
}

CCaretaker::CCaretaker() {
	///����������� �� ���������
	memento = CMemento();
}

CMemento CCaretaker::getMemento() {
	///���������� ����������� ���������
    return memento;
}

void CCaretaker::setMemento(CMemento m) {
	///��������� ���������
    memento = CMemento(m);
}
