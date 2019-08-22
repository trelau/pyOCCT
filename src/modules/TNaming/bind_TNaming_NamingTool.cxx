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
#include <TDF_LabelMap.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TDF_Label.hxx>
#include <TopoDS_Shape.hxx>
#include <TNaming_NamingTool.hxx>

void bind_TNaming_NamingTool(py::module &mod){

py::class_<TNaming_NamingTool> cls_TNaming_NamingTool(mod, "TNaming_NamingTool", "None");

// Constructors

// Fields

// Methods
// cls_TNaming_NamingTool.def_static("operator new_", (void * (*)(size_t)) &TNaming_NamingTool::operator new, "None", py::arg("theSize"));
// cls_TNaming_NamingTool.def_static("operator delete_", (void (*)(void *)) &TNaming_NamingTool::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_NamingTool.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_NamingTool::operator new[], "None", py::arg("theSize"));
// cls_TNaming_NamingTool.def_static("operator delete[]_", (void (*)(void *)) &TNaming_NamingTool::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_NamingTool.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_NamingTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_NamingTool.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_NamingTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_NamingTool.def_static("CurrentShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const opencascade::handle<TNaming_NamedShape> &, TopTools_IndexedMapOfShape &)) &TNaming_NamingTool::CurrentShape, "None", py::arg("Valid"), py::arg("Forbiden"), py::arg("NS"), py::arg("MS"));
cls_TNaming_NamingTool.def_static("CurrentShapeFromShape_", (void (*)(const TDF_LabelMap &, const TDF_LabelMap &, const TDF_Label &, const TopoDS_Shape &, TopTools_IndexedMapOfShape &)) &TNaming_NamingTool::CurrentShapeFromShape, "None", py::arg("Valid"), py::arg("Forbiden"), py::arg("Acces"), py::arg("S"), py::arg("MS"));
cls_TNaming_NamingTool.def_static("BuildDescendants_", (void (*)(const opencascade::handle<TNaming_NamedShape> &, TDF_LabelMap &)) &TNaming_NamingTool::BuildDescendants, "None", py::arg("NS"), py::arg("Labels"));

// Enums

}