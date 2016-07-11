#pragma once

#include <iostream>

class Singleton
{
public:
	static Singleton& instance();
public:
	int a;
private:
	Singleton()
	{}
private:
	static Singleton _instance;
};