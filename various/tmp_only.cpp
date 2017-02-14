
template <typename T>
struct add_const {
	using type = const T;
};

template <typename T>
struct add_const<const T> {
	using type = const T;
};

template <typename T>
using add_const_t = typename add_const<T>::type;

template <typename T>
struct add_pointer {
	using type = T*;
};

template <typename T>
using add_pointer_t = typename add_pointer<T>::type;


template <typename T>
struct my_class {
	add_pointer_t<add_const_t<T>> foo;
};

struct abstract {
	virtual ~abstract(void) = default;
	virtual void foo(void)  = 0;
};

int main(void) {
	my_class<abstract> x = {nullptr};

	return (x.foo == nullptr)?0:1;
}
