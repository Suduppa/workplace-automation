#pragma once
#include <iostream>

using namespace std;

const int numberOfDev = 10;

class Device
{
public:
	int id;
	int status;

	string GetStatus();
	string GetName();
	void setDevice(int id);
};

ref class Devices
{
public:
	Device* devices;

	Devices() 
	{ 
		devices = new Device[numberOfDev];
	}

	~Devices() { delete[] devices; }

	void LoadDevices();	
};

void Devices::LoadDevices() 
{
	for (int i = 0; i < numberOfDev; i++)
		devices[i].setDevice(i);
}

string Device::GetStatus()
{
	string stat = "";

	switch (status)
	{
	case 0:
		stat = "Не осмотрен";
		break;
	case 1:
		stat = "Проверено";
		break;
	case 2:
		stat = "Неисправен";
		break;
	}

	return stat;
}

string Device::GetName()
{
	string name = "";

	switch (id)
	{
	case 0:
		name = "Бронхоскоп";
		break;
	case 1:
		name = "Ингалятор";
		break;
	case 2:
		name = "Очиститель воздуха";
		break;
	case 3:
		name = "Анализатор ИВД";
		break;
	case 4:
		name = "Кейджи костные";
		break;
	case 5:
		name = "Диоптриметр";
		break;
	case 6:
		name = "Измеритель излучения";
		break;
	case 7:
		name = "Протезы";
		break;
	case 8:
		name = "Ангиоскоп";
		break;
	case 9:
		name = "Артериоскоп";
		break;
	}

	return name;
}

void Device::setDevice(int id)
{
	this->id = id;
	this->status = 0;
}