#include <Arduino.h>
#include <string>
#include <vector>
// Change to your WiFi credentials
const char* ssid     = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

// Use your own API key by signing up for a free developer account at https://openweathermap.org/
String apikey       = "OWM_API_KEY";
const char server[] = "api.openweathermap.org";
//http://api.openweathermap.org/data/2.5/forecast?q=Melksham,UK&APPID=your_OWM_API_key&mode=json&units=metric&cnt=40
//http://api.openweathermap.org/data/2.5/weather?q=Melksham,UK&APPID=your_OWM_API_key&mode=json&units=metric&cnt=1


struct location {
    String City;
    float Latitude;
    float Longitude;
    int cityID;
};

//Set your location according to OWM locations
std::vector<location> cityList = {
    /*Name, lat, lon, id : cityID from City: https://api.openweathermap.org/data/2.5/weather?q=Kisk%C5%91r%C3%B6s&appid=your_OWM_API_key*/
    {"Budapest", 47.550432, 19.125167, 3054643},
    {"Szeged", 46.2530, 20.1482, 715429},
    {"Debrecen", 47.5316, 21.6273, 721472},
    {"Kiskõrös", 46.6214, 19.2852, 3049896},
    {"Gyõr", 47.6875, 17.6504, 3052009},
    {"Zalaegerszeg", 46.8400, 16.8439, 3042638},
    {"Pécs", 46.0727, 18.2323, 3046526},
    {"Miskolc", 48.1000, 20.7833, 717582}
};

String Language         = "hu";                            // NOTE: Only the weather description is translated by OWM
                                                           // Examples: German (DE) Arabic (AR) Czech (CZ) English (EN) Greek (EL) Persian(Farsi) (FA) Galician (GL) Hungarian (HU) Japanese (JA)
                                                           // Korean (KR) Latvian (LA) Lithuanian (LT) Macedonian (MK) Slovak (SK) Slovenian (SL) Vietnamese (VI)
String Hemisphere       = "north";                         // or "south"  
String Units            = "M";                             // Use "M" for Metric or "I" for Imperial 
const char* Timezone    = "CET-1CEST,M3.5.0,M10.5.0/3";    // Choose your time zone from: https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv 
                                                           // See below for examples
const char* ntpServer   = "0.europe.pool.ntp.org";         // Or, choose a time server close to you, but in most cases it's best to use pool.ntp.org to find an NTP server
                                                           // then the NTP system decides e.g. 0.pool.ntp.org, 1.pool.ntp.org as the NTP syem tries to find  the closest available servers
                                                           // EU "0.europe.pool.ntp.org"
                                                           // US "0.north-america.pool.ntp.org"
                                                           // See: https://www.ntppool.org/en/                                                           
int  gmtOffset_sec      = 3600;                            // UK normal time is GMT, so GMT Offset is 0, for US (-5Hrs) is typically -18000, AU is typically (+8hrs) 28800
int  daylightOffset_sec = 3600;                            // In the UK DST is +1hr or 3600-secs, other countries may use 2hrs 7200 or 30-mins 1800 or 5.5hrs 19800 Ahead of GMT use + offset behind - offset

// Example time zones
//const char* Timezone = "MET-1METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "CET-1CEST,M3.5.0,M10.5.0/3";       // Central Europe
//const char* Timezone = "EST-2METDST,M3.5.0/01,M10.5.0/02"; // Most of Europe
//const char* Timezone = "EST5EDT,M3.2.0,M11.1.0";           // EST USA  
//const char* Timezone = "CST6CDT,M3.2.0,M11.1.0";           // CST USA
//const char* Timezone = "MST7MDT,M4.1.0,M10.5.0";           // MST USA
//const char* Timezone = "NZST-12NZDT,M9.5.0,M4.1.0/3";      // Auckland
//const char* Timezone = "EET-2EEST,M3.5.5/0,M10.5.5/0";     // Asia
//const char* Timezone = "ACST-9:30ACDT,M10.1.0,M4.1.0/3":   // Australia

// Select language to use or add your own translation
//#include "lang.h"
//#include "lang_fr.h"
//#include "lang_de.h"
#include "lang_hu.h"

// Params needed to fetch events from Google Calendar
char const * const calendarHost = "script.google.com";
char const * const calendarPath = "/macros/s/Your_KEY/exec"; // script path including key
int const calendarPort = 443;
