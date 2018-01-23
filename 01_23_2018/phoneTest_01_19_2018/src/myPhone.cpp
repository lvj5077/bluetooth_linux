#include "tango.h"

using namespace std; 
Tango::Tango(double t, std::string port) : PORT(port), Baud(t)
{
  std::cout << "The phone is=> Baud "<< Baud<<" Port "<< PORT<<std::endl;
  _phone.Open(PORT);		

  if ( ! _phone.good() ){
    std::cerr << "Error: Could not open serial port "<<PORT<< std::endl ;
    exit(1) ;
  }

  if(Baud==115200){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_115200);
    std::cout<<"Going for value of 115200"<<std::endl;
  }
  else if(Baud==1200){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_1200);
    std::cout<<"Going for value of 1200"<<std::endl;
  }
  else if(Baud==2400){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_2400);
    std::cout<<"Going for value of 2400"<<std::endl;
  }
  else if(Baud==19200){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_19200);
    std::cout<<"Going for value of 19200"<<std::endl;
  }
  else if(Baud==38400){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_38400);
    std::cout<<"Going for value of 38400"<<std::endl;
  }
  else if(Baud==57600){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_57600);
    std::cout<<"Going for value of 57600"<<std::endl;
  }
  else if(Baud==9600){
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
    std::cout<<"Going for default value of 9600"<<std::endl;
  }
  else{
    std::cout<<"Value incorrect. Going for default value of 9600"<<std::endl;
    _phone.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
  }

  if ( ! _phone.good() ){
    std::cerr << "Error: Could not set the baud rate." <<std::endl;
    exit(1);
  }		


  _phone.SetCharSize(LibSerial::SerialStreamBuf::CHAR_SIZE_8);
  if ( ! _phone.good() ){
    std::cerr << "Error: Could not set the char size." <<std::endl;
    exit(1);
  }
  _phone.SetParity( LibSerial::SerialStreamBuf::PARITY_NONE ) ;
  if ( ! _phone.good() ){
    std::cerr << "Error: Could not set the parity." <<std::endl;
    exit(1);
  }
  _phone.SetFlowControl(LibSerial::SerialStreamBuf::FLOW_CONTROL_NONE ) ;
  if ( ! _phone.good() ){
    std::cerr << "Error: Could not set the control." <<std::endl;
    exit(1);
  }
  _phone.SetNumOfStopBits(1) ;
  if ( ! _phone.good() ){
    std::cerr << "Error: Could not set the stopbit." <<std::endl;
    exit(1);
  }

}

/****************************Basic functon*******************************************/

void Tango::writePort(std::string& str){
  _phone << str;
  std::cout << "wrote comand: "<<str.c_str()<< std::endl;
}

string Tango::readPort(){


  // Read one character from the serial port.
  char next_char;
  _phone >> next_char;

  // You can also read other types of values from the serial port in a similar fashion.
  int data_size;
  _phone >> data_size;

  // std::cout << "received comand: "<<data_size<< "" << next_char << std::endl;

  std::string i;
  // _phone >> i;
  // std::cout << "received comand: "<<i<< std::endl;
  if(data_size >0){
    _phone >> i;
    return i;
    // try{
    //   return boost::lexical_cast<int>(i);
    // }
    // catch(boost::bad_lexical_cast& blc){
    //   continue;
    // }
  } 

}



// inline int CMotor::readPort(){
//   std::string i;
//   while(_motor.rdbuf()->in_avail() >0){
//     _motor>> i;
//     try{
//       return boost::lexical_cast<int>(i);
//     }
//     catch(boost::bad_lexical_cast& blc){
//       continue;
//     }
//   } 
// }




Tango::~Tango(){
  _phone.Close();
}

