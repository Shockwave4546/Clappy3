#ifndef VisionProcessing_H
#define VisionProcessing_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class VisionProcessing : public Command {
public:
	VisionProcessing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	cs::UsbCamera camera;
	cs::CvSink cvSink;
	cv::Mat source;
	cv::Mat output;
};

#endif  // VisionProcessing_H
