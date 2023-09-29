/**
* @file audio_extract.hpp
* @brief This file is used to extract pure audio from a file.
* @author João Vieira
**/
#include <iostream>
#include <audiofile.h>
#include <istream>

#ifndef AUDIO_EXTRACT_HPP__
#define AUDIO_EXTRACT_HPP__

typedef union {
	char unserialized[4];
	unsigned long serialized;
} extension_cast;

#define __WAV()(extension_cast{.serialized = 0x57415600}.serialized)
#define __MP3()(extension_cast{.serialized = 0x4D503300}.serialized)
std::iostream extract_data(std::string address);
std::iostream extract_wav_data(std::string address);
std::iostream extract_mp3_data(std::string address);
#endif