#ifndef WIDGET_DIALSWITCH_H_
#define WIDGET_DIALSWITCH_H_

#include "application.h"

class WidgetDialSwitch : public WidgetBaseClass
{
    public:
        WidgetDialSwitch(uint8_t ucItem = 0);
        ~WidgetDialSwitch();
        void begin(void (*UserCallBack)(void) = NULL);
        uint8_t getSwitch1(void);
        uint8_t getSwitch2(void);
        uint8_t getSwitch3(void);
        void controlSwitch(uint8_t pin,uint8_t ucVal);

    private:
        char pCmdTopic[64];
        uint8_t _Item = 0;
        
        uint8_t _switch1Key = 0;
        uint8_t _switch2Key = 0;
        uint8_t _switch3Key = 0;
        

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
