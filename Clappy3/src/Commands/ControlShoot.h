#ifndef ControlShoot_H
#define ControlShoot_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author Garrick Craft
 */
class ControlShoot : public Command {
public:
	ControlShoot(ShootPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ShootPosition m_position;
	bool m_done;
};

#endif  // ControlShoot_H
