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
		stat = "�� ��������";
		break;
	case 1:
		stat = "���������";
		break;
	case 2:
		stat = "����������";
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
		name = "����������";
		break;
	case 1:
		name = "���������";
		break;
	case 2:
		name = "���������� �������";
		break;
	case 3:
		name = "���������� ���";
		break;
	case 4:
		name = "������ �������";
		break;
	case 5:
		name = "�����������";
		break;
	case 6:
		name = "���������� ���������";
		break;
	case 7:
		name = "�������";
		break;
	case 8:
		name = "���������";
		break;
	case 9:
		name = "�����������";
		break;
	}

	return name;
}

void Device::setDevice(int id)
{
	this->id = id;
	this->status = 0;
}