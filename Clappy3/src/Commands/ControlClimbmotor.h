#ifndef ControlClimbmotor_H
#define ControlClimbmotor_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ControlClimbmotor : public Command {
public:
	ControlClimbmotor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<XboxController> gearStickX;
	std::shared_ptr<Joystick> gearStick;
};

#endif  // ControlClimbmotor_H
