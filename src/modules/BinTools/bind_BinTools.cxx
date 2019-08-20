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
#include <Standard.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_IStream.hxx>
#include <TopoDS_Shape.hxx>
#include <BinTools_ShapeSet.hxx>
#include <BinTools_Curve2dSet.hxx>
#include <BinTools_CurveSet.hxx>
#include <BinTools_SurfaceSet.hxx>
#include <BinTools_LocationSet.hxx>
#include <BinTools.hxx>

void bind_BinTools(py::module &mod){

py::class_<BinTools, std::unique_ptr<BinTools>> cls_BinTools(mod, "BinTools", "Tool to keep shapes in binary format");

// Constructors

// Fields

// Methods
// cls_BinTools.def_static("operator new_", (void * (*)(size_t)) &BinTools::operator new, "None", py::arg("theSize"));
// cls_BinTools.def_static("operator delete_", (void (*)(void *)) &BinTools::operator delete, "None", py::arg("theAddress"));
// cls_BinTools.def_static("operator new[]_", (void * (*)(size_t)) &BinTools::operator new[], "None", py::arg("theSize"));
// cls_BinTools.def_static("operator delete[]_", (void (*)(void *)) &BinTools::operator delete[], "None", py::arg("theAddress"));
// cls_BinTools.def_static("operator new_", (void * (*)(size_t, void *)) &BinTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinTools.def_static("operator delete_", (void (*)(void *, void *)) &BinTools::operator delete, "None", py::arg(""), py::arg(""));
cls_BinTools.def_static("PutReal_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Real)) &BinTools::PutReal, "None", py::arg("OS"), py::arg("theValue"));
cls_BinTools.def_static("PutInteger_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Integer)) &BinTools::PutInteger, "None", py::arg("OS"), py::arg("theValue"));
cls_BinTools.def_static("PutBool_", (Standard_OStream & (*)(Standard_OStream &, const Standard_Boolean)) &BinTools::PutBool, "None", py::arg("OS"), py::arg("theValue"));
cls_BinTools.def_static("PutExtChar_", (Standard_OStream & (*)(Standard_OStream &, const Standard_ExtCharacter)) &BinTools::PutExtChar, "None", py::arg("OS"), py::arg("theValue"));
cls_BinTools.def_static("GetReal_", [](Standard_IStream & IS, Standard_Real & theValue){ Standard_IStream & rv = BinTools::GetReal(IS, theValue); return std::tuple<Standard_IStream &, Standard_Real &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
cls_BinTools.def_static("GetInteger_", [](Standard_IStream & IS, Standard_Integer & theValue){ Standard_IStream & rv = BinTools::GetInteger(IS, theValue); return std::tuple<Standard_IStream &, Standard_Integer &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
cls_BinTools.def_static("GetBool_", [](Standard_IStream & IS, Standard_Boolean & theValue){ Standard_IStream & rv = BinTools::GetBool(IS, theValue); return std::tuple<Standard_IStream &, Standard_Boolean &>(rv, theValue); }, "None", py::arg("IS"), py::arg("theValue"));
cls_BinTools.def_static("GetExtChar_", (Standard_IStream & (*)(Standard_IStream &, Standard_ExtCharacter &)) &BinTools::GetExtChar, "None", py::arg("IS"), py::arg("theValue"));
cls_BinTools.def_static("Write_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &BinTools::Write, "Writes <theShape> on <theStream> in binary format.", py::arg("theShape"), py::arg("theStream"));
cls_BinTools.def_static("Read_", (void (*)(TopoDS_Shape &, Standard_IStream &)) &BinTools::Read, "Reads a shape from <theStream> and returns it in <theShape>.", py::arg("theShape"), py::arg("theStream"));
cls_BinTools.def_static("Write_", (Standard_Boolean (*)(const TopoDS_Shape &, const Standard_CString)) &BinTools::Write, "Writes <theShape> in <theFile>.", py::arg("theShape"), py::arg("theFile"));
cls_BinTools.def_static("Read_", (Standard_Boolean (*)(TopoDS_Shape &, const Standard_CString)) &BinTools::Read, "Reads a shape from <theFile> and returns it in <theShape>.", py::arg("theShape"), py::arg("theFile"));

// Enums

}