/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hpp>

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
