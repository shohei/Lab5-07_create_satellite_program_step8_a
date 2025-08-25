#include "HEPTA_CDH.h"
#include "HEPTA_COM.h"
#include "HEPTA_EPS.h"
#include "HEPTA_SENSOR.h"
#include "mbed.h"
HEPTA_CDH cdh(p5, p6, p7, p8, "sd");
HEPTA_EPS eps(p16, p26);
HEPTA_SENSOR sensor(p17, p28, p27, 0x19, 0x69, 0x13, p13, p14, p25, p24);
HEPTA_COM com(p9, p10, 9600);
DigitalOut condition(LED1);
RawSerial sat(USBTX, USBRX, 9600);
Timer sattime;
int rcmd = 0, cmdflag = 0; // command variable
AnalogIn soil(p18);

int main() {
  sat.printf("From Sat : Nominal Operation\r\n");
  while (1) {
    sat.printf("soil moisture: %3.3f%%\n", soil.read() * 100.0f);
    wait(2.0);
  }
}
