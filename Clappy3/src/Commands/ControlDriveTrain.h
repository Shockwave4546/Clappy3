#ifndef ControlDriveTrain_H
#define ControlDriveTrain_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ControlDriveTrain : public Command {
public:
	ControlDriveTrain(double x, double y, double z, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_X;
	double m_Y;
	double m_Z;
	double m_timeout;
};

#endif  // ControlDriveTrain_H
