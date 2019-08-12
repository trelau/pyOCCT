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
#include <GeomAbs_CurveType.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <ProjLib_Projector.hxx>

void bind_ProjLib_Projector(py::module &mod){

py::class_<ProjLib_Projector, std::unique_ptr<ProjLib_Projector, Deleter<ProjLib_Projector>>> cls_ProjLib_Projector(mod, "ProjLib_Projector", "Root class for projection algorithms, stores the result.");

// Constructors
cls_ProjLib_Projector.def(py::init<>());

// Fields

// Methods
// cls_ProjLib_Projector.def_static("operator new_", (void * (*)(size_t)) &ProjLib_Projector::operator new, "None", py::arg("theSize"));
// cls_ProjLib_Projector.def_static("operator delete_", (void (*)(void *)) &ProjLib_Projector::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_Projector.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_Projector::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_Projector.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_Projector::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_Projector.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_Projector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_Projector.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_Projector::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib_Projector.def("IsDone", (Standard_Boolean (ProjLib_Projector::*)() const) &ProjLib_Projector::IsDone, "None");
cls_ProjLib_Projector.def("Done", (void (ProjLib_Projector::*)()) &ProjLib_Projector::Done, "Set isDone = Standard_True;");
cls_ProjLib_Projector.def("GetType", (GeomAbs_CurveType (ProjLib_Projector::*)() const) &ProjLib_Projector::GetType, "None");
cls_ProjLib_Projector.def("SetBSpline", (void (ProjLib_Projector::*)(const opencascade::handle<Geom2d_BSplineCurve> &)) &ProjLib_Projector::SetBSpline, "None", py::arg("C"));
cls_ProjLib_Projector.def("SetBezier", (void (ProjLib_Projector::*)(const opencascade::handle<Geom2d_BezierCurve> &)) &ProjLib_Projector::SetBezier, "None", py::arg("C"));
cls_ProjLib_Projector.def("SetType", (void (ProjLib_Projector::*)(const GeomAbs_CurveType)) &ProjLib_Projector::SetType, "None", py::arg("Type"));
cls_ProjLib_Projector.def("IsPeriodic", (Standard_Boolean (ProjLib_Projector::*)() const) &ProjLib_Projector::IsPeriodic, "None");
cls_ProjLib_Projector.def("SetPeriodic", (void (ProjLib_Projector::*)()) &ProjLib_Projector::SetPeriodic, "None");
cls_ProjLib_Projector.def("Line", (const gp_Lin2d & (ProjLib_Projector::*)() const) &ProjLib_Projector::Line, "None");
cls_ProjLib_Projector.def("Circle", (const gp_Circ2d & (ProjLib_Projector::*)() const) &ProjLib_Projector::Circle, "None");
cls_ProjLib_Projector.def("Ellipse", (const gp_Elips2d & (ProjLib_Projector::*)() const) &ProjLib_Projector::Ellipse, "None");
cls_ProjLib_Projector.def("Hyperbola", (const gp_Hypr2d & (ProjLib_Projector::*)() const) &ProjLib_Projector::Hyperbola, "None");
cls_ProjLib_Projector.def("Parabola", (const gp_Parab2d & (ProjLib_Projector::*)() const) &ProjLib_Projector::Parabola, "None");
cls_ProjLib_Projector.def("Bezier", (opencascade::handle<Geom2d_BezierCurve> (ProjLib_Projector::*)() const) &ProjLib_Projector::Bezier, "None");
cls_ProjLib_Projector.def("BSpline", (opencascade::handle<Geom2d_BSplineCurve> (ProjLib_Projector::*)() const) &ProjLib_Projector::BSpline, "None");
cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Lin &)) &ProjLib_Projector::Project, "None", py::arg("L"));
cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Circ &)) &ProjLib_Projector::Project, "None", py::arg("C"));
cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Elips &)) &ProjLib_Projector::Project, "None", py::arg("E"));
cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Parab &)) &ProjLib_Projector::Project, "None", py::arg("P"));
cls_ProjLib_Projector.def("Project", (void (ProjLib_Projector::*)(const gp_Hypr &)) &ProjLib_Projector::Project, "None", py::arg("H"));
cls_ProjLib_Projector.def("UFrame", (void (ProjLib_Projector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ProjLib_Projector::UFrame, "Translates the 2d curve to set the part of the curve [CFirst, CLast] in the range [ UFirst, UFirst + Period [", py::arg("CFirst"), py::arg("CLast"), py::arg("UFirst"), py::arg("Period"));
cls_ProjLib_Projector.def("VFrame", (void (ProjLib_Projector::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ProjLib_Projector::VFrame, "Translates the 2d curve to set the part of the curve [CFirst, CLast] in the range [ VFirst, VFirst + Period [", py::arg("CFirst"), py::arg("CLast"), py::arg("VFirst"), py::arg("Period"));

// Enums

}