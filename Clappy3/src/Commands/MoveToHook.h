#ifndef MoveToHook_H
#define MoveToHook_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveToHook : public Command {
public:
	MoveToHook();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveToHook_H
