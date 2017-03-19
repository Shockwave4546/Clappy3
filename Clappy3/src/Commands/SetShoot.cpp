#include "../Commands/SetShoot.h"

#include <thread>
#include <chrono>

SetShoot::SetShoot(Direction direction) {
	Requires(Robot::gearArm.get());
	m_direction = direction;
}

void SetShoot::Initialize() {

	if (m_direction == Direction::FORWARD)
	{
		Robot::gearArm->OpenShoot();
	}
	else
		Robot::gearArm->CloseShoot();
}

void SetShoot::Execute() {

	m_done = true;

}

bool SetShoot::IsFinished() {
	return m_done;
}

void SetShoot::End() {

}

void SetShoot::Interrupted() {

}
