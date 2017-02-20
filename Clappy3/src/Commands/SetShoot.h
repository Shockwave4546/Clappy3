#ifndef SetShoot_H
#define SetShoot_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SetShoot : public Command {
public:
	SetShoot(Direction direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Direction m_direction;
	bool m_done;
};

#endif  // SetShoot_H
