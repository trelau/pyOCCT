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
#include <TopoDS_ListOfShape.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Iterator.hxx>

void bind_TopoDS_Iterator(py::module &mod){

py::class_<TopoDS_Iterator> cls_TopoDS_Iterator(mod, "TopoDS_Iterator", "Iterates on the underlying shape underlying a given TopoDS_Shape object, providing access to its component sub-shapes. Each component shape is returned as a TopoDS_Shape with an orientation, and a compound of the original values and the relative values.");

// Constructors
cls_TopoDS_Iterator.def(py::init<>());
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("cumOri"));
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("cumOri"), py::arg("cumLoc"));

// Fields

// Methods
// cls_TopoDS_Iterator.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Iterator::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Iterator.def_static("operator delete_", (void (*)(void *)) &TopoDS_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Iterator::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Iterator.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS_Iterator.def("Initialize", [](TopoDS_Iterator &self, const TopoDS_Shape & a0) -> void { return self.Initialize(a0); });
cls_TopoDS_Iterator.def("Initialize", [](TopoDS_Iterator &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Initialize(a0, a1); });
cls_TopoDS_Iterator.def("Initialize", (void (TopoDS_Iterator::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &TopoDS_Iterator::Initialize, "Initializes this iterator with shape S. Note: - If cumOri is true, the function composes all sub-shapes with the orientation of S. - If cumLoc is true, the function multiplies all sub-shapes by the location of S, i.e. it applies to each sub-shape the transformation that is associated with S.", py::arg("S"), py::arg("cumOri"), py::arg("cumLoc"));
cls_TopoDS_Iterator.def("More", (Standard_Boolean (TopoDS_Iterator::*)() const) &TopoDS_Iterator::More, "Returns true if there is another sub-shape in the shape which this iterator is scanning.");
cls_TopoDS_Iterator.def("Next", (void (TopoDS_Iterator::*)()) &TopoDS_Iterator::Next, "Moves on to the next sub-shape in the shape which this iterator is scanning. Exceptions Standard_NoMoreObject if there are no more sub-shapes in the shape.");
cls_TopoDS_Iterator.def("Value", (const TopoDS_Shape & (TopoDS_Iterator::*)() const) &TopoDS_Iterator::Value, "Returns the current sub-shape in the shape which this iterator is scanning. Exceptions Standard_NoSuchObject if there is no current sub-shape.");

// Enums

}