#include "tango.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <ctime>
#include <sys/stat.h>
#include <stdio.h>      

using namespace std; 


int main(int argc, char* argv[])
{
	Tango myphone(115200,"/dev/rfcomm0"); 

	int count = 0;
	while(1){
		count ++;
		stringstream ss;
		ss << "hello world " << count << "\n";
		string sendOut = ss.str();
		if (count == 5){
			myphone.writePort(sendOut);
		}
		if (count == 10){
			myphone.writePort(sendOut);
		}	
		if ( myphone.readPort()!= "" ){
			std::cout << "received: "<< myphone.readPort() << std::endl;
		}

	   	usleep(30);	
	}

	return 0; 
}
