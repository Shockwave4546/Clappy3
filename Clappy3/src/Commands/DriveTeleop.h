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

	DriveTeleop();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

	double m_X;
	double m_Y;
	double m_Z;
	double m_scalar;
	double m_sens;
	int m_controlConfig;

	inline double Left();
	inline double Right();
	inline double CalculateSpeed(double scalar, double input);

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<XboxController> driveStickX;

};

#endif
