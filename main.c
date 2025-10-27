#include "Breaking Bad Header.h"


int main(int argc, char** argv)
{
	logo();
	printf("\n");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	//HANDLE hWatchDog = WatchDogInitializer();
	HANDLE hWatchDog;
	int auto_mode = 0;
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "--auto") == 0 || strcmp(argv[i], "--watchdog") == 0) {
			auto_mode = 1;
			break;
		}
	}

	


	if (auto_mode) {
		hWatchDog = WatchDogInitializer();
		mode_1(hWatchDog);
		CloseHandle(hWatchDog);
		if (!kill_process_by_name(L"Breaking Bad Watchdog.exe")) {
			wprintf(L"No matching process found or failed to terminate.\n");
		}
	}
	else {
		printf("Running in interactive/user mode\n"); // logo here
		int mode;
		printf("Chose a Mode: ");
		scanf_s("%d", &mode);

		switch (mode)
		{
		case 2:
			;
			hWatchDog = WatchDogInitializer();
			mode_1(hWatchDog);
			CloseHandle(hWatchDog);
			if (!kill_process_by_name(L"Breaking Bad Watchdog.exe")) {
				wprintf(L"No matching process found or failed to terminate.\n");
			}
			break;
		case 1:
			;
			int amount;
			printf("How much ");
			SetConsoleTextAttribute(hConsole, 9);
			printf("meth ");
			SetConsoleTextAttribute(hConsole, 14);
			printf("do you want: ");
			scanf_s("%d", &amount);
			mode_2(amount);
			SetConsoleTextAttribute(hConsole, 4);
			printf("I Liked it\n");
			SetConsoleTextAttribute(hConsole, 7);

			/*
			CloseHandle(hWatchDog);

			if (!kill_process_by_name(L"Breaking Bad Watchdog.exe")) {
				wprintf(L"No matching process found or failed to terminate.\n");
			}*/
			break;
		}
	}

	
	
	


	return EXIT_SUCCESS;
}