#include <stdio.h>
#include <stdlib.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY = "a83e02be327a2c17de16a8e512e2d3cb";
const char *device_id = "15c7358a0e274122feffa80d797cb442";

char timestamp[512];
char temperature[512];
char data[2048];

void setTimestamp() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
    
  sprintf(timestamp, "%d-%02d-%02dT%02d:%02d:%02dZ", 
    tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
    tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void setTemperature() {
  srand(time(NULL));
  int temp = (rand() % 70) + 50;
  
  sprintf(temperature, "%d", temp);
}

void setData() {
  sprintf(data, "{ \"timestamp\": \"%s\", \"value\": %s }", timestamp, temperature);
}

int main() {
  m2x_context *ctx = NULL;
  m2x_response response;
  
  setTimestamp();
  setTemperature();  
  setData();
  
  printf("Updating temperature of value: %s , timestamp: %s ...\n", temperature, timestamp);
  
  ctx = m2x_open(M2X_KEY);
  
  response = m2x_device_stream_value_update(ctx, device_id, "temperature", data);
  
  printf("Status code: %d\n", response.status);

  m2x_release_response(&response);
  m2x_close(ctx);
  
  return 0;
}
