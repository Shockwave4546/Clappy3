#ifndef OverrideSwitch_H
#define OverrideSwitch_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class OverrideSwitch : public Command {
public:
	OverrideSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done{ false };
};

#endif  // OverrideSwitch_H
