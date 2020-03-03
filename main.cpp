#include<iostream>
#include<fstream>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

class CharacterVideo
{
	public:
		HANDLE handle;
		COORD coord;

		void renewfile(char*fileName, int fileNo)
		{
			sprintf(fileName, "%s%d%s","baascii\\ba(", fileNo, ").txt");
		}
		void recursor(int x, int y)
		{
			coord.X=x;
			coord.Y=y;
			handle =GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(handle, coord);
		}
};


int main(){
 	CharacterVideo cv;
 	cv.recursor(0,0);
 	char fileName[22]={"baascii\\ba(0).txt"};
 	string str;
 	int i=0,delayTime=33;
	clock_t startTime,finishTime;
 	ifstream File(fileName);
	startTime=clock();
 	PlaySound(("ascii.wav"),NULL,SND_FILENAME | SND_ASYNC);
    cin.get();

 	while(i<=1266)
 	{
		if(i%30==0)
			delayTime =43;
		else
			delayTime=33;
		cv.renewfile(fileName,i);
		finishTime=clock();

		if((finishTime-startTime)>=delayTime)
		{
		i++;
 		File.open(fileName);
		while(File.good())
		{
			getline(File,str);
			cout << str;
		}
		File.close();
		startTime +=delayTime;

		cv.recursor(0,0);
		}
	}cout << "hello world" <<endl;
	return 0;
 }
