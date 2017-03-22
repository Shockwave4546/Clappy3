#ifndef ControlGearArm_H
#define ControlGearArm_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <ctime>

/**
 *
 *
 * @author Garrick Craft
 */
class ControlGearArm : public Command {
public:
	ControlGearArm();
	ControlGearArm(double speed, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<XboxController> gearStick;
	double m_speed{ 0 };
	double m_timeout{ -1 };
	std::time_t m_timer;
	int current_time{ -1 };
};

#endif
