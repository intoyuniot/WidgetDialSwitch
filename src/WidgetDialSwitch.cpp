#include "WidgetDialSwitch.h"


WidgetDialSwitch::WidgetDialSwitch(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdTopic,0,sizeof(pCmdTopic));
    sprintf(pCmdTopic,"channel/dialSwitch_%d/cmd/cmd",_Item);
}

WidgetDialSwitch::~WidgetDialSwitch()
{
}

void WidgetDialSwitch::begin(void (*UserCallBack)(void))
{
    _EventCb = UserCallBack;
    IntoRobot.subscribe(pCmdTopic,NULL,this);
}


uint8_t WidgetDialSwitch::getSwitch1(void)
{
    
    return _switch1Key;
}

uint8_t WidgetDialSwitch::getSwitch2(void)
{
   
    return _switch2Key;
}

uint8_t WidgetDialSwitch::getSwitch3(void)
{
    
    return _switch3Key;
}

void WidgetDialSwitch::controlSwitch(uint8_t pin,uint8_t ucVal)
{
    pinMode(pin,OUTPUT);
    digitalWrite(pin,ucVal);
}



void WidgetDialSwitch::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    aJsonClass aJson;
    
    aJsonObject *root = aJson.parse((char *)payload);
	if(root == NULL)
	{
	    aJson.deleteItem(root);
		return;
	}

	aJsonObject *switch1 = aJson.getObjectItem(root, "switch1");
	if(switch1 == NULL)
	{
	    aJson.deleteItem(root);
		return;	    
	}
	_switch1Key = atoi(switch1->valuestring);

	aJsonObject *switch2 = aJson.getObjectItem(root, "switch2");
	if(switch2 == NULL)
	{
	    aJson.deleteItem(root);
		return;	    
	}
	_switch2Key = atoi(switch2->valuestring);

	aJsonObject *switch3 = aJson.getObjectItem(root, "switch3");
	if(switch3 == NULL)
	{
	    aJson.deleteItem(root);
		return;	    
	}
	_switch3Key = atoi(switch3->valuestring);

    _EventCb();
}

