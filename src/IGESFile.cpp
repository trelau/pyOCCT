#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <IGESFile_Read.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_FileRecognizer.hxx>

PYBIND11_MODULE(IGESFile, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IGESData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESFile_Read.hxx
	mod.def("IGESFile_Read", (Standard_Integer (*)(char *, const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &, const opencascade::handle<IGESData_FileRecognizer> &, const Standard_Boolean)) &IGESFile_Read, "None", py::arg("nomfic"), py::arg("amodel"), py::arg("protocol"), py::arg("reco"), py::arg("modefnes") = Standard_False);

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESFile_Read.hxx
	mod.def("IGESFile_ReadFNES", (Standard_Integer (*)(char *, const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &)) &IGESFile_ReadFNES, "None", py::arg("nomfic"), py::arg("amodel"), py::arg("protocol"));


	// CLASSES

}
