#include "AutoGrabGearFromGround.h"
#include "ToggleGearPCM.h"
#include "MoveToGround.h"
#include "ControlDriveTrain.h"
#include "MoveToHook.h"


AutoGrabGearFromGround::AutoGrabGearFromGround() {
	/*
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
	 *
	 */

	if (Robot::gearPCM->GetPCMStatus() == PCMStatus::OPENED)
	{
		AddSequential(new MoveToGround());
		AddSequential(new ControlDriveTrain(0, 1, 0, 0.5));
		AddSequential(new ToggleGearPCM(PCMStatus::CLOSED));
		AddSequential(new MoveToHook());
	}
}
