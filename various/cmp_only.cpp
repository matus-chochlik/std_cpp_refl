
// Note -- this is still TMP
template <typename T>
struct identity {
	using type = T;
};

template <typename T>
constexpr identity<T> type = {};

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
struct my_class {
	typename decltype(add_pointer_t(add_const_t(type<T>)))::type foo;
};

struct abstract {
	virtual ~abstract(void) = default;
	virtual void foo(void)  = 0;
};

int main(void) {
	my_class<abstract> x = {nullptr};

	return (x.foo == nullptr)?0:1;
}
