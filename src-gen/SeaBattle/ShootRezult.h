/*
 * Autogenerated by ThriftMeGenerator (v2.13.4.0)
 * 
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING!
 * 
 * Copyright 2020 Daimler AG
 * All Rights Reserved.
 * NOTICE:  All added/modified information contained herein is and remains the proprietary of Daimler AG.
 * The intellectual and technical concepts contained herein are proprietary to Daimler AG and may be covered by German and Foreign Patents, patent applications, and are protected by trade secret or copyright law.
 */

#ifndef _SEABATTLE_SHOOTREZULT_
#define _SEABATTLE_SHOOTREZULT_

#include <platform/Platform.h>

namespace SeaBattle
{
	struct ShootRezult
	{
		enum type
		{
			Miss = 0,
			Hit = 1,
			Kill = 2
		};
		static const char* GetName(int32_t, const char *result = nullptr);
	};

	extern const std::map<int32_t, const char*> _ShootRezult_VALUES_TO_NAMES;
}

_THRIFT_BEGIN_HASH_NAMESPACE
template <>
_THRIFT_HASHCLASS_TYPE hash< ::SeaBattle::ShootRezult::type >
{
public:
	size_t operator()(const ::SeaBattle::ShootRezult::type& value) const
	{
		return ::thrift::hash<int32_t >()((int32_t)value);
	}
};
_THRIFT_END_HASH_NAMESPACE

#endif // _SEABATTLE_SHOOTREZULT_

