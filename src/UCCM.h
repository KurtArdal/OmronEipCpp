#pragma once
#ifndef UCCM_H
#define UCCM_H

// C++ includes
#include <vector>

// Local includes
#include "Types.h"

namespace OmronEipCpp {
	class UCCM_Message {
	public:
		UCCM_Message(byte datatype, std::vector<byte> data, short sc = 0) {
			this->_datatype = datatype;
			this->_structCode = sc;
			this->_data = data;
		}

		byte getDatatype() {
			return this->_datatype;
		}
		void setDatatype(byte datatype) {
			this->_datatype = datatype;
		}

		short getStructcode() {
			return this->_structCode;
		}
		void setStructcode(short sc) {
			this->_structCode = sc;
		}

		std::vector<byte> getData() {
			return this->_data;
		}
		void setData(std::vector<byte> data) {
			this->_data = data;
		}

	private:
		byte _datatype;
		short _structCode;
		std::vector<byte> _data;
	};
}
#endif // UCCM_H