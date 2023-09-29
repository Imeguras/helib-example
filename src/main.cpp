
#include <string>
#include <iostream>

#include <boost/program_options.hpp>

#include "audio_extract.hpp"

namespace po = boost::program_options;

int main(int argc, char **argv){
	po::options_description desc("Correct Usage: ./helib-example [options]");
    desc.add_options()
	("help", "produce help message")
    ("file", po::value<std::string>(), "file address")
	;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);    

	if (vm.count("help")) {
		std::cout << desc << "\n";
		return 1;
	}else{
		if (vm.count("file")) {
			extract_data(vm["file"].as<std::string>());
		} else {
			std::cout << "File address was not set.\n";
		}
	}




	

	
	return 0;
}