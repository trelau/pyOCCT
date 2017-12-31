#ifndef __pyOCCT_Common_Header__
#define __pyOCCT_Common_Header__

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <boost/shared_ptr.hpp>

#include <Standard_Handle.hxx>

namespace py = pybind11;

// Use opencascade::handle as holder type for Standard_Transient types
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);

// Use boost::shared_ptr for some SMESH iterators
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

// Hack for a fix where the fully qualified name is not found
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#endif