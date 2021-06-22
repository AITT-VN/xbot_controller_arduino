#include "port.h"

Port::Port(uint8_t port){
    s1 = Port_Digital[port].s1;
    s2 = Port_Digital[port].s2;
    _port = port;
}

uint8_t Port::getPort()
{
  return(_port);
}

int Port::pin1(void)
{
  return(s1);
}

int Port::pin2(void)
{
  return(s2);
}


