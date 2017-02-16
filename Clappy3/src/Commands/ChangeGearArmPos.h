#ifndef ChangeGearArmPos_H
#define ChangeGearArmPos_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ChangeGearArmPos : public Command {
public:
	ChangeGearArmPos(double position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_position;
	bool m_done;
};

#endif  // ChangeGearArmPos_H
