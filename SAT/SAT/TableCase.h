#pragma once
#include <map>
#include <string>
#include <vector>

class TableCase
{
private:
	static TableCase* m_instance_;
	TableCase();

	int m_nb_possibility_;
	int m_current_row_;
	std::map<std::string, std::vector<bool>> m_main_table_;

public:
	static TableCase* GetInstance();
	void AddCols(std::string _sValue);
	void NextRow();
	void CreateTable();
	bool GetValue(std::string _sKey);
};