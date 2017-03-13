#ifndef ControlGearArm_H
#define ControlGearArm_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Garrick Craft
 */
class ControlGearArm : public Command {
public:
	ControlGearArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//bool m_done;
	//double m_targetPosition;
	std::shared_ptr<XboxController> gearStick;
};

#endif
