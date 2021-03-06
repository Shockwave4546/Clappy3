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
	ToggleGearPCM(PCMStatus status);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done{ false };
	PCMStatus m_status;
};

#endif  // ToggleGearPCM_H
