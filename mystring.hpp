#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>

using namespace std;

namespace my {

	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		// Ĭ�ϳ�Ա����
		string();
		string(const char* str = "");			// ���캯��
		string(const string& s);				// �������캯��
		string& operator=(const string& s);		// �������������
		~string();

		// ��������غ���
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		// �����ʹ�С��غ���
		size_t size() const;
		size_t capacity() const;
		void reserve(size_t n);
		void resize(size_t n, char ch = '\0');
		bool empty() const;

		// �޸��ַ���غ���
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);
		string& insert(size_t pos, char ch);
		string& insert(size_t pos, const char* str);
		string& erase(size_t pos, size_t len);
		void clear();
		void swap(string& s);
		const char* c_str() const;

		// �����ַ�����غ���
		char& operator[](size_t i);
		const char& operator[](size_t i) const;
		size_t find(char ch, size_t pos = 0) const;
		size_t find(const char* str, size_t pos = 0) const;
		size_t rfind(char ch, size_t pos = npos) const;
		size_t rfind(const char* str, size_t pos = 0) const;

		// ��ϵ��������غ���
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

	private:
		char* _str;			// �洢�ַ���ָ��
		size_t _size;		// ��¼�ַ�����ǰ����Ч����
		size_t _capacity;	// ��¼�ַ�����ǰ������
		static const size_t npos = -1;	// ��̬��Ա���� 
	};

	// io�����������
	istream& operator>>(istream& in, string& s);
	ostream& operator<<(ostream& out, string& s);
	istream& getline(istream& in, string& s);

	// ���캯��
	string::string() {
		this->_str = nullptr;
		this->_size = 0;
		this->_capacity = 0;
	}

	string::string(const char* str)
	{
		this->_size = strlen(str);
		this->_capacity = this->_size;
		this->_str = new char[this->_capacity + 1];
		strcpy(this->_str, str);
	}

	// �������캯��(���)
	string::string(const string& s)
		:_str(new char[strlen(s._str) + 1]), _size(0), _capacity(0)
	{
		strcpy(this->_str, s._str);
		this->_size = s._size;
		this->_capacity = s._capacity;
	}

	// ��ֵ��������غ���
	string& string::operator=(const string& s) {

		if (this != &s) {		// ��ֹ�Լ����Լ���ֵ
			delete[] this->_str;
			this->_str = new char[strlen(s._str) + 1];
			strcpy(this->_str, s._str);
			this->_size = s._size;
			this->_capacity = s._capacity;
		}
		return *this;
	}

	// ��������
	string::~string() {
		delete[] this->_str;
		this->_str = nullptr;
		this->_size = 0;
		this->_capacity = 0;
	}

	// ��������غ���
	string::iterator string::begin() {
		return this->_str;
	}

	string::iterator string::end() {
		return this->_str + this->_size;
	}

	string::const_iterator string::begin() const
	{
		return this->_str;
	}

	string::const_iterator string::end() const
	{
		return this->_str + this->_size;
	}

	// �����ʹ�С��غ���
	size_t string::size() const
	{

		return this->_size;	// �����ַ�����ǰ����Ч����
	}

	size_t string::capacity() const
	{
		return this->_capacity;	// �����ַ�����ǰ������
	}

	// �����ַ���������С
	void string::reserve(size_t n) {
		if (n > this->_capacity) {
			char* temp = new char[n + 1];
			strncpy(temp, this->_str, this->_size + 1);
			delete[] this->_str;
			this->_str = temp;
			this->_capacity = n;
		}
	}

	// �ı��ַ�����С
	void string::resize(size_t n, char ch)
	{
		if (n <= this->_size) {
			this->_size = n;
			this->_str[_size] = '\0';
		}
		else {
			if (n > this->_capacity) {
				this->reserve(n);
			}
			for (size_t i = _size; i < n; ++i) {
				this->_str[i] = ch;
			}
			this->_size = n;			// size����
			this->_str[_size] = '\0';	// �ַ��������Ϸ���'\0'
		}
	}

	// �ַ����п�
	bool string::empty() const {
		return strcmp(this->_str, "") == 0;
	}

	// β���ַ�
	void string::push_back(char ch) {

		if (this->_size == this->_capacity) {
			this->reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		this->_str[_size] = ch;
		this->_str[_size + 1] = '\0';
		++this->_size;
	}

	// β���ַ���
	void string::append(const char* str)
	{
		size_t len = this->_size + strlen(str);
		if (len > this->_capacity) {
			this->reserve(len);
		}
		strcpy(this->_str + this->_size, str);
		this->_size = len;
	}

	// operator+= ����
	string& string::operator+=(char ch) {
		this->push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str) {
		this->append(str);
		return *this;
	}

	// insert ����
	string& string::insert(size_t pos, char ch) {

		assert(pos <= this->_size);	// ����±�ĺϷ���
		if (this->_size == this->_capacity) {
			this->reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		char* end = this->_str + _size;
		while (end >= _str + pos) {
			*(end + 1) = *end;
			--end;
		}

		this->_str[pos] = ch;
		++this->_size;
		return *this;
	}

	string& string::insert(size_t pos, const char* str)
	{
		assert(pos <= this->_size);
		size_t len = strlen(str);
		if (len + this->_size > this->_capacity) {
			reserve(len + this->_size);
		}

		char* end = _str + _size;
		while (end >= _str + pos)
		{
			*(end + len) = *end;
			end--;
		}

		strncpy(_str + pos, str, len);
		_size += len;

		return *this;

	}

	// erase ����
	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < this->_size);
		size_t n = _size - pos;

		if (len >= n) {
			this->_size = pos;
			this->_str[_size] = '\0';
		}
		else {
			strcpy(_str + pos, _str + pos + len);
			_size -= len;
		}

		return *this;
	}

	void string::clear() {
		this->_size = 0;
		_str[_size] = '\0';
	}


	// �����������������
	void string::swap(string& s) {

		std::swap(this->_str, s._str);
		std::swap(this->_size, s._size);
		std::swap(this->_capacity, s._capacity);
	}

	// ����C���͵��ַ���
	const char* string::c_str() const {
		return this->_str;
	}


	// �����ַ�����غ���
	char& string::operator[](size_t i) {
		assert(i < this->_size);
		return this->_str[i];
	}


	const char& string::operator[](size_t i) const {
		assert(i < this->_size);
		return this->_str[i];
	}

	// ������ҵ�һ��ƥ����ַ�
	size_t string::find(char ch, size_t pos) const {
		assert(pos < this->_size);
		for (size_t i = 0; i < this->_size; ++i) {
			if (this->_str[i] == ch) return i;

		}

		return npos;
	}


	// ������ҵ�һ��ƥ����ַ���
	size_t string::find(const char* str, size_t pos) const {

		assert(pos < this->_size);
		const char* ret = strstr(this->_str + pos, str);

		if (ret)	return ret - this->_str;
		else return npos;

	}


	size_t string::rfind(char ch, size_t pos) const {

		string temp(*this);
		std::reverse(temp.begin(), temp.end());
		if (pos >= this->_size) pos = _size - 1;

		pos = _size - 1 - pos;
		size_t ret = temp.find(ch, pos);

		if (ret != string::npos) {
			return this->_size - 1 - ret;
		}
		else {
			return string::npos;
		}
	}

	size_t string::rfind(const char* str, size_t pos) const {
		string temp(*this);
		std::reverse(temp.begin(), temp.end());
		size_t len = strlen(str);
		char* arr = new char[len + 1];
		strcpy(arr, str); \
			size_t left = 0, right = len - 1;

		while (left < right) {

			std::swap(arr[left], arr[right]);
			++left;
			--right;
		}

		if (pos >= _size) {
			pos = _size - 1;
		}
		pos = _size - 1 - pos;

		size_t ret = temp.find(arr, pos);
		delete[] arr;
		if (ret != npos) return _size - ret - len;
		else return npos;
	}

	bool string::operator>(const string& s)const
	{
		return strcmp(_str, s._str) > 0;
	}

	bool string::operator==(const string& s)const
	{
		return strcmp(_str, s._str) == 0;
	}

	bool string::operator>=(const string& s)const
	{
		return (*this > s) || (*this == s);
	}

	bool string::operator<(const string& s)const
	{
		return !(*this >= s);
	}

	bool string::operator<=(const string& s)const
	{
		return !(*this > s);
	}

	bool string::operator!=(const string& s)const
	{
		return !(*this == s);
	}

	// >> ���������
	istream& operator>>(istream& in, string& s) {

		s.clear();
		char ch = in.get();
		while (ch != ' ' && ch != '\n') {
			s += ch;
			ch = in.get();
		}

		return in;
	}

	ostream& operator<<(ostream& out, const string& s) {

		for (auto c : s) {
			out << c;
		}
		return out;
	}


	istream& getline(istream& in, string& s) {

		s.clear();
		char ch = in.get();
		while (ch != '\n') {
			s += ch;
			ch = in.get();
		}

		return in;
	}
}