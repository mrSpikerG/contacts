#pragma once
#include<iostream>
#include<exception>
#define СПРАВОЧНИК contacts

class ListException : public std::exception {
private:
	std::string m_error;
public:
	ListException(int code)
	{
		switch (code)
		{
		case 1:
			m_error = "\nError: any elements in list";
			break;
		case 2:
			m_error = "\nError: unexpected id";
			break;
		case 3:
			m_error = "\nFile inputing error";
			break;
		case 4:
			m_error = "\nFile reading error";
			break;
		}
	}
	const char* what() const noexcept override {
		return m_error.c_str();
	}
};
