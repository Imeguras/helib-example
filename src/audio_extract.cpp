#include "audio_extract.hpp"
#include <audiofile.h>



audio_ether::audio_ether(std::string address){
	this->data = "";
	this->address = address;
}

void audio_ether::extract_data(){
	//check the extension of the file
	std::string extension = address.substr(address.find_last_of(".") + 1);
	std::cout << extension << "\n";
	//string to long
	uint64_t ext = 0;
	
	memmove(&ext, extension.c_str(), 4);
	switch(ext){
		case extension_cast::__wav:
		case extension_cast::__WAV:
			extract_wav_data();
			break; 
		default:
			std::cout << ext << "\n";
			std::cout << "File extension not supported.\n";
			break;
		/*case __MP3():
			return extract_mp3_data(address);*/

	}
	
}
void audio_ether::extract_wav_data(){
	auto fileHandle = afOpenFile(address.c_str(), "r", NULL);
	
	frames = afGetFrameCount(fileHandle, AF_DEFAULT_TRACK);
	frame_size = 4; //afGetFrameSize(fileHandle, AF_DEFAULT_TRACK,0);
	channels = afGetChannels(fileHandle, AF_DEFAULT_TRACK);

	char *data = new char[(int)(frames*frame_size)];
	auto frames_read = afReadFrames(fileHandle, AF_DEFAULT_TRACK, data, frames);
	this->data = std::string(data, (int)frames*frame_size);

	
	afCloseFile(fileHandle);
	
}
void audio_ether::extract_mp3_data(){
	
	
}
void audio_ether::amplify_data(std::string _data){
	/*foreach 4 bytes multiply it by 2 */
	char * buffer;
	buffer = (char*)malloc(_data.size());
	if(buffer == NULL){
		std::cout << "Error allocating memory.\n";
		return;
	}
	memcpy(buffer, _data.c_str(), _data.size());
	for(int i = 0; i < data.size(); i+=4){
		float temp = 0;
		memmove(&temp, buffer+i, 4);
		temp = temp*2;
		
		memmove(buffer+i, &temp, 4);
	}
	this->data = std::string(buffer, _data.size());

}
void audio_ether::data_toWAV(){
	AFfilesetup		outfilesetup = afNewFileSetup();
	AFfilehandle	outfile;

	//auto frameCount = afGetFrameCount(infile, AF_DEFAULT_TRACK);
	//auto channelCount = afGetChannels(infile, AF_DEFAULT_TRACK);

	afInitFileFormat(outfilesetup, AF_FILE_WAVE);
	afInitByteOrder(outfilesetup, AF_DEFAULT_TRACK, AF_BYTEORDER_LITTLEENDIAN);
	afInitChannels(outfilesetup,AF_DEFAULT_TRACK, channels);
	afInitRate(outfilesetup, AF_DEFAULT_TRACK, 44100.0);
	afInitSampleFormat(outfilesetup, AF_DEFAULT_TRACK, AF_SAMPFMT_FLOAT, 4);

	outfile = afOpenFile("finish.wav", "w", outfilesetup);

	std::cout << "Writing to file...\n";

	auto k = afWriteFrames(outfile, AF_DEFAULT_TRACK, data.c_str(), frames);
	std::cout << k << "\n";
	afCloseFile(outfile);

}
std::string audio_ether::get_data(){
	return this->data;
}
audio_ether::~audio_ether(){
	
}