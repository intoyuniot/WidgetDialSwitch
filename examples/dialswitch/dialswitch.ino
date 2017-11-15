/*
************************************************************************
* 作者:  IntoRobot Team    
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
拨码开关

所需器件:

*/
/*该头文件引用由IntoRobot自动添加.*/
#include <WidgetDialSwitch.h>

WidgetDialSwitch dialKey;

#define LED1  D0
#define LED2  D1
#define LED3  D2

void DialCb(void)
{
    if(dialKey.getSwitch1())
    {
        dialKey.controlSwitch(LED1,HIGH);
    }
    else
    {
        dialKey.controlSwitch(LED1,LOW);
    }
    
    if(dialKey.getSwitch2())
    {
        dialKey.controlSwitch(LED2,HIGH);
    }
    else
    {
        dialKey.controlSwitch(LED2,LOW);
    }
    
    if(dialKey.getSwitch3())
    {
        dialKey.controlSwitch(LED3,HIGH);
    }
    else
    {
        dialKey.controlSwitch(LED3,LOW);
    }
}

void setup() 
{
    // put your setup code here, to run once.
    dialKey.begin(DialCb);
}

void loop() 
{
    // put your main code here, to run repeatedly.

}
