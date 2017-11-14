#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <LocalTraceBufferPool.hxx>
#include <BasicsGenericDestructor.hxx>

PYBIND11_MODULE(LocalTraceBufferPool, mod) {

	// IMPORT
	py::module::import("OCCT.BasicsGenericDestructor");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\LocalTraceBufferPool.hxx
	py::class_<LocalTrace_TraceInfo, std::unique_ptr<LocalTrace_TraceInfo, Deleter<LocalTrace_TraceInfo>>> cls_LocalTrace_TraceInfo(mod, "LocalTrace_TraceInfo", "None");
	cls_LocalTrace_TraceInfo.def(py::init<>());

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\LocalTraceBufferPool.hxx
	py::class_<LocalTraceBufferPool, std::unique_ptr<LocalTraceBufferPool, py::nodelete>, PROTECTED_DELETE> cls_LocalTraceBufferPool(mod, "LocalTraceBufferPool", "None");
	cls_LocalTraceBufferPool.def_static("instance_", (LocalTraceBufferPool * (*)()) &LocalTraceBufferPool::instance, "None");
	cls_LocalTraceBufferPool.def("insert", (int (LocalTraceBufferPool::*)(int, const char *)) &LocalTraceBufferPool::insert, "None", py::arg("traceType"), py::arg("msg"));
	cls_LocalTraceBufferPool.def("retrieve", (int (LocalTraceBufferPool::*)(LocalTrace_TraceInfo &)) &LocalTraceBufferPool::retrieve, "None", py::arg("aTrace"));
	cls_LocalTraceBufferPool.def("toCollect", (unsigned long (LocalTraceBufferPool::*)()) &LocalTraceBufferPool::toCollect, "None");


}
