#include <stdio.h>
#include <assert.h>
#include "checkBattery.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
return (Checktemperature(temperature) && checkSoc(soc) && checkChargerate(chargeRate));
}

float convertFarenheitToCelcius(float temp)
{
    return (temp - 32.0) * (5.0 / 9.0);
}

int Checktemperature(float temperature)
{
    int result;
    char name[] = "Temperature";
    result = checkParameterMargin(GET_TEMPERATURE_IN_CELCIUS(temperature),TEMP_MIN,TEMP_MAX) ; 
    IsReachingWarningLevel(name,GET_TEMPERATURE_IN_CELCIUS(temperature),TEMP_MIN,TEMP_MAX);
    return result;
}

int checkSoc(float soc){
    int result;
    char name[] = "Soc";
    result = checkParameterMargin(soc, SOC_MIN, SOC_MAX) ;
    IsReachingWarningLevel(name,soc, SOC_MIN, SOC_MAX);
    return result;
}

int checkChargerate(float chargeRate){
    int result;
    char name[] = "chargeRate";
    result = checkParameterLimit(chargeRate,CHARGE_LIMIT) ;
    IsReachingWarningLevel(name,chargeRate,0.0,CHARGE_LIMIT);
    return result;
}

int checkParameterMargin(float param,float min_margin , float max_margin)
{
    int result = E_OK;
    

    if(param < min_margin || param > max_margin)
    {
        printf("%f  out of range!\n", param);
        result = E_NOT_OK;
    }

    else 
    {
        printf("%f In range!\n",param);
        result = E_OK;
    }

    return result;
}

void IsReachingWarningLevel(char *param,float value,float min_margin , float max_margin)
{
    int result = E_OK;
    float tol_percent = 0.05;
    float tolerance = (max_margin * tol_percent);
    
    if ((value > min_margin) && (value <= (min_margin+tolerance)))
    {
        printf("Warning! %s reaching minimum level\n",param);
    }
    else if ((value >= (max_margin - tolerance)) && (value < max_margin))
    {
        printf("Warning! %s reaching maximum level\n",param);
    }
    else
    {
        printf("%f Safe Zone!\n",value);
    }

}

int checkParameterLimit(float param, float limit)
{
	int result = E_OK;
	if (param > limit)
	{
	    printf("%f  out of range!\n", param);
	    result = E_NOT_OK;
	}
	else
	{
	    printf("%f In range!\n",param);
            result = E_OK;
        }
        return result;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(44, 77, 0.9));
}
    
