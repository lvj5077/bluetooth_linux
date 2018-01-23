#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

int main() 
{
    cout << "Hello";
    system("sdptool browse 54:27:58:C0:3C:DE > testFile.txt");

    ifstream in("testFile.txt");

	if(!in) {
	cout << "Cannot open input file.\n";
	return 1;
	}

	string str;

	bool findService = false;
	bool findChannel = false;
	int lineN = 0;
	int channelNum = -1;
	while(getline(in, str)) {
		lineN++;
		cout << lineN << " " << str << endl;

		if (!findChannel){
			if(!findService){
				if (str.find( "TestService", 0 ) != -1){
					cout << "~~~~~~~~~~~~~~~~~ Found TestService" << endl;
					findService = true;
					cout << lineN << " " << str << endl;
				}
			}

			if(findService){
				if (str.find( "Channel", 0 )!= -1){
					cout << "~~~~~~~~~~~~~~~~~ Found Channel" << endl;
					findChannel = true;
					cout << lineN << " " << str << endl;
					channelNum = atoi(str.substr(13).c_str()); 
				}
			}
		}
	}

	in.close();
	if (!findChannel){
		cout << "Cannot find target channel" << endl;
		return 1;
	}
	cout << "channelNum = " << channelNum <<endl;

	stringstream ss;
	ss << "sudo rfcomm bind /dev/rfcomm0 54:27:58:C0:3C:DE  " << channelNum;
	string cmd;
	cmd = ss.str();
	cout << "cmd = " << cmd <<endl;

	system(cmd.c_str());
    return 0;
}