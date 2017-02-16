#include "Robot.h"

std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<GearPCM> Robot::gearPCM;
std::shared_ptr<GearArm> Robot::gearArm;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

    driveTrain.reset(new DriveTrain());
    gearPCM.reset(new GearPCM());
    gearArm.reset(new GearArm());
	oi.reset(new OI());

	autonomousCommand.reset(new AutonomousCommand());

  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	driveTrain->SetDirection(Direction::FORWARD);
	gearArm->Zero();

}

void Robot::TeleopPeriodic() {

	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Top Left Motor", driveTrain->GetMotorD(DriveMotor::TOP_LEFT));
	SmartDashboard::PutNumber("Top Right Motor", driveTrain->GetMotorD(DriveMotor::TOP_RIGHT));
	SmartDashboard::PutNumber("Bottom Left Motor", driveTrain->GetMotorD(DriveMotor::BOTTOM_LEFT));
	SmartDashboard::PutNumber("Bottom Right Motor", driveTrain->GetMotorD(DriveMotor::BOTTOM_RIGHT));
	SmartDashboard::PutNumber("Center Motor", driveTrain->GetMotorD(DriveMotor::CENTER));
	SmartDashboard::PutString("Robot Direction", driveTrain->GetDirectionS());
	SmartDashboard::PutString("GearPCM Status", gearPCM->GetPCMStatusS());
	SmartDashboard::PutNumber("Encoder Position", gearArm->GetDegreesD());
	SmartDashboard::PutNumber("gy", (Robot::oi->getGearStick()->GetY() * 360 < 0.0) ? 0.0 : Robot::oi->getGearStick()->GetY() * 360);
	SmartDashboard::PutBoolean("Limit Switch", gearArm->GetHomeSwitch());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

