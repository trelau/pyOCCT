#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BaseTraceCollector.hxx>

PYBIND11_MODULE(BaseTraceCollector, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BaseTraceCollector.hxx
	py::class_<BaseTraceCollector, std::unique_ptr<BaseTraceCollector, Deleter<BaseTraceCollector>>> cls_BaseTraceCollector(mod, "BaseTraceCollector", "See derived Classes in SALOMELocalTrace for usage without CORBA, see derived Classes in SALOMETraceCollector for usage with CORBA.");


}
