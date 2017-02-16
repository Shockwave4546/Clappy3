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
	ControlGearArm(Position position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done;
	Position m_position;
};

#endif
