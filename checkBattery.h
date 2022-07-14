
#define E_NOT_OK      0
#define E_OK          1
#define TEMP_MIN      0
#define TEMP_MAX      45
#define SOC_MIN       20
#define SOC_MAX       80
#define CHARGE_LIMIT  0.8

int Checktemperature(float temperature);
int checkSoc(float soc);
int checkChargerate(float chargeRate);
int checkParameterMargin(float param,float min_margin , float max_margin);
int checkParameterLimit(float param, float limit);
void IsReachingWarningLevel(char *param,float value,float min_margin , float max_margin);
