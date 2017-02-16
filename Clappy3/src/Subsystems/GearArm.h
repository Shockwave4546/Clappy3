#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>



enum class Position
{
	GROUND,
	RAMP,
	HOOK,
	JOYSTICK
};

enum class ShootPosition
{
	DOWN,
	UP
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

	std::shared_ptr<SpeedController> shootMotor;
	std::shared_ptr<DigitalInput> upperLimit;
	std::shared_ptr<DigitalInput> lowerLimit;

	inline bool EncoderP();
	inline bool GearArmMotorP();
	inline bool HomeSwitchP();

	inline bool ShootMotorP();
	inline bool LowerLimitP();
	inline bool UpperLimitP();

	inline bool Ground();
	inline bool Ramp();
	inline bool Hook();
	inline bool BetweenGroundAndRamp();
	inline bool BetweenRampAndHook();

public:

	GearArm();

	void InitDefaultCommand();

	void Zero();

	void Home();

	void MoveTo(double position);

	void ControlGearArmMotor(double speed);

	void ControlShootMotor(ShootPosition position);

	bool GetHomeSwitch();

	bool GetLowerLimit();

	bool GetUpperLimit();

	double GetDegreesD();

	bool Position(double position);

};

#endif
