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
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_NamedShape.hxx>
#include <TDF_LabelMap.hxx>
#include <TDF_AttributeMap.hxx>
#include <TNaming_Selector.hxx>

void bind_TNaming_Selector(py::module &mod){

py::class_<TNaming_Selector, std::unique_ptr<TNaming_Selector>> cls_TNaming_Selector(mod, "TNaming_Selector", "This class provides a single API for selection of shapes. This involves both identification and selection of shapes in the data framework. If the selected shape is modified, this selector will solve its identifications. This class is the user interface for topological naming resources. * The <IsIdentified> method returns (if exists) the NamedShape which contains a given shape. The definition of an identified shape is : a Shape handled by a NamedShape (this shape is the only one stored) , which has the TNaming_PRImITIVE evolution");

// Constructors
cls_TNaming_Selector.def(py::init<const TDF_Label &>(), py::arg("aLabel"));

// Fields

// Methods
// cls_TNaming_Selector.def_static("operator new_", (void * (*)(size_t)) &TNaming_Selector::operator new, "None", py::arg("theSize"));
// cls_TNaming_Selector.def_static("operator delete_", (void (*)(void *)) &TNaming_Selector::operator delete, "None", py::arg("theAddress"));
// cls_TNaming_Selector.def_static("operator new[]_", (void * (*)(size_t)) &TNaming_Selector::operator new[], "None", py::arg("theSize"));
// cls_TNaming_Selector.def_static("operator delete[]_", (void (*)(void *)) &TNaming_Selector::operator delete[], "None", py::arg("theAddress"));
// cls_TNaming_Selector.def_static("operator new_", (void * (*)(size_t, void *)) &TNaming_Selector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TNaming_Selector.def_static("operator delete_", (void (*)(void *, void *)) &TNaming_Selector::operator delete, "None", py::arg(""), py::arg(""));
cls_TNaming_Selector.def_static("IsIdentified_", [](const TDF_Label & a0, const TopoDS_Shape & a1, opencascade::handle<TNaming_NamedShape> & a2) -> Standard_Boolean { return TNaming_Selector::IsIdentified(a0, a1, a2); });
cls_TNaming_Selector.def_static("IsIdentified_", (Standard_Boolean (*)(const TDF_Label &, const TopoDS_Shape &, opencascade::handle<TNaming_NamedShape> &, const Standard_Boolean)) &TNaming_Selector::IsIdentified, "To know if a shape is already identified (not selected) =======================================================", py::arg("access"), py::arg("selection"), py::arg("NS"), py::arg("Geometry"));
cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> Standard_Boolean { return self.Select(a0, a1); });
cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const Standard_Boolean a2) -> Standard_Boolean { return self.Select(a0, a1, a2); });
cls_TNaming_Selector.def("Select", (Standard_Boolean (TNaming_Selector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean) const) &TNaming_Selector::Select, "Creates a topological naming on the label aLabel given as an argument at construction time. If successful, the shape Selection - found in the shape Context - is now identified in the named shape returned in NamedShape. If Geometry is true, NamedShape contains the first appearance of Selection. This syntax is more robust than the previous syntax for this method.", py::arg("Selection"), py::arg("Context"), py::arg("Geometry"), py::arg("KeepOrientatation"));
cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.Select(a0); });
cls_TNaming_Selector.def("Select", [](TNaming_Selector &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Select(a0, a1); });
cls_TNaming_Selector.def("Select", (Standard_Boolean (TNaming_Selector::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean) const) &TNaming_Selector::Select, "Creates a topological naming on the label aLabel given as an argument at construction time. If successful, the shape Selection is now identified in the named shape returned in NamedShape. If Geometry is true, NamedShape contains the first appearance of Selection.", py::arg("Selection"), py::arg("Geometry"), py::arg("KeepOrientatation"));
cls_TNaming_Selector.def("Solve", (Standard_Boolean (TNaming_Selector::*)(TDF_LabelMap &) const) &TNaming_Selector::Solve, "Updates the topological naming on the label aLabel given as an argument at construction time. The underlying shape returned in the method NamedShape is updated. To read this shape, use the method TNaming_Tool::GetShape", py::arg("Valid"));
cls_TNaming_Selector.def("Arguments", (void (TNaming_Selector::*)(TDF_AttributeMap &) const) &TNaming_Selector::Arguments, "Returns the attribute list args. This list contains the named shape on which the topological naming was built.", py::arg("args"));
cls_TNaming_Selector.def("NamedShape", (opencascade::handle<TNaming_NamedShape> (TNaming_Selector::*)() const) &TNaming_Selector::NamedShape, "Returns the NamedShape build or under construction, which contains the topological naming..");

// Enums

}