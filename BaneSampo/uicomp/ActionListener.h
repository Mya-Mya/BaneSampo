#pragma once
#include<string>
class ActionListener {
public:
	virtual void actionPerformed(std::string message)=0;
};