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
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <gp_Pnt.hxx>
#include <CPnts_UniformDeflection.hxx>

void bind_CPnts_UniformDeflection(py::module &mod){

py::class_<CPnts_UniformDeflection, std::unique_ptr<CPnts_UniformDeflection, Deleter<CPnts_UniformDeflection>>> cls_CPnts_UniformDeflection(mod, "CPnts_UniformDeflection", "This class defines an algorithm to create a set of points (with a given chordal deviation) at the positions of constant deflection of a given parametrized curve or a trimmed circle. The continuity of the curve must be at least C2.");

// Constructors
cls_CPnts_UniformDeflection.def(py::init<>());
cls_CPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));

// Fields

// Methods
// cls_CPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t)) &CPnts_UniformDeflection::operator new, "None", py::arg("theSize"));
// cls_CPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *)) &CPnts_UniformDeflection::operator delete, "None", py::arg("theAddress"));
// cls_CPnts_UniformDeflection.def_static("operator new[]_", (void * (*)(size_t)) &CPnts_UniformDeflection::operator new[], "None", py::arg("theSize"));
// cls_CPnts_UniformDeflection.def_static("operator delete[]_", (void (*)(void *)) &CPnts_UniformDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_CPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &CPnts_UniformDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *, void *)) &CPnts_UniformDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <Resolution> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <Resolution> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <U1>, <U2> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def("Initialize", (void (CPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &CPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <UStep>, <U1>, <U2> and <WithControl>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Resolution"), py::arg("WithControl"));
cls_CPnts_UniformDeflection.def("IsAllDone", (Standard_Boolean (CPnts_UniformDeflection::*)() const) &CPnts_UniformDeflection::IsAllDone, "To know if all the calculus were done successfully (ie all the points have been computed). The calculus can fail if the Curve is not C1 in the considered domain. Returns True if the calculus was successful.");
cls_CPnts_UniformDeflection.def("Next", (void (CPnts_UniformDeflection::*)()) &CPnts_UniformDeflection::Next, "go to the next Point.");
cls_CPnts_UniformDeflection.def("More", (Standard_Boolean (CPnts_UniformDeflection::*)()) &CPnts_UniformDeflection::More, "returns True if it exists a next Point.");
cls_CPnts_UniformDeflection.def("Value", (Standard_Real (CPnts_UniformDeflection::*)() const) &CPnts_UniformDeflection::Value, "return the computed parameter");
cls_CPnts_UniformDeflection.def("Point", (gp_Pnt (CPnts_UniformDeflection::*)() const) &CPnts_UniformDeflection::Point, "return the computed parameter");

// Enums

}