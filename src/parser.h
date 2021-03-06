//
// Copyright (c) 2011 Ramon E. Torres Salomon
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software
// is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef _YUKA_PARSER_H
#define _YUKA_PARSER_H

#include <string.h>
#include <vector>
#include <stdint.h>

namespace yuka {

	typedef double YukaFloat;
	typedef uint64_t YukaInt;

	enum Token {
		Token_Invalid = 0,
		Token_Add,
		Token_Sub,
		Token_Div,
		Token_Mul,
		Token_Number,
		Token_Pow,
		Token_OpenParentesis,
		Token_CloseParentesis
	};

	enum ValueType {
		ValueType_Invalid = 0,
		ValueType_Integer,
		ValueType_Float
	};

	struct Value {
		ValueType type;
		YukaInt   int_value;
		YukaFloat float_value;
	};

	class TokenObj
	{
	public:
		TokenObj(Token type) {
			m_type = type;
			::memset(&m_value, 0, sizeof(Value));
		}

		ValueType getValueType() {
			return m_value.type;
		}

		void setIntValue(YukaInt value) {
			m_value.type = ValueType_Integer;
			m_value.int_value = value;
		}
		
		YukaInt getIntValue() {
			return m_value.int_value;
		}

		void setFloatValue(YukaFloat value) {
			m_value.type = ValueType_Float;
			m_value.float_value = value;
		}

		YukaFloat getFloatValue() {
			return m_value.float_value;
		}

		void setValue(Value value) {
			m_value = value;
		}

		Value getValue() {
			return m_value;
		}

		Token getType() {
			return m_type;
		}

		bool isOperator() {
			return m_type == Token_Add ||
				m_type == Token_Sub ||
				m_type == Token_Div ||
				m_type == Token_Mul ||
				m_type == Token_Pow;
		}

	protected:
		Token m_type;
		Value m_value;
	};

	typedef std::vector<TokenObj*> TokenObjVector;
	typedef std::vector<TokenObj*>::iterator TokenObjVectorIterator;

	class Parser
	{
	public:
		Parser();
		virtual ~Parser();

		TokenObjVector parse(const char *data, size_t len);
	private:
	/* data */
	};
};

#endif //_YUKA_PARSER_H
