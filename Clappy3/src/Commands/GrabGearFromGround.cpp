#include "GrabGearFromGround.h"
#include "../Robot.h"
#include "ToggleGearPCM.h"
#include "SetShoot.h"
#include "ChangeGearArmPos.h"
#include <thread>
#include <chrono>

#include "SetShoot.h"
GrabGearFromGround::GrabGearFromGround() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new SetShoot(Direction::REVERSE));
	AddSequential(new ChangeGearArmPos(Position::GROUND));
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	AddSequential(new ToggleGearPCM(PCMStatus::CLOSED));
	AddSequential(new ChangeGearArmPos(Position::HOOK));
}
