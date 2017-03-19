#include "GearArm.h"

#include "../Commands/ControlGearArm.h"
#include "../RobotMap.h"

GearArm::GearArm() : Subsystem("GearArm") {

	gearArmMotor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;
	solenoid = RobotMap::gearShootSolenoid;

	m_idealPosition = Position::NOT_INITIALIZED;

}

void GearArm::InitDefaultCommand() {

	SetDefaultCommand(new ControlGearArm());
}

void GearArm::ControlGearArmMotor(double speed)
{
	if (speed > 0 && GetHomeSwitch())
		StopGearArmMotor();
	else if (speed > 0)
		gearArmMotor->Set(speed);
	else
		gearArmMotor->Set(speed * 0.5);
}

void GearArm::StopGearArmMotor()
{
	gearArmMotor->StopMotor();
}

void GearArm::SetIdealPosition(Position position)
{
	m_idealPosition = position;
}



void GearArm::OpenShoot()
{
	if (SolenoidP() && !ShootOpened())
	{
		solenoid->Set(frc::DoubleSolenoid::Value::kForward);
		frc::Wait(1);
	}
}

void GearArm::CloseShoot()
{
	if (SolenoidP() && ShootOpened())
	{
		solenoid->Set(frc::DoubleSolenoid::Value::kReverse);
		frc::Wait(2.5);
	}
}




bool GearArm::ShootOpened()
{
	return SolenoidP() && solenoid->Get() == frc::DoubleSolenoid::Value::kForward;
}

bool GearArm::GetHomeSwitch()
{
	return homeSwitch->Get();
}

Position GearArm::GetIdealPosition()
{
	return m_idealPosition;
}

inline bool GearArm::SolenoidP()
{
	return solenoid != nullptr;
}
