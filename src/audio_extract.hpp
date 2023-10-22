/**
* @file audio_extract.hpp
* @brief This file is used to extract pure audio from a file.
* @author João Vieira
**/
#include <iostream>
#include <audiofile.h>
#include <istream>
#include <cstring>
#include <string>
#include <audiofile.h>
#include <cstddef>
#include <cstring>

#ifndef AUDIO_EXTRACT_HPP__
#define AUDIO_EXTRACT_HPP__

 enum extension_cast{
	__wav = 0x766177,
	__WAV = 0x564157,
	__MP3 = 0x4d5033,
	__mp3 = 0x6d7033
};
class audio_ether{
	public:
		audio_ether(std::string address);
		~audio_ether();
		void extract_data();
		void extract_wav_data();
		void extract_mp3_data();
		void amplify_data(std::string _data);
		std::string get_data();
		void data_toWAV(); 
	private:
		std::string address;
		std::string data;
		extension_cast ext;
		int track;
		int frames;
		float frame_size;
		int frames_read;
		int channels;
		int fileHandle;

}; 

#endif