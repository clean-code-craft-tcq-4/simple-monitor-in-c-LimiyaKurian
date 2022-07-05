#include <stdio.h>
#include <assert.h>
#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
return (Checktemperature(temperature) && checkSoc(soc) && checkChargerate(chargeRate));
}

int Checktemperature(float temperature){
int result = E_OK;
if (temperature < 0 || temperature > 45)
{
printf("Temperature out of range!\n");
result =  E_NOT_OK;
}
return result;
}

int checkSoc(float soc){
int result = E_OK;
if(soc < 20 || soc > 80)
{
printf("State of Charge out of range!\n");
result =  E_NOT_OK;
}
return result;
}

int checkChargerate(float chargeRate){
int result = E_OK;
if(chargeRate > 0.8)
{
printf("Charge Rate out of range!\n");
result =  E_NOT_OK;
}
return result;
}
    
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
    
