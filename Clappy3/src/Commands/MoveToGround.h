#ifndef MoveToGround_H
#define MoveToGround_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveToGround : public Command {
public:
	MoveToGround();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveToGround_H
