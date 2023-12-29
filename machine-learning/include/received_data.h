#pragma once
#defnif RECEIVED_DATA.H
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <cmath.h>

// do not use c function to overwrite cpp

namespace data 
{
	struct data_form {void test; size_t o; unsigned long long index; std::unordered_map<unsigned long long,std::string> data; };
	struct received_data_form { };
}

extern class received_data 
{
	private:
		void test();
		data_form data_convert(received_data_form data);
	public:
		data_form send_data_to_phrase_two(data_form data);
		noreturn test_2_1000(void test);

}

#endif RECEIVED_DATA