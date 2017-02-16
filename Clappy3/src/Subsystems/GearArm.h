#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>

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
	double m_targetPosition;

public:

	GearArm();

	void InitDefaultCommand();

	void Zero();
	void Home();

	void ControlGearArmMotor(double speed);
	void StopGearArmMotor();
	void MoveTo(double position);

	bool GetHomeSwitch();
	double GetTargetPosition();
	double GetDegreesD();

};

#endif
