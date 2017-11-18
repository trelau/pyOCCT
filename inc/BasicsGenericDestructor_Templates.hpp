#ifndef __BasicsGenericDestructor_Templates_Header__
#define __BasicsGenericDestructor_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <BasicsGenericDestructor.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
template <typename TYPE>
void bind_DESTRUCTOR_OF(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
	py::class_<DESTRUCTOR_OF<TYPE>, std::unique_ptr<DESTRUCTOR_OF<TYPE>, Deleter<DESTRUCTOR_OF<TYPE>>>, GENERIC_DESTRUCTOR> cls(mod, name.c_str(), "The DESTRUCTOR_OF class allows the user to program - at any moment - the destruction of an object at the end of the process.");
	cls.def(py::init<TYPE &>(), py::arg("anObject"));
	cls.def("__call__", (void (DESTRUCTOR_OF<TYPE>::*)()) &DESTRUCTOR_OF<TYPE>::operator(), py::is_operator(), "Performs the destruction of the object. This method really destroys the object pointed by _objectPtr. It should be called at the end of the process (i.e. at exit).");

};

#endif