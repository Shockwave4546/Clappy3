#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	gearArmMotor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;

	shootMotor = RobotMap::shootMotor;
	lowerLimit = RobotMap::shootLowerLimit;
	upperLimit = RobotMap::shootUpperLimit;

	if (EncoderP())
		encoder->SetDistancePerPulse(360.0 / 497.0);
	if (ShootMotorP())
		shootMotor->Set(0.0);

	ControlGearArmMotor(0.0);


}

void GearArm::InitDefaultCommand() {

}

void GearArm::Zero()
{
	if (EncoderP())
		encoder->Reset();
}

void GearArm::ControlGearArmMotor(double speed)
{
	if (GearArmMotorP())
	{
		gearArmMotor->Set(speed);
	}
}

void GearArm::ControlShootMotor(ShootPosition position)
{
	if (ShootMotorP())
	{
		if (position == ShootPosition::DOWN)
		{
			while (!GetLowerLimit())
				shootMotor->Set(1.0);
		}
		else
		{
			while (!GetUpperLimit())
				shootMotor->Set(-1.0);
		}
	}
}

bool GearArm::GetHomeSwitch()
{
	return (HomeSwitchP()) ? homeSwitch->Get() : false;
}

bool GearArm::GetLowerLimit()
{
	return (LowerLimitP()) ? lowerLimit->Get() : false;
}

bool GearArm::GetUpperLimit()
{
	return (UpperLimitP()) ? upperLimit->Get() : false;
}

double GearArm::GetDegreesD()
{
	if (EncoderP())
		return encoder->GetDistance();
	else
		return static_cast<double>(RobotError::POINTER_IS_NULL);
}

bool GearArm::Position(double position)
{
	if (EncoderP())
		return encoder->GetDistance() > position - 2.0 && encoder->GetDistance() < position + 2.0;
	else
		return false;
}

void GearArm::MoveTo(double position)
{
	if (EncoderP())
	{
		while (encoder->GetDistance() < position - 2.0)
			ControlGearArmMotor(-0.5);
		while (encoder->GetDistance() > position + 2.0)
			ControlGearArmMotor(0.5);
		ControlGearArmMotor(0.0);
	}
}

inline bool GearArm::EncoderP()
{
	return encoder != nullptr;
}

inline bool GearArm::GearArmMotorP()
{
	return gearArmMotor != nullptr;
}

inline bool GearArm::ShootMotorP()
{
	return shootMotor != nullptr;
}

inline bool GearArm::LowerLimitP()
{
	return lowerLimit != nullptr;
}

inline bool GearArm::UpperLimitP()
{
	return upperLimit != nullptr;
}

inline bool GearArm::HomeSwitchP()
{
	return homeSwitch != nullptr;
}
