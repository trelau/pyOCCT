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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Blend_CSFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <BRepBlend_Line.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Blend_Status.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Blend_Point.hxx>
#include <BRepBlend_CSWalking.hxx>

void bind_BRepBlend_CSWalking(py::module &mod){

py::class_<BRepBlend_CSWalking, std::unique_ptr<BRepBlend_CSWalking, Deleter<BRepBlend_CSWalking>>> cls_BRepBlend_CSWalking(mod, "BRepBlend_CSWalking", "None");

// Constructors
cls_BRepBlend_CSWalking.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Curv"), py::arg("Surf"), py::arg("Domain"));

// Fields

// Methods
// cls_BRepBlend_CSWalking.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_CSWalking::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_CSWalking.def_static("operator delete_", (void (*)(void *)) &BRepBlend_CSWalking::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_CSWalking::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_CSWalking.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_CSWalking::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_CSWalking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_CSWalking.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_CSWalking::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_CSWalking.def("Perform", [](BRepBlend_CSWalking &self, Blend_CSFunction & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const math_Vector & a5, const Standard_Real a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_BRepBlend_CSWalking.def("Perform", (void (BRepBlend_CSWalking::*)(Blend_CSFunction &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_CSWalking::Perform, "None", py::arg("F"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_CSWalking.def("Complete", (Standard_Boolean (BRepBlend_CSWalking::*)(Blend_CSFunction &, const Standard_Real)) &BRepBlend_CSWalking::Complete, "None", py::arg("F"), py::arg("Pmin"));
cls_BRepBlend_CSWalking.def("IsDone", (Standard_Boolean (BRepBlend_CSWalking::*)() const) &BRepBlend_CSWalking::IsDone, "None");
cls_BRepBlend_CSWalking.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_CSWalking::*)() const) &BRepBlend_CSWalking::Line, "None");

// Enums

}