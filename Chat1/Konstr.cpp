//===================================== Τΰιλ Konstr.cpp ==============================
#include "member.h"
#include "membList.h"

member::member(string nk, string lgn, string pswd)
{
	nik = nk;
	login = lgn;
	password = pswd;
}


/*void member::getMemberNik()
{
	return nik;
}

const char Snack::getSnackName() const
{
	cout << *SnackName << endl;
	return *SnackName;
}

SnackSlot::SnackSlot(short n)
{
	SlotSize = n;
}

SnackSlot::SnackSlot(short m, short n)
{
	SlotSize = m;
	Items = n;
}

short SnackSlot::getSnackSlotSize() const
{
	return SlotSize;
}

short SnackSlot::getSnackSlotItems() const
{
	return Items;
}


VendingMachine::VendingMachine(short slotCount)
{
	slots = slotCount;
}

void Snack::setSnackPrice(float pr)
{
	SnackPrice = pr;
}

void Snack::setSnackName(const char* sn)
{
	SnackName = sn;
}
*/