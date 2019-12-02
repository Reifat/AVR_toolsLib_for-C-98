template<typename T1, typename T2>
struct IsSameT
{
	static const bool value = false;
};
template<typename T>
struct IsSameT<T, T>
{
	static const bool value = true;
};