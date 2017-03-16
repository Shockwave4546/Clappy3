#include "MoveToTarget.h"
#include "../Calculations.h"

MoveToTarget::MoveToTarget(Target target)
{
	Requires(Robot::driveTrain.get());
	m_target = target;
}

MoveToTarget::MoveToTarget(Target target, double minDistance) {
	Requires(Robot::driveTrain.get());
	m_minDistance = minDistance;
	m_target = target;
}

void MoveToTarget::Initialize() {
	if (m_target == Target::GEAR)
		SmartDashboard::PutString("Tracker", "gear");
	else
		SmartDashboard::PutString("Tracker", "hook");
	SmartDashboard::PutBoolean("Tracking", true);
}

void MoveToTarget::Execute() {
	m_distance = SmartDashboard::GetNumber("hdist", 0);
	if (m_distance > 0)
	{
		m_offset = SmartDashboard::GetNumber("offset", 0);
		Robot::driveTrain->ControlDriveTrain(0, calc::AutoYValue(m_offset, calc::DistanceWeight(m_distance, m_minDistance), 1),
												calc::AutoZValue(m_offset, calc::DistanceWeight(m_distance, m_minDistance), 1), 1);
	}
}

bool MoveToTarget::IsFinished() {
	return m_distance - m_minDistance <= 0.5 && std::abs(m_offset) <= 0.2;
}

void MoveToTarget::End() {
	Robot::driveTrain->StopMoving();
	SmartDashboard::PutBoolean("Tracking", false);
}

void MoveToTarget::Interrupted() {
	Robot::driveTrain->StopMoving();
	SmartDashboard::PutBoolean("Tracking", false);
}
