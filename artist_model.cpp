#include <string>
#include <vector>
#include <iostream>

class artist_model 
{
	private :
		
		std::string output_inital_message();
		struct artist_info_structure
		{
			long long artist_PID;
			std::string artist_name;
			std::vector<std::pair<long long,std::string>> album_PID;
		}
		void function_for_testing_GET(struct artist_info_structure info);
		extern artist_info_structure artist_GET();
	public :
		artist_info_structure get_artist_info(struct artist_info_structure info);
		


}


std::string output_inital_message()
{
	std::string str;
	std::cout << "inital_starting..." ;
	sleep(1);
	std::cout << "testing framework started successfully" << str ;
	return str;
}


void functon_for_testing_GET(struct artist_info_structure info)
{
	if (info.artist_PID != NULL) { std::cout << "positive on PID" ; }

	std::string output_inital_message();
}


extern artist_info_structure artist_GET()
{
	struct artist_info_structure info;
	// reply data from outside sources
	// info = artist_controller::get_artist_info::GET();
	return info;
}


artist_info_structure get_artist_info(artist_GET())
{
	return artist_GET();
}






// end of line
