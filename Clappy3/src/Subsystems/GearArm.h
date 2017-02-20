#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>

enum Position
{
	MIN,
	GROUND,
	RAMP,
	HOOK,
	MAX,
	UP,
	DOWN
};

/**
 *
 *
 * @author Garrick Craft
 */
class GearArm : public Subsystem {
private:

	std::shared_ptr<SpeedController> gearArmMotor;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<DigitalInput> homeSwitch;
	int m_targetPosition;
	double m_targetPositionD;

public:

	GearArm();

	void InitDefaultCommand();

	void Zero();
	void Home();

	void ControlGearArmMotor(double speed);
	void StopGearArmMotor();
	void MoveToTargetPosition();
	void SetTargetPosition(Position position);

	void CycleUp();
	void CycleDown();

	bool GetHomeSwitch();
	std::string GetTargetPositionS();
	double GetDegreesD();
	double GetTargetPositionD();

};

#endif
