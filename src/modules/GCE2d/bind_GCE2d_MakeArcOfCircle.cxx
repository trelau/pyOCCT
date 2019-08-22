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
#include <GCE2d_Root.hxx>
#include <Standard.hxx>
#include <gp_Circ2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <GCE2d_MakeArcOfCircle.hxx>

void bind_GCE2d_MakeArcOfCircle(py::module &mod){

py::class_<GCE2d_MakeArcOfCircle, GCE2d_Root> cls_GCE2d_MakeArcOfCircle(mod, "GCE2d_MakeArcOfCircle", "Implements construction algorithms for an arc of circle in the plane. The result is a Geom2d_TrimmedCurve curve. A MakeArcOfCircle object provides a framework for: - defining the construction of the arc of circle, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of circle.");

// Constructors
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Circ"), py::arg("Alpha1"), py::arg("Alpha2"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Circ"), py::arg("P"), py::arg("Alpha"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Boolean>(), py::arg("Circ"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("Circ"), py::arg("P1"), py::arg("P2"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Circ2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean>(), py::arg("Circ"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GCE2d_MakeArcOfCircle.def(py::init<const gp_Pnt2d &, const gp_Vec2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("V"), py::arg("P2"));

// Fields

// Methods
// cls_GCE2d_MakeArcOfCircle.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeArcOfCircle::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeArcOfCircle.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeArcOfCircle::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeArcOfCircle.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeArcOfCircle::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeArcOfCircle.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeArcOfCircle::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeArcOfCircle.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeArcOfCircle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeArcOfCircle.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeArcOfCircle::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeArcOfCircle.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (GCE2d_MakeArcOfCircle::*)() const) &GCE2d_MakeArcOfCircle::Value, "Returns the constructed arc of circle. Exceptions StdFail_NotDone if no arc of circle is constructed.");

// Enums

}