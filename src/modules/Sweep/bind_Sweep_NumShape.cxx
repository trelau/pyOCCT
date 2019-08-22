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
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <Sweep_NumShape.hxx>

void bind_Sweep_NumShape(py::module &mod){

py::class_<Sweep_NumShape> cls_Sweep_NumShape(mod, "Sweep_NumShape", "Gives a simple indexed representation of a Directing Edge topology.");

// Constructors
cls_Sweep_NumShape.def(py::init<>());
cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum>(), py::arg("Index"), py::arg("Type"));
cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"));
cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"));
cls_Sweep_NumShape.def(py::init<const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"), py::arg("EndInf"));

// Fields

// Methods
// cls_Sweep_NumShape.def_static("operator new_", (void * (*)(size_t)) &Sweep_NumShape::operator new, "None", py::arg("theSize"));
// cls_Sweep_NumShape.def_static("operator delete_", (void (*)(void *)) &Sweep_NumShape::operator delete, "None", py::arg("theAddress"));
// cls_Sweep_NumShape.def_static("operator new[]_", (void * (*)(size_t)) &Sweep_NumShape::operator new[], "None", py::arg("theSize"));
// cls_Sweep_NumShape.def_static("operator delete[]_", (void (*)(void *)) &Sweep_NumShape::operator delete[], "None", py::arg("theAddress"));
// cls_Sweep_NumShape.def_static("operator new_", (void * (*)(size_t, void *)) &Sweep_NumShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Sweep_NumShape.def_static("operator delete_", (void (*)(void *, void *)) &Sweep_NumShape::operator delete, "None", py::arg(""), py::arg(""));
cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1) -> void { return self.Init(a0, a1); });
cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1, const Standard_Boolean a2) -> void { return self.Init(a0, a1, a2); });
cls_Sweep_NumShape.def("Init", [](Sweep_NumShape &self, const Standard_Integer a0, const TopAbs_ShapeEnum a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_Sweep_NumShape.def("Init", (void (Sweep_NumShape::*)(const Standard_Integer, const TopAbs_ShapeEnum, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &Sweep_NumShape::Init, "Reinitialize a simple indexed edge.", py::arg("Index"), py::arg("Type"), py::arg("Closed"), py::arg("BegInf"), py::arg("EndInf"));
cls_Sweep_NumShape.def("Index", (Standard_Integer (Sweep_NumShape::*)() const) &Sweep_NumShape::Index, "None");
cls_Sweep_NumShape.def("Type", (TopAbs_ShapeEnum (Sweep_NumShape::*)() const) &Sweep_NumShape::Type, "None");
cls_Sweep_NumShape.def("Closed", (Standard_Boolean (Sweep_NumShape::*)() const) &Sweep_NumShape::Closed, "None");
cls_Sweep_NumShape.def("BegInfinite", (Standard_Boolean (Sweep_NumShape::*)() const) &Sweep_NumShape::BegInfinite, "None");
cls_Sweep_NumShape.def("EndInfinite", (Standard_Boolean (Sweep_NumShape::*)() const) &Sweep_NumShape::EndInfinite, "None");
cls_Sweep_NumShape.def("Orientation", (TopAbs_Orientation (Sweep_NumShape::*)() const) &Sweep_NumShape::Orientation, "None");

// Enums

}