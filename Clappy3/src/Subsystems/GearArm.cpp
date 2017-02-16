#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	gearArmMotor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;

	encoder->SetDistancePerPulse(360.0/497);

	m_targetPosition = 0;

}

void GearArm::InitDefaultCommand() {

	SetDefaultCommand(new ControlGearArm());

}

void GearArm::Zero()
{
	encoder->Reset();
}

void GearArm::ControlGearArmMotor(double speed)
{
	gearArmMotor->Set(speed);
}

void GearArm::StopGearArmMotor()
{
	gearArmMotor->StopMotor();
}

void GearArm::MoveTo(double position)
{
	while (encoder->GetDistance() < position - 10)
	{
		ControlGearArmMotor(-0.17);
	}
	while (encoder->GetDistance() > position + 10)
	{
		ControlGearArmMotor(0.45);
	}
	StopGearArmMotor();
}

bool GearArm::GetHomeSwitch()
{
	return homeSwitch->Get();
}

double GearArm::GetTargetPosition()
{
	return m_targetPosition;
}

double GearArm::GetDegreesD()
{
	return encoder->GetDistance();
}
