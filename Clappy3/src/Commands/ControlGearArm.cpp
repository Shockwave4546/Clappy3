#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());
	m_done = false;
	m_targetPosition = 0;
}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {

		m_targetPosition = Robot::gearArm->GetTargetPositionD();

		if (Robot::gearArm->GetDegreesD() < m_targetPosition)
		{
			Robot::gearArm->ControlGearArmMotor(-Robot::gearArm->CalculateSpeed(Robot::gearArm->GetDegreesD() - m_targetPosition));
		}
		if (Robot::gearArm->GetDegreesD() > m_targetPosition)
		{
			Robot::gearArm->ControlGearArmMotor(Robot::gearArm->CalculateSpeed(Robot::gearArm->GetDegreesD() - m_targetPosition));
		}
}

bool ControlGearArm::IsFinished() {
	return false;
}

void ControlGearArm::End() {

}

void ControlGearArm::Interrupted() {
	Robot::gearArm->StopGearArmMotor();
}
