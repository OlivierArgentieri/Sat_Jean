#pragma once
#include <string>

class Parser
{
private:
	std::string m_expression_;
	std::string m_working_string_;

	void RemoveUselessParenthesis();
	bool ContainsUselessParenthesis();
public:



};