#ifndef ToggleSlow_H
#define ToggleSlow_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ToggleSlow : public Command {
public:
	ToggleSlow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done{ false };
};

#endif  // ToggleSlow_H
