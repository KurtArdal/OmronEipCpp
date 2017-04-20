// C++ includes
#include <string>

// Local includes
#include "../includes/PLCData.h"
namespace OmronEipCpp{
	PLCData::PLCData(const std::string &name, const std::string &protocol, const std::string &ip, const std::string &port, const std::string &SNA, const std::string &DNA, const std::string &DA1){
		this->_name = name;
		this->_protocol = protocol;
		this->_ipaddress = ip;
		this->_port = port;
		this->_SNA = SNA;
		this->_DNA = DNA;
		this->_DA1 = DA1;
	}

	std::string PLCData::getName() {
		return this->_name;
	}

	std::string PLCData::getProtocol() {
		return this->_protocol;
	}

	std::string PLCData::getIP() {
		return this->_ipaddress;
	}

	std::string PLCData::getPort() {
		return this->_port;
	}

	std::string PLCData::getSNA() {
		return this->_SNA;
	}

	std::string PLCData::getDNA() {
		return this->_DNA;
	}

	std::string PLCData::getDA1() {
		return this->_DA1;
	}

}
