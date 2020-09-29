#include "Flyweight.h"
NetDeviceFactory*  NetDeviceFactory::instance = NULL;
std::mutex NetDeviceFactory::_mutex;