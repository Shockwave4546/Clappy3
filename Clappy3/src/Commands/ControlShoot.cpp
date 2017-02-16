#include "ControlShoot.h"

ControlShoot::ControlShoot(ShootPosition position) {

	Requires(Robot::gearArm.get());

	m_position = position;
	m_done = false;

}

void ControlShoot::Initialize() {

}

void ControlShoot::Execute() {

	if (m_position == ShootPosition::DOWN)
		Robot::gearArm->ControlShootMotor(m_position);
	else
		Robot::gearArm->ControlShootMotor(ShootPosition::UP);

	m_done = true;

}

bool ControlShoot::IsFinished() {
	return m_done;
}

void ControlShoot::End() {

}

void ControlShoot::Interrupted() {

}
