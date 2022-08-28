#include <iostream>
#include <sstream>
#include <cstdint>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
	uint64_t num;

	istringstream iss(argv[1]);
	iss >> num;

	if (argc != 2)
	{
		cout << "Please specify discord time as the first arg!" << endl;
		return (2);
	}

	if (num==0)
	{
		cout << "Please specify discord time as a numerical snowflake!" << endl;
		return (2);
	}

	num = num >> 22;
	num += 1420070400000;
	num /= 1000;

	cout << "Unix time: " << num << endl;

	time_t epch = num;

	cout << "Human time  (GMT) : " << asctime(gmtime(&epch));
	cout << "Human time (Local): " << asctime(localtime(&epch));

	return (0);
}

