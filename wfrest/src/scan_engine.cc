#include <dnet.h>
#include <string>
/* basic funtion  :
 scan for aviliable open port
*/

extern bool scan_with_sF(std::vector<int> command_code)
{
	bool modified_await = true;
	// put function here detect if using -sF or not
	return modified_await;
}

extern void log_write(std::string output)
{
	if (scan_with_sF)
		std::cout << output << std::endl;
  
}

