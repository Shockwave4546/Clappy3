#include "ChangeGearArmPos.h"

ChangeGearArmPos::ChangeGearArmPos(double position) {
	Requires(Robot::gearArm.get());

	m_position = position;
	m_done = false;
}

void ChangeGearArmPos::Initialize() {

}

void ChangeGearArmPos::Execute() {

	Robot::gearArm->SetTargetPosition(m_position);
	m_done = true;

}

bool ChangeGearArmPos::IsFinished() {
	return m_done;
}

void ChangeGearArmPos::End() {

}

void ChangeGearArmPos::Interrupted() {

}
