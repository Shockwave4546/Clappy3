#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "WPILib.h"

std::shared_ptr<SpeedController> RobotMap::driveTrainTopLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainTopRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainCenter;

std::shared_ptr<Compressor> RobotMap::gearPCMCompressor;
std::shared_ptr<Solenoid> RobotMap::gearPCMSolenoid;

std::shared_ptr<SpeedController> RobotMap::gearArmMotor;
std::shared_ptr<Encoder> RobotMap::gearArmEncoder;
std::shared_ptr<DigitalInput> RobotMap::gearArmSwitch;
std::shared_ptr<PIDController> RobotMap::gearArmPIDController;

void RobotMap::init() {

    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainTopLeft.reset(new TalonSRX(0));
    lw->AddActuator("DriveTrain", "TopLeft", std::static_pointer_cast<TalonSRX>(driveTrainTopLeft));
    driveTrainTopLeft->StopMotor();

    driveTrainTopRight.reset(new TalonSRX(1));
    lw->AddActuator("DriveTrain", "TopRight", std::static_pointer_cast<TalonSRX>(driveTrainTopRight));
    driveTrainTopRight->StopMotor();
    
    driveTrainBottomLeft.reset(new TalonSRX(2));
    lw->AddActuator("DriveTrain", "BottomLeft", std::static_pointer_cast<TalonSRX>(driveTrainBottomLeft));
    driveTrainBottomLeft->StopMotor();
    
    driveTrainBottomRight.reset(new TalonSRX(3));
    lw->AddActuator("DriveTrain", "BottomRight", std::static_pointer_cast<TalonSRX>(driveTrainBottomRight));
    driveTrainBottomRight->StopMotor();
    
    driveTrainCenter.reset(new TalonSRX(4));
    lw->AddActuator("DriveTrain", "Center", std::static_pointer_cast<TalonSRX>(driveTrainCenter));
    driveTrainCenter->StopMotor();



    gearPCMCompressor.reset(new Compressor());
    lw->AddActuator("GearPCM", "Compressor", gearPCMCompressor);
    gearPCMCompressor->Start();

    gearPCMSolenoid.reset(new Solenoid(0));
    lw->AddActuator("GearPCM", "Solenoid", gearPCMSolenoid);



    gearArmMotor.reset(new TalonSRX(5));
    lw->AddActuator("GearArm", "Motor", std::static_pointer_cast<TalonSRX>(gearArmMotor));
    gearArmMotor->StopMotor();

    gearArmEncoder.reset(new Encoder(0, 1, true));
    lw->AddSensor("GearArm", "Encoder", gearArmEncoder);
    gearArmEncoder->SetDistancePerPulse(360/497);

    gearArmSwitch.reset(new DigitalInput(2));
    lw->AddSensor("GearArm", "HomeSwitch", gearArmSwitch);

    gearArmPIDController.reset(new PIDController(1.0, 0.0, 0.0,/* F: 0.0, */ gearArmEncoder.get(), gearArmMotor.get(), 0.02));
    lw->AddActuator("GearArm", "PIDController", gearArmPIDController);
    gearArmPIDController->SetContinuous(false);
    gearArmPIDController->SetAbsoluteTolerance(2);
    gearArmPIDController->SetOutputRange(-1.0, 1.0);


}
