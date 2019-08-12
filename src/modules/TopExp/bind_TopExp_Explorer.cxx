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
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_TypeDef.hxx>
#include <TopExp_Stack.hxx>
#include <TopExp_Explorer.hxx>

void bind_TopExp_Explorer(py::module &mod){

py::class_<TopExp_Explorer, std::unique_ptr<TopExp_Explorer, Deleter<TopExp_Explorer>>> cls_TopExp_Explorer(mod, "TopExp_Explorer", "An Explorer is a Tool to visit a Topological Data Structure form the TopoDS package.");

// Constructors
cls_TopExp_Explorer.def(py::init<>());
cls_TopExp_Explorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"));
cls_TopExp_Explorer.def(py::init<const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum>(), py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));

// Fields

// Methods
// cls_TopExp_Explorer.def_static("operator new_", (void * (*)(size_t)) &TopExp_Explorer::operator new, "None", py::arg("theSize"));
// cls_TopExp_Explorer.def_static("operator delete_", (void (*)(void *)) &TopExp_Explorer::operator delete, "None", py::arg("theAddress"));
// cls_TopExp_Explorer.def_static("operator new[]_", (void * (*)(size_t)) &TopExp_Explorer::operator new[], "None", py::arg("theSize"));
// cls_TopExp_Explorer.def_static("operator delete[]_", (void (*)(void *)) &TopExp_Explorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopExp_Explorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopExp_Explorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopExp_Explorer.def_static("operator delete_", (void (*)(void *, void *)) &TopExp_Explorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopExp_Explorer.def("Init", [](TopExp_Explorer &self, const TopoDS_Shape & a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_TopExp_Explorer.def("Init", (void (TopExp_Explorer::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopExp_Explorer::Init, "Resets this explorer on the shape S. It is initialized to search the shape S, for shapes of type ToFind, that are not part of a shape ToAvoid. If the shape ToAvoid is equal to TopAbs_SHAPE, or if it is the same as, or less complex than, the shape ToFind it has no effect on the search.", py::arg("S"), py::arg("ToFind"), py::arg("ToAvoid"));
cls_TopExp_Explorer.def("More", (Standard_Boolean (TopExp_Explorer::*)() const) &TopExp_Explorer::More, "Returns True if there are more shapes in the exploration.");
cls_TopExp_Explorer.def("Next", (void (TopExp_Explorer::*)()) &TopExp_Explorer::Next, "Moves to the next Shape in the exploration. Exceptions Standard_NoMoreObject if there are no more shapes to explore.");
cls_TopExp_Explorer.def("Current", (const TopoDS_Shape & (TopExp_Explorer::*)() const) &TopExp_Explorer::Current, "Returns the current shape in the exploration. Exceptions Standard_NoSuchObject if this explorer has no more shapes to explore.");
cls_TopExp_Explorer.def("ReInit", (void (TopExp_Explorer::*)()) &TopExp_Explorer::ReInit, "Reinitialize the exploration with the original arguments.");
cls_TopExp_Explorer.def("Depth", (Standard_Integer (TopExp_Explorer::*)() const) &TopExp_Explorer::Depth, "Returns the current depth of the exploration. 0 is the shape to explore itself.");
cls_TopExp_Explorer.def("Clear", (void (TopExp_Explorer::*)()) &TopExp_Explorer::Clear, "Clears the content of the explorer. It will return False on More().");
cls_TopExp_Explorer.def("Destroy", (void (TopExp_Explorer::*)()) &TopExp_Explorer::Destroy, "None");

// Enums

}