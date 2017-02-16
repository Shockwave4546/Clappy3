#ifndef HomeGearArm_H
#define HomeGearArm_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Garrick Craft
 */
class HomeGearArm : public Command {
public:
	HomeGearArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done;
};

#endif
