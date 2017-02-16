#ifndef ToggleGearPCM_H
#define ToggleGearPCM_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Garrick Craft
 */
class ToggleGearPCM : public Command {
public:
	ToggleGearPCM();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done;
};

#endif  // ToggleGearPCM_H
