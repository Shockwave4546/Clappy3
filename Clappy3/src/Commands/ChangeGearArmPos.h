#ifndef ChangeGearArmPos_H
#define ChangeGearArmPos_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ChangeGearArmPos : public Command {
public:
	ChangeGearArmPos(Position position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Position m_position;
	bool m_done{ false };
};

#endif  // ChangeGearArmPos_H
