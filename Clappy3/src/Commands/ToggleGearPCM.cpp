#include "ToggleGearPCM.h"

#include "../Subsystems/GearPCM.h"

ToggleGearPCM::ToggleGearPCM() {
	Requires(Robot::gearPCM.get());
	m_done = false;
}

void ToggleGearPCM::Initialize() {

}

void ToggleGearPCM::Execute() {

	if (Robot::gearPCM->GetPCMStatus() == static_cast<bool>(PCMStatus::OPENED))
		Robot::gearPCM->SetGearPCM(PCMStatus::CLOSED);
	else
		Robot::gearPCM->SetGearPCM(PCMStatus::OPENED);

	m_done = true;

}

bool ToggleGearPCM::IsFinished() {
	return m_done;
}

void ToggleGearPCM::End() {

}

void ToggleGearPCM::Interrupted() {

}
