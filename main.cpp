#include <fstream>
#include <iostream>
#include "proto/Sensor.pb.h"

int main(int argc, char const *argv[])
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  Sensor sensor;
  sensor.set_name("Laboratory");
  sensor.set_temperature(23.4);
  sensor.set_humidity(68);
  sensor.set_door(Sensor_SwitchLevel_OPEN);  
  std::cout << "Hello Proto!" << std::endl;
  std::ofstream output_data("sensor.data", std::ios::out | std::ios::trunc | std::ios::binary);
  sensor.SerializeToOstream(&output_data); 
  output_data.close();
  Sensor sensorR;
  std::ifstream input_data("sensor.data", std::ios::in | std::ifstream::binary);
  std::cout << bool(input_data) << std::endl;  
  sensorR.ParseFromIstream(&input_data);
  std::cout << sensorR.name() << std::endl;
  std::cout << sensorR.temperature() << std::endl;
  std::cout << sensorR.humidity() << std::endl;
  std::cout << sensorR.door() << std::endl;
  input_data.close();
  return 0;
}
