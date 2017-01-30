#include "pch.h"
#include "JobViewModel.h"
#include "SerialCommsViewModel.h"

using namespace VEELB;
using namespace Windows::ApplicationModel::Background;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::System::Threading;
using namespace std;

SerialCommsViewModel^ _serialViewModel;

void JobViewModel::Run(IBackgroundTaskInstance^ taskInstance)
{

}

JobViewModel::JobViewModel(Platform::String^ jobNumberIn)
{
	jobNumber = jobNumberIn;
	_serialViewModel = ref new SerialCommsViewModel();
	_serialViewModel->sendJob(jobNumber);
}

JobViewModel::JobViewModel()
{
}

void JobViewModel::Start(IBackgroundTaskInstance^ taskInstance)
{
	// Use the taskInstance->Name and/or taskInstance->InstanceId to determine
	// what background activity to perform. In this sample, all of our
	// background activities are the same, so there is nothing to check.
	auto activity = ref new JobViewModel();
	activity->Run(taskInstance);
}