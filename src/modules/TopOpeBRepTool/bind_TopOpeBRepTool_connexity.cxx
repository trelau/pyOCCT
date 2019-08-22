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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_Array1OfListOfShape.hxx>
#include <TopOpeBRepTool_connexity.hxx>

void bind_TopOpeBRepTool_connexity(py::module &mod){

py::class_<TopOpeBRepTool_connexity> cls_TopOpeBRepTool_connexity(mod, "TopOpeBRepTool_connexity", "None");

// Constructors
cls_TopOpeBRepTool_connexity.def(py::init<>());
cls_TopOpeBRepTool_connexity.def(py::init<const TopoDS_Shape &>(), py::arg("Key"));

// Fields

// Methods
// cls_TopOpeBRepTool_connexity.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_connexity::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_connexity::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_connexity::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_connexity::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_connexity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_connexity.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_connexity::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_connexity.def("SetKey", (void (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::SetKey, "None", py::arg("Key"));
cls_TopOpeBRepTool_connexity.def("Key", (const TopoDS_Shape & (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::Key, "None");
cls_TopOpeBRepTool_connexity.def("Item", (Standard_Integer (TopOpeBRepTool_connexity::*)(const Standard_Integer, TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::Item, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AllItems", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::AllItems, "None", py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopTools_ListOfShape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("AddItem", (void (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::AddItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const Standard_Integer, const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("OriKey"), py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("RemoveItem", (Standard_Boolean (TopOpeBRepTool_connexity::*)(const TopoDS_Shape &)) &TopOpeBRepTool_connexity::RemoveItem, "None", py::arg("Item"));
cls_TopOpeBRepTool_connexity.def("ChangeItem", (TopTools_ListOfShape & (TopOpeBRepTool_connexity::*)(const Standard_Integer)) &TopOpeBRepTool_connexity::ChangeItem, "None", py::arg("OriKey"));
cls_TopOpeBRepTool_connexity.def("IsMultiple", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::IsMultiple, "None");
cls_TopOpeBRepTool_connexity.def("IsFaulty", (Standard_Boolean (TopOpeBRepTool_connexity::*)() const) &TopOpeBRepTool_connexity::IsFaulty, "None");
cls_TopOpeBRepTool_connexity.def("IsInternal", (Standard_Integer (TopOpeBRepTool_connexity::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_connexity::IsInternal, "None", py::arg("Item"));

// Enums

}