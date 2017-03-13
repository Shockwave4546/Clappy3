#ifndef DRIVETELEOP_H
#define DRIVETELEOP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Garrick Craft
 */
class DriveTeleop: public Command {
public:

	DriveTeleop(ControlConfig driveConfig);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

	double m_X{ 0 };
	double m_Y{ 0 };
	double m_Z{ 0 };
	double m_scalar{ 1 };
	double m_sens{ 1 };

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<XboxController> driveStickX;

};

#endif
