#ifndef FORECAST_RECORD_H_
#define FORECAST_RECORD_H_

#include <Arduino.h>

typedef struct { // For current Day and Day 1, 2, 3, etc
  int    Dt;
  String Icon;
  String Trend;
  String Forecast0;
  String Description;
  float  Temperature;
  float  FeelsLike;
  float  Humidity;
  float  High;
  float  Low;
  float  Winddir;
  float  Windspeed;
  float  Rainfall;
  float  Snowfall;
  float  Pressure;
  int    Cloudcover;
  int    Visibility;
  int    Sunrise;
  int    Sunset;
  int    FTimezone;  
} Forecast_record_type;

typedef struct {
  /* data */
  String Icon;
  float  High;
  float  Low;
  int x;
  int y;
  String city;
} Map_record_type;

struct EventData{
    String startTime;
    String endTime;
    String title;
    String description;
    bool allDay;
    String status;
    String alert;
    uint8_t month;
    uint8_t day;
    uint8_t weekday;
  };


#endif /* ifndef FORECAST_RECORD_H_ */
