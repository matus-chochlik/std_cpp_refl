
// --- TMP implementation ---
template <typename T>
struct add_const_TMP {
	using type = const T;
};

template <typename T>
struct add_const_TMP<const T> {
	using type = const T;
};

template <typename T>
using add_const_t_TMP = typename add_const_TMP<T>::type;

template <typename T>
struct add_pointer_TMP {
	using type = T*;
};

template <typename T>
using add_pointer_t_TMP = typename add_pointer_TMP<T>::type;

// --- CMP implementation ---

template <typename T>
struct identity {
	using type = T;
};

template <typename T>
constexpr identity<T> type = {};

template <typename T>
static constexpr inline
identity<const T> add_const_t_CMP(identity<T>) {
	return {};
}

template <typename T>
static constexpr inline
identity<const T> add_const_t_CMP(identity<const T>) {
	return {};
}

template <typename T>
static constexpr inline
identity<T*> add_pointer_t_CMP(identity<T>) {
	return {};
}

// --- TMP usage ---

template <typename T>
struct my_class_TMP {
	// Note this -- nice, clean, easily understandable
	add_pointer_t_TMP<add_const_t_TMP<T>> foo;
};

// --- CMP usage ---

template <typename T>
struct my_class_CMP {
	// Note this ugliness.
	// You cannot get around the `typename XXX::type` stuff
	// because the argument T can be "unconstructible",
	// so you have to wrap it into the identity template if
	// you want to return it from a function.
	typename decltype(add_pointer_t_CMP(add_const_t_CMP(type<T>)))::type foo;
};

// --- Use case ---

struct abstract {
	virtual ~abstract(void) = default;
	virtual void foo(void)  = 0;
};

int main(void) {
	my_class_TMP<abstract> xTMP = {nullptr};
	my_class_CMP<abstract> xCMP = {nullptr};

	return (xTMP.foo == xCMP.foo)?0:1;
}
