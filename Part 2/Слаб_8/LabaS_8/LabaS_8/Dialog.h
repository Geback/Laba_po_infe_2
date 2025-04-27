
#pragma once
#include "Event.h"
#include "Vector.h"

class Dialog :
	public Vector
{
public:
	Dialog(void);
	~Dialog(void);
	void GetEvent(TEvent& event);
	void Execute();
	void HandleEvent(TEvent& event);
	void ClearEvent(TEvent& event);
	bool Valid();
	void EndExec();
protected:
	int EndState;
};