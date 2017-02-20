#include "VisionProcessing.h"
#include <thread>
#include <chrono>
VisionProcessing::VisionProcessing() {
	Requires(Robot::vision.get());

	camera = CameraServer::GetInstance()->StartAutomaticCapture();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	cvSink = CameraServer::GetInstance()->GetVideo();

	camera.SetResolution(480, 640);
	outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 480, 640);


	test = 0;
}

// Called just before this Command runs the first time
void VisionProcessing::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void VisionProcessing::Execute() {

	cvSink.GrabFrame(source);
	cv::cvtColor(source, output, cv::COLOR_BGR2GRAY);
	outputStreamStd.PutFrame(output);
}

// Make this return true when this Command no longer needs to run execute()
bool VisionProcessing::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void VisionProcessing::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionProcessing::Interrupted() {

}
