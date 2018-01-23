#pragma once 

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <SerialStream.h>
#include <SerialPort.h>

#include <boost/lexical_cast.hpp>

using namespace std; 

class Tango{
	
  public:
    Tango(double t= 9600, string port="/dev/ttyUSB0"); 
    virtual ~Tango(); 

  protected :
    // LibSerial::SerialPort   my_serial_port( "/dev/rfcomm0");
    LibSerial::SerialStream _phone;

    std::string PORT;
    double Baud;	

    public:
    /**************************************************
      Basic serial operations
     **************************************************/
    void writePort(std::string& str);
    string readPort();
};


