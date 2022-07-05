#include <stdio.h>
#include <assert.h>

#define E_NOT_OK 0
#define E_OK     1

int batteryIsOk(float temperature, float soc, float chargeRate) {
return (Checktemperature(temperature) && checkSoc(soc) && checkChargerate(chargeRate));
}

int Checktemperature(float temperature){
int result = E_NOT_OK;
if (temperature < 0 || temperature > 45)
{
result =  E_OK;
}
return result;
}

int checkSoc(float soc){
int result = E_NOT_OK;
if(soc < 20 || soc > 80)
{
result =  E_OK;
}
return result;
}

int checkChargerate(float chargerate){
int result = E_NOT_OK;
if(chargeRate > 0.8)
{
result =  E_OK;
}
return result;
}
    
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
    
