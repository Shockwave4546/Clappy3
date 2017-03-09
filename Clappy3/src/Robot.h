#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/AutonomousCommand.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearPCM.h"
#include "Subsystems/GearArm.h"
//#include "Subsystems/Vision.h"
#include "OI.h"
#include "Subsystems/Climber.h"
#include <networktables/NetworkTable.h>

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

    static std::shared_ptr<DriveTrain> driveTrain;
    static std::shared_ptr<GearPCM> gearPCM;
    static std::shared_ptr<GearArm> gearArm;
    //static std::shared_ptr<Vision> vision;
    static std::shared_ptr<Climber> climber;



	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	void ChangeCamera();

private:
    std::shared_ptr<cs::UsbCamera> cam0;
    std::shared_ptr<cs::UsbCamera> cam1;
    std::shared_ptr<cs::MjpegServer> mjpegServer;
};
#endif
