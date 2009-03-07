#include <QList>

#include <KComponentData>
#include <KCmdLineArgs>
#include <KLocale>
#include <KDebug>

#include <Solid/DeviceNotifier>
#include <Solid/Device>
#include <Solid/Processor>
#include <Solid/StorageDrive>
#include <Solid/StorageVolume>
#include <Solid/StorageAccess>

#include <iostream>

int main(int argc, char *argv[]) {
	KComponentData cData("hprinter");

	QList<Solid::Device> list = Solid::Device::allDevices();
	
	Solid::Device device;
	Solid::DeviceInterface *deviceInterface;
	Solid::StorageAccess *accessStorage;
	Solid::StorageVolume *volumeStorage;
	Solid::StorageDrive *driveStorage;

	for (int i = 0; i < list.count(); i++) {	
		device = list[i];
		
		if (device.isValid()) {
			if (device.is<Solid::StorageDrive>())
				kDebug() << "device.is a storage drive";
			if (device.is<Solid::StorageAccess>()) {
				kDebug() << "device is a storage access";
				if (deviceInterface = device.asDeviceInterface(Solid::DeviceInterface::StorageDrive))
					kDebug() << "device interface";
				if (driveStorage = device.as<Solid::StorageDrive>())
					kDebug() << "storage drive";
				if (volumeStorage = device.as<Solid::StorageVolume>())
					kDebug() << "storage volume";
				if (accessStorage = device.as<Solid::StorageAccess>())
					kDebug() << "storage access";
				
				if (driveStorage) {
					kDebug() << "it's a drive storage";
					if (driveStorage->driveType() == Solid::StorageDrive::MemoryStick) {
						kDebug() << "Yes!";
					}
				}
			}
		}
	}
/*	
	kDebug() << "";
	
	for (int i = 0; i < list2.count(); i++) {
		Solid::Device device = list2[i];
		QString udi2 = device.udi();
		//kDebug() << udi2.toLatin1().constData();
		if (Solid::StorageVolume *sv = device.as<Solid::StorageVolume>()) {
			kDebug() << sv->label();
			if (udi2 == udi) {
				kDebug() << "label: " << sv->label();
			}
		}
	}
*/
	return 0;
}
