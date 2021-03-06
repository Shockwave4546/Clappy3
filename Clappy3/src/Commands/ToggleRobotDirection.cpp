#include "ToggleRobotDirection.h"

ToggleRobotDirection::ToggleRobotDirection(): Command() {

	Requires(Robot::driveTrain.get());

}

void ToggleRobotDirection::Initialize() {

}

void ToggleRobotDirection::Execute() {
	Robot::driveTrain->ChangeDirection();
	m_done = true;
}

bool ToggleRobotDirection::IsFinished() {

    return m_done;
}

void ToggleRobotDirection::End() {

}

void ToggleRobotDirection::Interrupted() {

}
