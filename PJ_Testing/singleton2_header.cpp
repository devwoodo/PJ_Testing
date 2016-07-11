#include "singleton2_header.h"

Singleton Singleton::_instance;

Singleton& Singleton::instance()
{
	//static Singleton _instance;
	return _instance;
}