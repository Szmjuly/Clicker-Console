#include <iostream>
#include <Windows.h>

using namespace std;

bool RightClick, LeftClick = false;


void menu()
{
	cout << "Press NumPad 1 For RightClick\n"
		"Press Numpad 2 To STOP RightClick\n"
		"Press Numpad 4 For LeftClick\n"
		"Press Numpad 5 To STOP LeftClick\n";
}

void RightClickFunc()
{
	//Debug
	//cout << "In RightClickFun\n";
	if (GetAsyncKeyState(VK_NUMPAD1))
	{
		//Debug
		cout << "Right Click True...\n";
		RightClick = true;
	}
	else if (GetAsyncKeyState(VK_NUMPAD2))
	{
		//Debug
		cout << "Right Click False...\n";
		RightClick = false;
	}


}
void LeftClickFunc()
{
	//Debug
	//cout << "In LeftClickFun\n";
	if (GetAsyncKeyState(VK_NUMPAD4))
	{
		//Debug
		cout << "Left Click True...\n";
		LeftClick = true;
	}
	else if (GetAsyncKeyState(VK_NUMPAD5))
	{
		//Debug
		cout << "Left Click False...\n";
		LeftClick = false;
	}


}

int main()
{
	menu();
	while (true)
	{
		RightClickFunc();
		LeftClickFunc();

		if (RightClick == true)
		{
			//Debug
			//cout << "Rclicking\n";
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			Sleep(10);
		}
		if (LeftClick == true)
		{
			//Debug
			//cout << "Lclicking\n";
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(5000); // 1000 = 1 sec || 60000 = 1 min || 120000 = 2 min
		}
	}
}