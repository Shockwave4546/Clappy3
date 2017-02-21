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
	std::shared_ptr<DoubleSolenoid> solenoid;
	int m_targetPosition;
	double m_targetPositionD;

	inline bool SolenoidP();

public:

	GearArm();

	void InitDefaultCommand();

	void Zero();
	void Home();

	void ControlGearArmMotor(double speed);
	void StopGearArmMotor();
	void MoveToTargetPosition();
	void SetTargetPosition(Position position);

	void Forward();
	void Reverse();
	DoubleSolenoid::Value GetSolenoidValue();

	void CycleUp();
	void CycleDown();

	bool GetHomeSwitch();
	std::string GetTargetPositionS();
	double GetDegreesD();
	double GetTargetPositionD();

};

#endif
