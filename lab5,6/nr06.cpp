#include <iostream>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

struct case_insensitive_cmp
{
	bool operator()(const std::string &lhs, const std::string &rhs) const
	{
		auto lsize = lhs.size();
		auto rsize = rhs.size();
		auto minSize = (lsize < rsize) ? lsize : rsize;

		for (auto i = 0; i < minSize; ++i)
			if (std::tolower(lhs[i]) != std::tolower(rhs[i]))
				return std::tolower(lhs[i]) < std::tolower(rhs[i]);

		return lsize < rsize;
	}
};

struct case_insensitive_hash
{
	size_t operator()(const std::string &s) const
	{
		std::string str{s};
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::hash<std::string> hashFunction;
		return hashFunction(str);
	}
};

struct case_insensitive_equality
{
	bool operator()(const std::string &s1, const std::string &s2) const
	{
		auto size1 = s1.size();
		auto size2 = s2.size();
		auto minSize = (size1 < size2) ? size1 : size2;

		for (size_t i = 0; i < minSize; ++i)
		{
			if (tolower(s1[i]) != tolower(s2[i]))
				return false;
		}
		if (size1 != size2)
			return false;
		return true;
	}
};

std::map<std::string, unsigned int, case_insensitive_cmp> frequencytable(const std::vector<std::string> &text)
{
	std::map<std::string, unsigned int, case_insensitive_cmp> freq{};
	for (const auto &str : text)
	{
		freq[str]++;
	}
	return freq;
}

std::pair<std::string, unsigned int> themostfrequent(const std::map<std::string, unsigned int, case_insensitive_cmp> frequencyMap)
{
	unsigned int maxFreq = 0;
	std::string result;
	for (const auto &str : frequencyMap)
	{
		if (str.second > maxFreq)
		{
			maxFreq = str.second;
			result = str.first;
		}
	}
	return std::pair<std::string, unsigned int>(result, maxFreq);
}

std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> hashed_frequencytable(const std::vector<std::string> &text)
{
	std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> freq{};
	for (const auto &str : text)
	{
		freq[str]++;
	}
	return freq;
}

std::ostream &operator<<(std::ostream &out, const std::map<std::string, unsigned int, case_insensitive_cmp> &freq)
{
	out << "{";
	for (auto &pair : freq)
	{
		out << "{" << pair.first << ", " << pair.second << "}";
	}
	return out << "}";
}

std::ostream &operator<<(std::ostream &out, const std::pair<std::string, unsigned int> &freq)
{
	return out << "the most frequent -> " << freq.first << " : " << freq.second;
}

std::ostream &operator<<(std::ostream &out, const std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> &freq)
{
	out << "{";
	for (auto &pair : freq)
	{
		out << "{" << pair.first << ", " << pair.second << "}";
	}
	return out << "}";
}

int main(int argc, char *argv[])
{

	std::cout << frequencytable(std::vector<std::string>{"AA", "aA", "Aa", "this", "THIS", "m", "b"}) << "\n";
	std::cout << hashed_frequencytable(std::vector<std::string>{"AA", "aA", "Aa", "this", "THIS", "m", "b"}) << "\n";

	case_insensitive_hash h;
	std::cout << h("xxx") << " " << h("XXX") << "\n";
	std::cout << h("Abc") << " " << h("abC") << "\n";

	case_insensitive_equality e;
	std::cout << e("xxx", "XXX") << "\n";

	std::vector<std::string> textVector;
	std::ifstream input("text.txt");
	textVector = vectortest::readfile(input);
	std::map<std::string, unsigned int, case_insensitive_cmp> frequencyMap = frequencytable(textVector);

	std::cout << "magnus : " << frequencyMap["magnus"] << "\n";
	std::cout << "hominum : " << frequencyMap["hominum"] << "\n";
	std::cout << "memoria : " << frequencyMap["memoria"] << "\n";
	std::cout << themostfrequent(frequencyMap);
	return 0;
}

// std::cout << "Testing readfile\n";
// readfileTest();
// std::cout << "\n------------------------------------------------------\n";
// std::cout << "Testing Print\n\n";
// printTest();

// std::cout << "\n------------------------------------------------------\n";
// std::cout << "Testing vectorToList\n\n";
// vectorToListTest();

// std::cout << "\n------------------------------------------------------\n";
// std::cout << "Testing Sortings for vector and list\n";
// sortingAlgsTest();

// void readfileTest()
// {
// 	std::ifstream inp{"test.txt"};
// 	auto vectFromInput = vectortest::readfile(inp);
// 	std::cout << "Unsorted:\n"
// 			  << vectFromInput;
// 	vectortest::sort_std(vectFromInput);
// 	std::cout << "Sorted:\n"
// 			  << vectFromInput;
// 	inp.close();
// }

/*void printTest()
{
	std::cout << "For the vector:\n";
	for (int i; i <= 5; i++)
	{
		std::vector<std::string> vect;
		vect = vectortest::randomstrings(i, 8);
		std::cout << "Vector Length = " << i << ": " << vect << "\n";
	}

	std::cout << "For the list:\n";
	for (int j; j <= 5; j++)
	{
		std::list<std::string> li;
		li = listtest::randomstrings(j, 8);
		std::cout << "List Length = " << j << ": " << li << "\n";
	}
}

void listSortMove(int nr, int s)
{
	std::list<std::string> lstr;
	lstr = listtest::randomstrings(nr, s);
	listtest::sort_move(lstr);
}

void listSortAssign(int nr, int s)
{
	std::list<std::string> lstr;
	lstr = listtest::randomstrings(nr, s);
	listtest::sort_assign(lstr);
}

void vectorSortMove(int nr, int s)
{
	std::vector<std::string> vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_move(vect);
}

void vectorSortAssign(int nr, int s)
{
	std::vector<std::string> vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_assign(vect);
}

void vectorQuicksort(int nr, int s)
{
	std::vector<std::string> vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_std(vect);
}

std::list<std::string> vectorToList(std::vector<std::string> vect)
{
	std::list<std::string> lstr;
	for (std::vector<std::string>::const_iterator
			 p = vect.begin();
		 p != vect.end();
		 ++p)
	{
		lstr.push_back(*p);
	}
	return lstr;
}

void sortingAlgsTest()
{
	for (int nr = 5000; nr <= 25000; nr += 5000)
	{
		std::cout << "\n-------------for nr = " << nr << "------------\n";
		vectorSortMove(nr, 50);
		vectorSortAssign(nr, 50);
		vectorQuicksort(nr, 50);
		listSortMove(nr, 50);
		listSortAssign(nr, 50);
	}
}

void vectorToListTest()
{
	std::vector<std::string> vect;
	vect = vectortest::randomstrings(20, 10);
	std::cout << "Unsorted Vector:\n"
			  << vect << "\n";

	std::list<std::string> li;
	li = vectorToList(vect);
	std::cout << "Copied Unsorted List:\n"
			  << li << "\n";

	vectortest::sort_move(vect);
	std::cout << "Sorted Vector:\n"
			  << vect << "\n";

	listtest::sort_move(li);
	std::cout << "Sorted List:\n"
			  << li;
}*/