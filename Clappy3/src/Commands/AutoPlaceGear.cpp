#include "AutoPlaceGear.h"
#include "MoveToTarget.h"
#include "ToggleGearPCM.h"
#include "ControlDriveTrain.h"
#include "MoveToShoot.h"
#include "AutoGrabGearFromGround.h"

AutoPlaceGear::AutoPlaceGear() {
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

	if (Robot::gearPCM->GetPCMStatus() == PCMStatus::CLOSED)
	{
		AddSequential(new MoveToTarget(Target::HOOK));
		AddSequential(new ControlDriveTrain(0, 1, 0, 0.5));
		AddSequential(new ToggleGearPCM(PCMStatus::OPENED));
		AddParallel(new MoveToShoot());
		AddParallel(new ControlDriveTrain(0, -1, 0, 0.5));
	}
}
