#ifndef MoveToTarget_H
#define MoveToTarget_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

enum Target
{
	HOOK,
	GEAR
};

class MoveToTarget : public Command {
public:
	MoveToTarget(Target target);
	MoveToTarget(Target target, double minumumDistance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_minDistance{ 0 };
	Target m_target;
	double m_distance{ 0 };
	double m_offset{ 0 };
};

#endif  // MoveToTarget_H
