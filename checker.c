#include <stdio.h>
#include <assert.h>

int Checktemperature(float temperature);
int checkSoc(float soc);
int checkChargerate(float chargeRate);

#define E_NOT_OK 0
#define E_OK     1

int batteryIsOk(float temperature, float soc, float chargeRate) {
return (Checktemperature(temperature) && checkSoc(soc) && checkChargerate(chargeRate));
}

int Checktemperature(float temperature){
int result = E_OK;
if (temperature < 0 || temperature > 45)
{
result =  E_NOT_OK;
}
printf("%d", result);
return result;
}

int checkSoc(float soc){
int result = E_OK;
if(soc < 20 || soc > 80)
{
result =  E_NOT_OK;
}
printf("%d", result);
return result;
}

int checkChargerate(float chargeRate){
int result = E_OK;
if(chargeRate > 0.8)
{
result =  E_NOT_OK;
}
printf("%d", result);
return result;
}
    
int main() {
  assert(Checktemperature(25));
  assert(checkSoc(70));
  assert(checkChargerate(0.7));
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
    
