// C++ includes
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Local includes
#include "../includes/EIP.h"

namespace OmronEipCpp {
	bool EIP::openSocket(std::string ip) {
		return true;
	}
	bool EIP::connected() {
		return true;
	}

	void EIP::registerSession(){
		cmd[0] = (byte)0x65;
		cmd[1] = (byte)0x00;

		cmd[2] = (byte)0x04;
		cmd[3] = (byte)0x00;

		cmd[4] = (byte)0x00;
		cmd[5] = (byte)0x00;
		cmd[6] = (byte)0x00;
		cmd[7] = (byte)0x00;

		cmd[8] = (byte)0x00;
		cmd[9] = (byte)0x00;
		cmd[10] = (byte)0x00;
		cmd[11] = (byte)0x00;

		cmd[12] = (byte)0x00;
		cmd[13] = (byte)0x00;
		cmd[14] = (byte)0x00;
		cmd[15] = (byte)0x00;
		cmd[16] = (byte)0x00;
		cmd[17] = (byte)0x00;
		cmd[18] = (byte)0x00;
		cmd[19] = (byte)0x00;

		cmd[20] = (byte)0x00;
		cmd[21] = (byte)0x00;
		cmd[22] = (byte)0x00;
		cmd[23] = (byte)0x00;

		cmd[24] = (byte)0x01;
		cmd[25] = (byte)0x00;
	
		cmd[26] = (byte)0x00;
		cmd[27] = (byte)0x00;

		/*
		Socket code goes here.

		Set up socket.

		write to socket

		read from socket

		*/

		sessionHandle[0] = res[4];
		sessionHandle[1] = res[5];
		sessionHandle[2] = res[6];
		sessionHandle[3] = res[7];
	}

	void EIP::unregisterSession(){
		cmd[0] = (byte)0x66;
		cmd[1] = (byte)0x00;

		cmd[2] = (byte)0x00;
		cmd[3] = (byte)0x00;

		cmd[4] = sessionHandle[0]; // SESSION HANDLE
		cmd[5] = sessionHandle[1]; //
		cmd[6] = sessionHandle[2]; //
		cmd[7] = sessionHandle[3]; //

		cmd[8] = (byte)0x00;
		cmd[9] = (byte)0x00;
		cmd[10] = (byte)0x00;
		cmd[11] = (byte)0x00;

		cmd[12] = (byte)0x00;
		cmd[13] = (byte)0x00;
		cmd[14] = (byte)0x00;
		cmd[15] = (byte)0x00;
		cmd[16] = (byte)0x00;
		cmd[17] = (byte)0x00;
		cmd[18] = (byte)0x00;
		cmd[19] = (byte)0x00;

		cmd[20] = (byte)0x00;
		cmd[21] = (byte)0x00;
		cmd[22] = (byte)0x00;
		cmd[23] = (byte)0x00;

		/*
		// Create in/out streams
		//Stream stm = EIPSocket.GetStream();

		// Send command
		//stm.Write(Cmd, 0, 28);

		// Receive response
		//stm.Read(Res, 0, 128);

		// Close socket
		//EIPSocket.Close();
		*/
	}
	void EIP::close(){
		// Close socket

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
		return (byte)(myInt & 0xff);
	}

	byte EIP::highByte(int myInt){
		return (byte)((myInt & 0xff) >> 16);
	}

	bool EIP::isArrayMember(const std::string& tagName) {
		return tagName.find('[') != std::string::npos;
	}

	std::string EIP::getTagnameFromMember(const std::string &tagName){
		int end = tagName.find('[');
		if (end != std::string::npos) {
			return tagName.substr(0, end);
		}
		else {
			return tagName;
		}
	}

	std::vector<std::string> EIP::getStructureMembers(const std::string& fullTagName){
		/*
		std::vector<std::string> tagNames;

		int end = 0;
		int index = 0;

		while (end != std::string::npos) {
			end =  fullTagName.find('.', index);
			if (end != std::string::npos) {
				tagNames.push_back(fullTagName.substr(index, fullTagName.length - index +1));
			}
			else{
				tagNames.push_back(fullTagName.substr(index, end - index));
			}
			index = end++;
		}

		*/
		
		std::vector<std::string> tagNames;
		std::istringstream strstream(fullTagName);
		std::string token;

		while (std::getline(strstream, token, '.')) {
			tagNames.push_back(token);
		}
		return tagNames;
	}

	int EIP::getIndexFromArray(const std::string& tagName){
		int start = tagName.find('[') + 1;
		int end = tagName.find(']');

		std::string sNum = tagName.substr(start, end - start);

		// Fix code.. Parse string integers into integers
		return 1;
	}
	
	/*
	std::vector<byte> EIP::buildMessageSection(bool rw, std::string fullTagName, UCCM_Message message){
		std::vector<byte> bArray;
		int tmpLength, charOff;
		std::string tag;

		std::vector<std::string> tagNameList = getStructureMembers(fullTagName);

		if (rw)
		{
			bArray.push_back((byte)0x4C); // Read if true, Service USINT Service code of the request.
		}
		else
		{
			bArray.push_back((byte)0x4D); // Write if false, Service USINT Service code of the request.
		}

		bArray.push_back((byte)0x00); // temp length

		tmpLength = 0;

		foreach(String subTag in tagNameList)
		{
			tag = getTagNameFromMember(subTag);
			bArray.push_back((byte)0x91);
			bArray.push_back((byte)tag.Length);

			for (charOff = 0; charOff < tag.Length; charOff++)
			{
				bArray.push_back((byte)tag[charOff]);
			}
			tmpLength = tmpLength + tag.Length + 2;

			if (tag.Length % 2 != 0)
			{ // padding
				bArray.Add((byte)0x00);
				tmpLength = tmpLength + 1;
			}

			if (isArrayMember(subTag))
			{ // Add Array parameters
				bArray.push_back((byte)0x28);
				bArray.push_back((byte)getIndexFromArray(subTag));
				tmpLength = tmpLength + 2;
			}
		}

		if (!read_write)
		{
			if ((byte)message.dataType != (byte)0xA0)
			{
				bArray.push_back((byte)message.dataType);
				bArray.push_back((byte)0x00);
			}
			else
			{
				bArray.push_back((byte)message.dataType);
				bArray.push_back((byte)0x02);
				bArray.AddRange(BitConverter.GetBytes(message.structCode));
				//                    bArray.Add(lowByte(message.structCode));
				//                    bArray.Add(highByte(message.structCode));
				//                    bArray.Add((byte)0x00);
			}
		}
		bArray.push_back((byte)0x01);
		//            if ((byte)message.dataType != (byte)0xA0)
		//            { 
		bArray.push_back((byte)0x00);
		//            }
		bArray[1] = (byte)(tmpLength / 2);

		if (!read_write)
		{
			bArray.AddRange(message.data);
		}
		return bArray;
	}
	*/

	std::vector<std::string> EIP::convertFromBytes(UCCM_Message& response){
		byte datatype = response.getDatatype();
		std::vector<byte> data = response.getData();
		int datalength = response.getDataSize();

		std::vector<std::string> result;

		switch (datatype) {
		case (byte)0xC3:
			for (std::vector<byte>::const_iterator it = data.begin(); it != data.end(); it += 2) {
				int16_t num = (*it << 8) + *(it + 1);
				result.push_back(std::to_string(num));
			}
		}
	}
	
	bool EIP::isClosed(){
		return true;
	}
}
