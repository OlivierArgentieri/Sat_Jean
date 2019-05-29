#include "pch.h"
#include "TableCase.h"
#include <iostream>

TableCase *TableCase::m_instance_ = nullptr;


TableCase::TableCase()
{
	m_nb_possibility_ = 0;
	m_current_row_ = 0;
}

TableCase* TableCase::GetInstance()
{
	if (m_instance_ == nullptr)
	{
		m_instance_ = new TableCase();
	}
	return m_instance_;
}

void TableCase::AddRow(std::string _sValue)
{
	if (m_main_table_.count(_sValue) > 0)
		return;
	m_main_table_.insert(std::pair<std::string, std::vector<bool>>(_sValue, std::vector<bool>()));
}

void TableCase::NextCols()
{
	if (m_current_row_ < m_nb_possibility_)
		m_current_row_++;
}

void TableCase::CreateTable()
{
	m_nb_possibility_ = pow(2, m_main_table_.size());
	
	int bin = 1;
	
	for (auto it = m_main_table_.begin(); it != m_main_table_.end(); ++it)
	{
		for (char test = 0; test < m_nb_possibility_; test++)
		{
			it->second.push_back((test & bin) != 0);
		}
		bin = bin << 1;
	}
}

bool TableCase::GetValue(std::string _sKey)
{
	return m_main_table_[_sKey][m_current_row_];
}

void TableCase::Display()
{
	for (auto it = m_main_table_.begin(); it != m_main_table_.end(); ++it)
	{
		std::cout << it->first << " : ";
		for (bool b : it->second)
		{
			std::cout << b << " ";
		}
		std::cout << std::endl;

	}
}