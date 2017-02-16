#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	gearArmMotor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;
	gearPID = RobotMap::gearArmPIDController;

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

void GearArm::SetGearPIDSetpoint(double position)
{
	gearPID->SetSetpoint(position);
}

void GearArm::SetTargetPosition(double position)
{
	m_targetPosition = position;
}

void GearArm::EnableGearPID()
{
	gearPID->Enable();
}

void GearArm::DisableGearPID()
{
	gearPID->Disable();
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
