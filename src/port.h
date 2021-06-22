#ifndef _PORT_H
#define _PORT_H

#include "Arduino.h"

typedef struct 
{
  int s1;
  int s2;
}Sig_t;

extern Sig_t Port_Digital[6]; 

class Port
{
    public:
        /**
         * Alternate Constructor which can call your own function to map the Port to arduino port,
         * \param[in]
        */
        Port(uint8_t port);
        uint8_t getPort(void);
        int pin1(void);
        int pin2(void);
    
    protected:
        /**
         *  \par Description
         *  Variables used to store the slot1 gpio number
         */
        int s1;

        /**
         *  \par Description
         *  Variables used to store the slot2 gpio number
         */
        int s2;

        /**
         *  \par Description
         *  Variables used to store the port
         */

        uint8_t _port;
};

#endif

