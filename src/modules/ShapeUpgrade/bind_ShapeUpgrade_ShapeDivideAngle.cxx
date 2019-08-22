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
#include <ShapeUpgrade_ShapeDivide.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapeUpgrade_ShapeDivideAngle.hxx>

void bind_ShapeUpgrade_ShapeDivideAngle(py::module &mod){

py::class_<ShapeUpgrade_ShapeDivideAngle, ShapeUpgrade_ShapeDivide> cls_ShapeUpgrade_ShapeDivideAngle(mod, "ShapeUpgrade_ShapeDivideAngle", "Splits all surfaces of revolution, cylindrical, toroidal, conical, spherical surfaces in the given shape so that each resulting segment covers not more than defined number of degrees (to segments less than 90).");

// Constructors
cls_ShapeUpgrade_ShapeDivideAngle.def(py::init<const Standard_Real>(), py::arg("MaxAngle"));
cls_ShapeUpgrade_ShapeDivideAngle.def(py::init<const Standard_Real, const TopoDS_Shape &>(), py::arg("MaxAngle"), py::arg("S"));

// Fields

// Methods
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator new_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideAngle::operator new, "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator delete_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideAngle::operator delete, "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator new[]_", (void * (*)(size_t)) &ShapeUpgrade_ShapeDivideAngle::operator new[], "None", py::arg("theSize"));
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator delete[]_", (void (*)(void *)) &ShapeUpgrade_ShapeDivideAngle::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeUpgrade_ShapeDivideAngle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeUpgrade_ShapeDivideAngle.def_static("operator delete_", (void (*)(void *, void *)) &ShapeUpgrade_ShapeDivideAngle::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeUpgrade_ShapeDivideAngle.def("InitTool", (void (ShapeUpgrade_ShapeDivideAngle::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideAngle::InitTool, "Resets tool for splitting face with given angle", py::arg("MaxAngle"));
cls_ShapeUpgrade_ShapeDivideAngle.def("SetMaxAngle", (void (ShapeUpgrade_ShapeDivideAngle::*)(const Standard_Real)) &ShapeUpgrade_ShapeDivideAngle::SetMaxAngle, "Set maximal angle (calls InitTool)", py::arg("MaxAngle"));
cls_ShapeUpgrade_ShapeDivideAngle.def("MaxAngle", (Standard_Real (ShapeUpgrade_ShapeDivideAngle::*)() const) &ShapeUpgrade_ShapeDivideAngle::MaxAngle, "Returns maximal angle");

// Enums

}