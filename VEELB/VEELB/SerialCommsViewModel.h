#pragma once

using namespace std;

namespace VEELB
{
	public ref class SerialCommsViewModel sealed
	{
	 private:     
	 	Windows::Foundation::Collections::IVector<Platform::Object^>^ _availableDevices;
        Windows::Devices::SerialCommunication::SerialDevice ^_serialPort;
     	Windows::Storage::Streams::DataWriter^ _dataWriterObject;
     	Windows::Storage::Streams::DataReader^ _dataReaderObject;
    	Concurrency::cancellation_token_source* cancellationTokenSource;
		
		void Listen(); 		
		void ListAvailablePorts(void);
		void CancelReadTask(void);
		void CloseDevice(void);
		int CreateChecksum(Platform::String^ message);
		bool IsTracer(Platform::String^ id);
		Concurrency::task<void> WriteAsync(Concurrency::cancellation_token cancellationToken, Platform::String^ message);
		Concurrency::task<void> ReadAsync(Concurrency::cancellation_token cancellationToken);
		//Concurrency::task<void> ConnectToSerialDeviceAsync(Windows::Devices::Enumeration::DeviceInformation ^device, Concurrency::cancellation_token cancellationToken);

	 public:
		static Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection ^> ^ListAvailableSerialDevicesAsync(void);
		void sendJob(Platform::String^ jobNum);
		void ConnectToTracer();
		Windows::Foundation::Collections::IVector<Platform::Object^>^ getAvailableDevices();
		
	};

}