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
#include <GeomFill_LocationLaw.hxx>
#include <Geom_Geometry.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Curve.hxx>
#include <gp_Mat.hxx>
#include <gp_Vec.hxx>
#include <gp_Ax1.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Extrema_ExtPC.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_SectionPlacement.hxx>

void bind_GeomFill_SectionPlacement(py::module &mod){

py::class_<GeomFill_SectionPlacement, std::unique_ptr<GeomFill_SectionPlacement>> cls_GeomFill_SectionPlacement(mod, "GeomFill_SectionPlacement", "To place section in sweep Function");

// Constructors
cls_GeomFill_SectionPlacement.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &, const opencascade::handle<Geom_Geometry> &>(), py::arg("L"), py::arg("Section"));

// Fields

// Methods
// cls_GeomFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SectionPlacement::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SectionPlacement.def_static("operator delete_", (void (*)(void *)) &GeomFill_SectionPlacement::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SectionPlacement::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SectionPlacement.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SectionPlacement::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SectionPlacement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SectionPlacement::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SectionPlacement.def("SetLocation", (void (GeomFill_SectionPlacement::*)(const opencascade::handle<GeomFill_LocationLaw> &)) &GeomFill_SectionPlacement::SetLocation, "To change the section Law", py::arg("L"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("Path"), py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const Standard_Real, const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("ParamOnPath"), py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("IsDone", (Standard_Boolean (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::IsDone, "None");
cls_GeomFill_SectionPlacement.def("ParameterOnPath", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::ParameterOnPath, "None");
cls_GeomFill_SectionPlacement.def("ParameterOnSection", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::ParameterOnSection, "None");
cls_GeomFill_SectionPlacement.def("Distance", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::Distance, "None");
cls_GeomFill_SectionPlacement.def("Angle", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::Angle, "None");
cls_GeomFill_SectionPlacement.def("Transformation", [](GeomFill_SectionPlacement &self, const Standard_Boolean a0) -> gp_Trsf { return self.Transformation(a0); });
cls_GeomFill_SectionPlacement.def("Transformation", (gp_Trsf (GeomFill_SectionPlacement::*)(const Standard_Boolean, const Standard_Boolean) const) &GeomFill_SectionPlacement::Transformation, "None", py::arg("WithTranslation"), py::arg("WithCorrection"));
cls_GeomFill_SectionPlacement.def("Section", (opencascade::handle<Geom_Curve> (GeomFill_SectionPlacement::*)(const Standard_Boolean) const) &GeomFill_SectionPlacement::Section, "Compute the Section, in the coordinate syteme given by the Location Law. If <WithTranslation> contact beetween <Section> and <Path> is forced.", py::arg("WithTranslation"));
cls_GeomFill_SectionPlacement.def("ModifiedSection", (opencascade::handle<Geom_Curve> (GeomFill_SectionPlacement::*)(const Standard_Boolean) const) &GeomFill_SectionPlacement::ModifiedSection, "Compute the Section, in the coordinate syteme given by the Location Law. To have the Normal to section equal to the Location Law Normal. If <WithTranslation> contact beetween <Section> and <Path> is forced.", py::arg("WithTranslation"));

// Enums

}