/*
 * default_definitions.h
 *
 * Created: 26.12.2019 17:45:57
 *  Author: Rayfat
 */ 


#ifndef DEFINITIONS_TYPE_HPP
#define DEFINITIONS_TYPE_HPP
namespace mbl // namespace meta bit library
{
	typedef volatile unsigned char* uint8ptr_t;
	typedef volatile unsigned char  reg8_t;
	typedef volatile unsigned int*  uint16ptr_t;
	typedef volatile unsigned int   reg16_t;

	typedef unsigned char			uint8_t;
	typedef unsigned int			uint16_t;
	typedef unsigned long int		uint32_t;
	typedef unsigned long long int	uint64_t;
	typedef char					int8_st;
	typedef int						int16_st;
	typedef long int				int32_st;
	typedef long long int			int64_st;

	typedef unsigned char			size_t;   // Default type for SIZE.
	typedef unsigned char			size8_t;
	typedef unsigned int			size16_t;
	typedef unsigned long int       size32_t;
	typedef unsigned long long int  size64_t;
}

#endif