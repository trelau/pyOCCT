#ifndef __Standard_Templates_Header__
#define __Standard_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_Assert.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\Standard_Assert.hxx
template <bool condition>
void bind_Standard_Static_Assert(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\Standard_Assert.hxx
	py::class_<Standard_Static_Assert<condition>, std::unique_ptr<Standard_Static_Assert<condition>, Deleter<Standard_Static_Assert<condition>>>> cls(mod, name.c_str(), "Static assert -- empty default template");
	cls.def(py::init<>());

};

#endif