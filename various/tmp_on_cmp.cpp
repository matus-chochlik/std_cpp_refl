namespace cmp {

template <typename T>
struct identity {
	using type = T;
};

template <bool B>
struct bool_t {
	static constexpr const bool value = B;

	explicit constexpr inline
	operator bool (void) const { return B; }
};

template <typename T>
constexpr const identity<T> type = {};

template <typename T>
static constexpr inline
identity<const T> add_const_t(identity<T>) {
	return {};
}

template <typename T>
static constexpr inline
identity<const T> add_const_t(identity<const T>) {
	return {};
}

template <typename T>
static constexpr inline
identity<T*> add_pointer_t(identity<T>) {
	return {};
}

template <typename T>
static constexpr inline
bool_t<false> is_pointer_v(identity<T>) {
	return {};
}

template <typename T>
static constexpr inline
bool_t<true> is_pointer_v(identity<T*>) {
	return {};
}

} // namespace cmp

namespace tmp {

template <typename T>
struct add_const
 : decltype(cmp::add_const_t(cmp::type<T>))
{ };

template <typename T>
using add_const_t = typename add_const<T>::type;

template <typename T>
struct add_pointer
 : decltype(cmp::add_pointer_t(cmp::type<T>))
{ };

template <typename T>
using add_pointer_t = typename add_pointer<T>::type;

template <typename T>
struct is_pointer
 : decltype(cmp::is_pointer_v(cmp::type<T>))
{ };

template <typename T>
constexpr const bool is_pointer_v = is_pointer<T>::value;

} // namespace tmp


// --- TMP usage ---

template <typename T>
struct my_class_TMP {

	tmp::add_pointer_t<tmp::add_const_t<T>> foo;
	static_assert(tmp::is_pointer_v<decltype(foo)>, "");
};

// --- CMP usage ---

template <typename T>
struct my_class_CMP {

	typename decltype(
		cmp::add_pointer_t(cmp::add_const_t(cmp::type<T>))
	)::type foo;
	static_assert(cmp::is_pointer_v(cmp::type<decltype(foo)>), "");
};

// --- Use case ---

struct abstract {
	virtual ~abstract(void) = default;
	virtual void bar(void)  = 0;
};

int main(void) {
	my_class_TMP<abstract> xTMP = {nullptr};
	my_class_CMP<abstract> xCMP = {nullptr};

	return (xTMP.foo == xCMP.foo)?0:1;
}
