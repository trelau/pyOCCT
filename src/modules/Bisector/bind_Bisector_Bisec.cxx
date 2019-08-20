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
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Bisector_Bisec.hxx>

void bind_Bisector_Bisec(py::module &mod){

py::class_<Bisector_Bisec, std::unique_ptr<Bisector_Bisec>> cls_Bisector_Bisec(mod, "Bisector_Bisec", "Bisec provides the bisecting line between two elements This line is trimed by a point <P> and it's contained in the domain defined by the two vectors <V1>, <V2> and <Sense>.");

// Constructors
cls_Bisector_Bisec.def(py::init<>());

// Fields

// Methods
// cls_Bisector_Bisec.def_static("operator new_", (void * (*)(size_t)) &Bisector_Bisec::operator new, "None", py::arg("theSize"));
// cls_Bisector_Bisec.def_static("operator delete_", (void (*)(void *)) &Bisector_Bisec::operator delete, "None", py::arg("theAddress"));
// cls_Bisector_Bisec.def_static("operator new[]_", (void * (*)(size_t)) &Bisector_Bisec::operator new[], "None", py::arg("theSize"));
// cls_Bisector_Bisec.def_static("operator delete[]_", (void (*)(void *)) &Bisector_Bisec::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector_Bisec.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector_Bisec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector_Bisec.def_static("operator delete_", (void (*)(void *, void *)) &Bisector_Bisec::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const GeomAbs_JoinType a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const GeomAbs_JoinType, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curves <Cu1> and <Cu2>. <oncurve> is True if the point <P> is common to <Cu1> and <Cu2>.", py::arg("Cu1"), py::arg("Cu2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("ajointype"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Curve> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curve <Cu1> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Cu"), py::arg("Pnt"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Curve> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the curve <Cu> and the point <Pnt>. <oncurve> is True if the point <P> is the point <Pnt>.", py::arg("Pnt"), py::arg("Cu"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_Bisector_Bisec.def("Perform", [](Bisector_Bisec &self, const opencascade::handle<Geom2d_Point> & a0, const opencascade::handle<Geom2d_Point> & a1, const gp_Pnt2d & a2, const gp_Vec2d & a3, const gp_Vec2d & a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_Bisector_Bisec.def("Perform", (void (Bisector_Bisec::*)(const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const gp_Pnt2d &, const gp_Vec2d &, const gp_Vec2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Bisec::Perform, "Performs the bisecting line between the two points <Pnt1> and <Pnt2>.", py::arg("Pnt1"), py::arg("Pnt2"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("Sense"), py::arg("Tolerance"), py::arg("oncurve"));
cls_Bisector_Bisec.def("Value", (const opencascade::handle<Geom2d_TrimmedCurve> & (Bisector_Bisec::*)() const) &Bisector_Bisec::Value, "Returns the Curve of <me>.");
cls_Bisector_Bisec.def("ChangeValue", (const opencascade::handle<Geom2d_TrimmedCurve> & (Bisector_Bisec::*)()) &Bisector_Bisec::ChangeValue, "Returns the Curve of <me>.");

// Enums

}