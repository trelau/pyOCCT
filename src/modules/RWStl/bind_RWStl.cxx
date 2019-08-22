/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <OSD_Path.hxx>
#include <Message_ProgressIndicator.hxx>
#include <RWStl.hxx>

void bind_RWStl(py::module &mod){

py::class_<RWStl> cls_RWStl(mod, "RWStl", "This class provides methods to read and write triangulation from / to the STL files.");

// Constructors

// Fields

// Methods
cls_RWStl.def_static("WriteBinary_", [](const opencascade::handle<Poly_Triangulation> & a0, const OSD_Path & a1) -> Standard_Boolean { return RWStl::WriteBinary(a0, a1); });
cls_RWStl.def_static("WriteBinary_", (Standard_Boolean (*)(const opencascade::handle<Poly_Triangulation> &, const OSD_Path &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::WriteBinary, "Write triangulation to binary STL file. binary format of an STL file. Returns false if the cannot be opened;", py::arg("theMesh"), py::arg("thePath"), py::arg("theProgInd"));
cls_RWStl.def_static("WriteAscii_", [](const opencascade::handle<Poly_Triangulation> & a0, const OSD_Path & a1) -> Standard_Boolean { return RWStl::WriteAscii(a0, a1); });
cls_RWStl.def_static("WriteAscii_", (Standard_Boolean (*)(const opencascade::handle<Poly_Triangulation> &, const OSD_Path &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::WriteAscii, "write the meshing in a file following the Ascii format of an STL file. Returns false if the cannot be opened;", py::arg("theMesh"), py::arg("thePath"), py::arg("theProgInd"));
cls_RWStl.def_static("ReadFile_", [](const OSD_Path & a0) -> opencascade::handle<Poly_Triangulation> { return RWStl::ReadFile(a0); });
cls_RWStl.def_static("ReadFile_", (opencascade::handle<Poly_Triangulation> (*)(const OSD_Path &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::ReadFile, "Read specified STL file and returns its content as triangulation. In case of error, returns Null handle.", py::arg("theFile"), py::arg("aProgInd"));
cls_RWStl.def_static("ReadFile_", [](const Standard_CString a0) -> opencascade::handle<Poly_Triangulation> { return RWStl::ReadFile(a0); });
cls_RWStl.def_static("ReadFile_", (opencascade::handle<Poly_Triangulation> (*)(const Standard_CString, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::ReadFile, "Read specified STL file and returns its content as triangulation. In case of error, returns Null handle.", py::arg("theFile"), py::arg("aProgInd"));
cls_RWStl.def_static("ReadBinary_", [](const OSD_Path & a0) -> opencascade::handle<Poly_Triangulation> { return RWStl::ReadBinary(a0); });
cls_RWStl.def_static("ReadBinary_", (opencascade::handle<Poly_Triangulation> (*)(const OSD_Path &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::ReadBinary, "Read triangulation from a binary STL file In case of error, returns Null handle.", py::arg("thePath"), py::arg("theProgInd"));
cls_RWStl.def_static("ReadAscii_", [](const OSD_Path & a0) -> opencascade::handle<Poly_Triangulation> { return RWStl::ReadAscii(a0); });
cls_RWStl.def_static("ReadAscii_", (opencascade::handle<Poly_Triangulation> (*)(const OSD_Path &, const opencascade::handle<Message_ProgressIndicator> &)) &RWStl::ReadAscii, "Read triangulation from an Ascii STL file In case of error, returns Null handle.", py::arg("thePath"), py::arg("theProgInd"));

// Enums

}