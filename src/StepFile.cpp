#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <StepFile_Read.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepModel.hxx>
#include <StepData_Protocol.hxx>

PYBIND11_MODULE(StepFile, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFile_Read.hxx
	mod.def("StepFile_ReadTrace", (void (*)(const Standard_Integer)) &StepFile_ReadTrace, "None", py::arg("mode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepFile_Read.hxx
	mod.def("StepFile_Read", (Standard_Integer (*)(char *, const opencascade::handle<StepData_StepModel> &, const opencascade::handle<StepData_Protocol> &)) &StepFile_Read, "None", py::arg("nomfic"), py::arg("stepmodel"), py::arg("protocol"));


	// CLASSES

}
