#include "pch.h"
#include "TableCase.h"

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

void TableCase::AddCols(std::string _sValue)
{
	if (m_main_table_.count(_sValue) > 0)
		return;
	m_main_table_.insert(std::pair<std::string, std::vector<bool>>(_sValue, std::vector<bool>()));
}

void TableCase::NextRow()
{
	if (m_current_row_ < m_nb_possibility_)
		m_current_row_++;
}

void TableCase::CreateTable()
{
	m_nb_possibility_ = pow(2, m_main_table_.size());
	int j = 1;
	for (auto it = m_main_table_.begin(); it != m_main_table_.end(); ++it)
	{
		for (char test = 0; test < m_nb_possibility_; test++)
		{
			it->second.push_back((test & j) != 0);
		}
		j = j << 1;
	}
}