#include <Arduino.h>
#define FONT(x) x##_tf

//Temperature - Humidity - Forecast
const String TXT_TEMPERATURE_C    = "Hõmérséklet (°C)";
const String TXT_TEMPERATURE_F    = "Hõmérséklet (°F)";
const String TXT_HUMIDITY_PERCENT = "Páratartalom (%)";
const String TXT_HILO             = "Max/Min";
const String TXT_FEELSLIKE        = "Hõérzet";

// Pressure
const String TXT_PRESSURE_HPA     = "Légnyomás (hPa)";
const String TXT_PRESSURE_IN      = "Légnyomás (in)";

//RainFall / SnowFall
const String TXT_RAINFALL_MM = "Csapadék (mm)";
const String TXT_RAINFALL_IN = "Csapadék (in)";
const String TXT_SNOWFALL_MM = "Havazás (mm)";
const String TXT_SNOWFALL_IN = "Havazás (in)";

//Moon
const String TXT_MOON_NEW             = "Újhold";
const String TXT_MOON_WAXING_CRESCENT = "Növekvõ holdsarló";
const String TXT_MOON_FIRST_QUARTER   = "Elsõ negyed";
const String TXT_MOON_WAXING_GIBBOUS  = "Növekvõ domború hold";
const String TXT_MOON_FULL            = "Telihold";
const String TXT_MOON_WANING_GIBBOUS  = "Fogyó domború hold";
const String TXT_MOON_THIRD_QUARTER   = "Utolsó negyed";
const String TXT_MOON_WANING_CRESCENT = "Fogyó holdsarló";

//Wind
const String TXT_N   = "É";
const String TXT_NNE = "ÉÉK";
const String TXT_NE  = "ÉK";
const String TXT_ENE = "KÉK";
const String TXT_E   = "K";
const String TXT_ESE = "KDK";
const String TXT_SE  = "DK";
const String TXT_SSE = "DDK";
const String TXT_S   = "D";
const String TXT_SSW = "DDNY";
const String TXT_SW  = "DNY";
const String TXT_WSW = "NYDNY";
const String TXT_W   = "NY";
const String TXT_WNW = "NYÉNY";
const String TXT_NW  = "ÉNY";
const String TXT_NNW = "ÉÉNY";

// UV
const String TXT_UV_LOW = "(Alacsony)";
const String TXT_UV_MEDIUM = "(Közepes)";
const String TXT_UV_HIGH = "(Magas)";
const String TXT_UV_VERYHIGH = "(Nagyn Magas)";
const String TXT_UV_EXTREME = "(Extrém Magas)";

//Day of the week
const char* weekday_D[] = { "Vasárnap", "Hétfõ", "Kedd", "Szerda", "Csütörtök", "Péntek", "Szombat" };
const char* weekdayShort_D[] = { "Vas", "Hé", "Ke", "Sze", "Csüt", "Pén", "Szo" };
const char* weekdayC_D[] = { "V", "H", "K", "SZ", "CS", "P", "SZ"};

//Month
const char* monthLong_M[] = { "Január", "Február", "Március", "Április", "Május", "Június", "Július", "Augusztus", "Szeptember", "Okttóber", "November", "December" };
const char* monthShort_M[] = { "Jan", "Feb", "Már", "Ápr", "Máj", "Jún", "Júl", "Aug", "Szep", "Okt", "Nov", "Dec" };

