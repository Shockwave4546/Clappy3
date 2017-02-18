#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"
#include <cmath>

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

void GearArm::MoveToTargetPosition()
{
	while (GetDegreesD() < m_targetPosition)
	{
		ControlGearArmMotor(-CalculateSpeed(GetDegreesD() - m_targetPosition));
	}
	while (GetDegreesD() > m_targetPosition)
	{
		ControlGearArmMotor(CalculateSpeed(GetDegreesD() - m_targetPosition));
	}
}

void GearArm::SetTargetPosition(double position)
{
	m_targetPosition = position;
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

inline double GearArm::CalculateSpeed(double difference)
{
	return std::abs(0.8 /(1 + std::exp(0.2 * difference)) - 0.4);
}
