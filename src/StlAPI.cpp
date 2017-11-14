#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <StlAPI_Writer.hxx>
#include <StlAPI_Reader.hxx>
#include <StlAPI.hxx>

PYBIND11_MODULE(StlAPI, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StlAPI_Writer.hxx
	py::class_<StlAPI_Writer, std::unique_ptr<StlAPI_Writer, Deleter<StlAPI_Writer>>> cls_StlAPI_Writer(mod, "StlAPI_Writer", "This class creates and writes STL files from Open CASCADE shapes. An STL file can be written to an existing STL file or to a new one.");
	cls_StlAPI_Writer.def(py::init<>());
	cls_StlAPI_Writer.def("ASCIIMode", (Standard_Boolean & (StlAPI_Writer::*)()) &StlAPI_Writer::ASCIIMode, "Returns the address to the flag defining the mode for writing the file. This address may be used to either read or change the flag. If the mode returns True (default value) the generated file is an ASCII file. If the mode returns False, the generated file is a binary file.");
	cls_StlAPI_Writer.def("Write", (Standard_Boolean (StlAPI_Writer::*)(const TopoDS_Shape &, const Standard_CString)) &StlAPI_Writer::Write, "Converts a given shape to STL format and writes it to file with a given filename.", py::arg("theShape"), py::arg("theFileName"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StlAPI_Reader.hxx
	py::class_<StlAPI_Reader, std::unique_ptr<StlAPI_Reader, Deleter<StlAPI_Reader>>> cls_StlAPI_Reader(mod, "StlAPI_Reader", "Reading from stereolithography format.");
	cls_StlAPI_Reader.def(py::init<>());
	cls_StlAPI_Reader.def("Read", (Standard_Boolean (StlAPI_Reader::*)(TopoDS_Shape &, const Standard_CString)) &StlAPI_Reader::Read, "Reads STL file to the TopoDS_Shape (each triangle is converted to the face).", py::arg("theShape"), py::arg("theFileName"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StlAPI.hxx
	py::class_<StlAPI, std::unique_ptr<StlAPI, Deleter<StlAPI>>> cls_StlAPI(mod, "StlAPI", "Offers the API for STL data manipulation.");
	cls_StlAPI.def(py::init<>());
	cls_StlAPI.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> Standard_Boolean { return StlAPI::Write(a0, a1); }, py::arg("theShape"), py::arg("theFile"));
	cls_StlAPI.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString, const Standard_Boolean)) &StlAPI::Write, "Convert and write shape to STL format. File is written in binary if aAsciiMode is False otherwise it is written in Ascii (by default).", py::arg("theShape"), py::arg("theFile"), py::arg("theAsciiMode"));
	cls_StlAPI.def_static("Read_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_CString)) &StlAPI::Read, "None", py::arg("theShape"), py::arg("aFile"));


}
