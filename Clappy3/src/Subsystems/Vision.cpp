#include "Vision.h"
#include "../RobotMap.h"
#include "../Commands/VisionProcessing.h"

Vision::Vision() : Subsystem("ExampleSubsystem") {

}

void Vision::InitDefaultCommand() {
	SetDefaultCommand(new VisionProcessing());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
