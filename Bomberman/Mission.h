#pragma once
#include<iostream>
using namespace std;
int GetMission(int key_score) {
	int mission = 0;
	if (key_score == 1)
		mission = 1;
	else if (key_score == 0)
		mission = 2;
	return mission;
}

    string MissionText(int number_mission) {
	string text_mission = "\t\t\t:Missions:\n";
	switch (number_mission)
	{
	case 1:
	{
		text_mission += "1.Find the key\n";
		break;
	}
	case 2:
	{
		text_mission += "2.Go to exit\n";
		break;
	}
	}
	return text_mission;
}
