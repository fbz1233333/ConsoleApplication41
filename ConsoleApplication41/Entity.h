#pragma once
#include "Model.h"
#include "DataStruct.h"
using namespace datastruct;

class Entity
{
public:
	Model* model;
	_Name modelPath;
	
	Entity(Model* model);
};

