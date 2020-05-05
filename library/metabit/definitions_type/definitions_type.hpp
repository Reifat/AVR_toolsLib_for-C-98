/*
 * Автор Reifat
 * GitHub Repository - https://github.com/Reifat
 * Последние изменения 30.04.2020.
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
	typedef char					int8_t;
	typedef int						int16_t;
	typedef long int				int32_t;
	typedef long long int			int64_t;

	typedef unsigned char			size_t;   // Default type for SIZE.
	typedef unsigned char			size8_t;
	typedef unsigned int			size16_t;
	typedef unsigned long int       size32_t;
	typedef unsigned long long int  size64_t;
}

#endif