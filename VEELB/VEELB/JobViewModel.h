#pragma once
using namespace std;

namespace VEELB
{
	public ref class JobViewModel sealed
	{
	public:
		void Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance^ taskInstance);
		void Start(Windows::ApplicationModel::Background::IBackgroundTaskInstance^ taskInstance);
		JobViewModel(Platform::String^ jobNumber);
		JobViewModel();
	private:
		Platform::String^ jobNumber;
		double xPosition;
		double yPosition;
	};
}
