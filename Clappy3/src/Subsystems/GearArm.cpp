#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"
#include <cmath>

GearArm::GearArm() : Subsystem("GearArm") {

	gearArmMotor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;

	encoder->SetDistancePerPulse(360.0/497);

	m_targetPosition = Position::HOOK;
	m_targetPositionD = 0;
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
	switch(m_targetPosition)
	{
	case Position::HOOK:
		m_targetPositionD = 0;
		break;
	case Position::RAMP:
		m_targetPositionD = 45;
		break;
	case Position::GROUND:
		m_targetPositionD = 90;
		break;
	}

	while (GetDegreesD() < m_targetPositionD)
	{
		ControlGearArmMotor(-CalculateSpeed(GetDegreesD() - m_targetPositionD));
	}
	while (GetDegreesD() > m_targetPositionD)
	{
		ControlGearArmMotor(CalculateSpeed(GetDegreesD() - m_targetPositionD));
	}
}

void GearArm::SetTargetPosition(Position position)
{
	if (position == Position::UP)
		CycleUp();
	else
		CycleDown();
}

void GearArm::CycleUp()
{
	if (m_targetPosition + 1 < Position::MAX)
		m_targetPosition += 1;
}

void GearArm::CycleDown()
{
	if (m_targetPosition - 1 > Position::MIN)
		m_targetPosition -= 1;
}

bool GearArm::GetHomeSwitch()
{
	return homeSwitch->Get();
}

std::string GearArm::GetTargetPositionS()
{
	switch (m_targetPosition)
	{
	case Position::GROUND:
		return "Ground";
	case Position::RAMP:
		return "Ramp";
	case Position::HOOK:
		return "Hook";
	default:
		return "Out Of Range";
	}
}

double GearArm::GetDegreesD()
{
	return encoder->GetDistance();
}

inline double GearArm::CalculateSpeed(double difference)
{
	return std::abs(0.8 /(1 + std::exp(0.2 * difference)) - 0.4);
}
