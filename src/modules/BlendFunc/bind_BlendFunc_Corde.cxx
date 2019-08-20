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
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Pnt2d.hxx>
#include <BlendFunc_Corde.hxx>

void bind_BlendFunc_Corde(py::module &mod){

py::class_<BlendFunc_Corde, std::unique_ptr<BlendFunc_Corde>> cls_BlendFunc_Corde(mod, "BlendFunc_Corde", "This function calculates point (pts) on the curve of intersection between the normal to a curve (guide) in a chosen parameter and a surface (surf), so that pts was at a given distance from the guide. X(1),X(2) are the parameters U,V of pts on surf.");

// Constructors
cls_BlendFunc_Corde.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("CGuide"));

// Fields

// Methods
// cls_BlendFunc_Corde.def_static("operator new_", (void * (*)(size_t)) &BlendFunc_Corde::operator new, "None", py::arg("theSize"));
// cls_BlendFunc_Corde.def_static("operator delete_", (void (*)(void *)) &BlendFunc_Corde::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc_Corde.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc_Corde::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc_Corde.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc_Corde::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc_Corde.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc_Corde::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc_Corde.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc_Corde::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc_Corde.def("SetParam", (void (BlendFunc_Corde::*)(const Standard_Real)) &BlendFunc_Corde::SetParam, "None", py::arg("Param"));
cls_BlendFunc_Corde.def("SetDist", (void (BlendFunc_Corde::*)(const Standard_Real)) &BlendFunc_Corde::SetDist, "None", py::arg("Dist"));
cls_BlendFunc_Corde.def("Value", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, math_Vector &)) &BlendFunc_Corde::Value, "computes the values <F> of the Function for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_BlendFunc_Corde.def("Derivatives", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Corde::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_BlendFunc_Corde.def("PointOnS", (const gp_Pnt & (BlendFunc_Corde::*)() const) &BlendFunc_Corde::PointOnS, "None");
cls_BlendFunc_Corde.def("PointOnGuide", (const gp_Pnt & (BlendFunc_Corde::*)() const) &BlendFunc_Corde::PointOnGuide, "returns the point of parameter <Param> on CGuide");
cls_BlendFunc_Corde.def("NPlan", (const gp_Vec & (BlendFunc_Corde::*)() const) &BlendFunc_Corde::NPlan, "returns the normal to CGuide at Ptgui.");
cls_BlendFunc_Corde.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Corde::*)() const) &BlendFunc_Corde::IsTangencyPoint, "Returns True when it is not possible to compute the tangent vectors at PointOnS.");
cls_BlendFunc_Corde.def("TangentOnS", (const gp_Vec & (BlendFunc_Corde::*)() const) &BlendFunc_Corde::TangentOnS, "Returns the tangent vector at PointOnS, in 3d space.");
cls_BlendFunc_Corde.def("Tangent2dOnS", (const gp_Vec2d & (BlendFunc_Corde::*)() const) &BlendFunc_Corde::Tangent2dOnS, "Returns the tangent vector at PointOnS, in the parametric space of the first surface.");
cls_BlendFunc_Corde.def("DerFguide", (void (BlendFunc_Corde::*)(const math_Vector &, gp_Vec2d &)) &BlendFunc_Corde::DerFguide, "Derived of the function compared to the parameter of the guideline", py::arg("Sol"), py::arg("DerF"));
cls_BlendFunc_Corde.def("IsSolution", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Corde::IsSolution, "Returns False if Sol is not solution else returns True and updates the fields tgs and tg2d", py::arg("Sol"), py::arg("Tol"));

// Enums

}