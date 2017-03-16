#ifndef MoveToShoot_H
#define MoveToShoot_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveToShoot : public Command {
public:
	MoveToShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveToShoot_H
