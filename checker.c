#include <stdio.h>
#include <assert.h>
#include "checker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
return (Checktemperature(temperature) && checkSoc(soc) && checkChargerate(chargeRate));
}

int Checktemperature(float temperature){
return checkparametermargin(temperature,TEMP_MIN,TEMP_MAX) ;
}

int checkSoc(float soc){
return checkparametermargin(soc, SOC_MIN, SOC_MAX);
}

int checkChargerate(float chargeRate){
return checkparalimit(chargeRate,CHARGE_LIMIT);
}

int checkparametermargin(float param,float min_margin , float max_margin)
{
int result = E_OK;
if(param < min_margin || param > max_margin){
printf("%f  out of range!\n", param);
result = E_NOT_OK;
}
return result;
}

int checkparalimit(float param, float limit)
{
int result = E_OK;
if (param > limit){
printf("%f  out of range!\n", param);
result = E_NOT_OK;
}
return result;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
    
