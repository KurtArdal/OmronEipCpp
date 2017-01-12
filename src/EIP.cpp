// C++ includes
#include <string>

// Local includes
#include "EIP.h"

namespace OmronEipCpp {
	bool EIP::openSocket(std::string ip) {
		return true;
	}
	bool EIP::connected() {
		return true;
	}

	void EIP::registerSession(){

	}
	void EIP::unregisterSession(){

	}
	void EIP::close(){

	}
	/*
	UCCM_Message EIP::readTagUCCM(std::string fullTagName) {
		UCCM_Message message = new UCCM_Message(0, new std::vector<byte>());
		return message;
	}

	UCCM_Message EIP::writeTagUCCM(std::string fullTagName, UCCM_Message data){
		UCCM_Message message = new UCCM_Message(0, new std::vector<byte>());
		return message;
	}
	*/
	byte EIP::lowByte(int myInt){
		return myInt;
	}
	byte EIP::highByte(int myInt){
		return myInt;
	}

	bool EIP::isArrayMember(std::string tagName) {
		return true;
	}
	std::string EIP::getTagnameFromMember(std::string &tagName){
		return tagName;
	}

	//std::vector<std::string> EIP::getStructureMembers(std::string fullTagName){
		
//	}
	int EIP::getIndexFromArray(std::string tagName){
		return 1;
	}
	/*
	std::vector<byte> EIP::buildMessageSection(bool rw, std::string fullTagName, UCCM_Message message){
		
	}
	std::vector<std::string> EIP::convertFromBytes(UCCM_Message repsonse){

	}
	*/
	bool EIP::isClosed(){
		return true;
	}
}