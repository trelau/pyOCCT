#ifndef __StdObjMgt_Templates_Header__
#define __StdObjMgt_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <StdObjMgt_Attribute.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_Attribute.hxx
template <typename Transient>
void bind_StdObjMgt_Attribute(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_Attribute.hxx
	py::class_<StdObjMgt_Attribute<Transient>, opencascade::handle<StdObjMgt_Attribute<Transient>>, Standard_Transient> cls(mod, name.c_str(), "Root class for a temporary persistent object corresponding to an attribute.");

};

#endif