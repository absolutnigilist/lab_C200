#include "MyData.h"

MyData::MyData() :sex(UNDEF), m_age(0), m_job(), m_salary(0.) {};

MyData::MyData(Sex s, size_t age, const char* job, float sal) :sex(s), m_age(age), m_job(job), m_salary(sal) {};

//MyData::~MyData() {};
//
//MyData::MyData(const MyData& other) :sex(other.sex), m_age(other.m_age), m_job(other.m_job), m_salary(other.m_salary) {};
//
//MyData::MyData(MyData&& other) :sex(other.sex), m_age(other.m_age), m_job(std::move(other.m_job)), m_salary(other.m_salary) {
//	other.sex = UNDEF;
//	other.m_age = 0;
//	other.m_salary = 0.;
//};
//MyData& MyData::operator=(const MyData& other) {
//	if (this != &other)
//	{
//		sex = other.sex;
//		m_age = other.m_age;
//		m_job = other.m_job;
//		m_salary = other.m_salary;
//	}
//	return *this;
//};
//
//MyData& MyData::operator=(MyData&& other) {
//	if (this != &other)
//	{
//		sex = other.sex;
//		m_age = other.m_age;
//		m_job = std::move(other.m_job);
//		m_salary = other.m_salary;
//
//		other.sex = UNDEF;
//		other.m_age = 0;
//		other.m_salary = 0.;
//	}
//	return *this;
//};

std::ostream& operator<<(std::ostream& os, const MyData& other) {
	os << "Sex: " << (other.sex == MyData::MALE ? "MALE" : (other.sex == MyData::FEMALE ? "FEMALE" : "UNDEF")) << " " << "Age: " << other.m_age << " " << "Job_title: " << other.m_job << " " << "Salary: " << other.m_salary << std::endl;
	return os;
};
