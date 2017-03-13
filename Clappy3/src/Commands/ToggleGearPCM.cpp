#include "ToggleGearPCM.h"

#include "../Subsystems/GearPCM.h"

ToggleGearPCM::ToggleGearPCM(PCMStatus status)
{
	Requires(Robot::gearPCM.get());
	m_status = status;
}

void ToggleGearPCM::Initialize() {

}

void ToggleGearPCM::Execute() {

	if (m_status == PCMStatus::TOGGLE)
	{
		if (Robot::gearPCM->GetPCMStatus() == DoubleSolenoid::Value::kReverse)
			Robot::gearPCM->SetGearPCM(PCMStatus::CLOSED);
		else
			Robot::gearPCM->SetGearPCM(PCMStatus::OPENED);
	}
	else
		Robot::gearPCM->SetGearPCM(m_status);



	m_done = true;

}

bool ToggleGearPCM::IsFinished() {
	return m_done;
}

void ToggleGearPCM::End() {

}

void ToggleGearPCM::Interrupted() {

}
