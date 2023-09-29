#include "audio_extract.hpp"
#include <cstring>

std::iostream extract_data(std::string address){
	//check the extension of the file
	std::string extension = address.substr(address.find_last_of(".") + 1);
	//string to long
	extension_cast ext;
	memcpy(ext.unserialized, extension.c_str(), 4);
	switch(ext.serialized){
		case __WAV():
			return extract_wav_data(address);
		/*case __MP3():
			return extract_mp3_data(address);*/

	}
	
}
std::iostream extract_wav_data(std::string address){
	
	
	
}
std::iostream extract_mp3_data(std::string address){
	
	
}
