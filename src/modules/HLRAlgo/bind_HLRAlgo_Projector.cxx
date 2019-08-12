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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin.hxx>
#include <HLRAlgo_Projector.hxx>

void bind_HLRAlgo_Projector(py::module &mod){

py::class_<HLRAlgo_Projector, std::unique_ptr<HLRAlgo_Projector, Deleter<HLRAlgo_Projector>>> cls_HLRAlgo_Projector(mod, "HLRAlgo_Projector", "Implements a projector object. To transform and project Points and Planes. This object is designed to be used in the removal of hidden lines and is returned by the Prs3d_Projector::Projector function. You define the projection of the selected shape by calling one of the following functions: - HLRBRep_Algo::Projector, or - HLRBRep_PolyAlgo::Projector The choice depends on the algorithm, which you are using. The parameters of the view are defined at the time of construction of a Prs3d_Projector object.");

// Constructors
cls_HLRAlgo_Projector.def(py::init<>());
cls_HLRAlgo_Projector.def(py::init<const gp_Ax2 &>(), py::arg("CS"));
cls_HLRAlgo_Projector.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("CS"), py::arg("Focus"));
cls_HLRAlgo_Projector.def(py::init<const gp_Trsf &, const Standard_Boolean, const Standard_Real>(), py::arg("T"), py::arg("Persp"), py::arg("Focus"));
cls_HLRAlgo_Projector.def(py::init<const gp_Trsf &, const Standard_Boolean, const Standard_Real, const gp_Vec2d &, const gp_Vec2d &, const gp_Vec2d &>(), py::arg("T"), py::arg("Persp"), py::arg("Focus"), py::arg("v1"), py::arg("v2"), py::arg("v3"));

// Fields

// Methods
// cls_HLRAlgo_Projector.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Projector::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Projector.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Projector::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Projector::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Projector.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Projector::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Projector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Projector.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Projector::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Projector.def("Set", (void (HLRAlgo_Projector::*)(const gp_Trsf &, const Standard_Boolean, const Standard_Real)) &HLRAlgo_Projector::Set, "None", py::arg("T"), py::arg("Persp"), py::arg("Focus"));
cls_HLRAlgo_Projector.def("Directions", (void (HLRAlgo_Projector::*)(gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &HLRAlgo_Projector::Directions, "None", py::arg("D1"), py::arg("D2"), py::arg("D3"));
cls_HLRAlgo_Projector.def("Scaled", [](HLRAlgo_Projector &self) -> void { return self.Scaled(); });
cls_HLRAlgo_Projector.def("Scaled", (void (HLRAlgo_Projector::*)(const Standard_Boolean)) &HLRAlgo_Projector::Scaled, "to compute with the given scale and translation.", py::arg("On"));
cls_HLRAlgo_Projector.def("Perspective", (Standard_Boolean (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Perspective, "Returns True if there is a perspective transformation.");
cls_HLRAlgo_Projector.def("Transformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Transformation, "Returns the active transformation.");
cls_HLRAlgo_Projector.def("InvertedTransformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::InvertedTransformation, "Returns the active inverted transformation.");
cls_HLRAlgo_Projector.def("FullTransformation", (const gp_Trsf & (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::FullTransformation, "Returns the original transformation.");
cls_HLRAlgo_Projector.def("Focus", (Standard_Real (HLRAlgo_Projector::*)() const) &HLRAlgo_Projector::Focus, "Returns the focal length.");
cls_HLRAlgo_Projector.def("Transform", (void (HLRAlgo_Projector::*)(gp_Vec &) const) &HLRAlgo_Projector::Transform, "None", py::arg("D"));
cls_HLRAlgo_Projector.def("Transform", (void (HLRAlgo_Projector::*)(gp_Pnt &) const) &HLRAlgo_Projector::Transform, "None", py::arg("Pnt"));
cls_HLRAlgo_Projector.def("Project", (void (HLRAlgo_Projector::*)(const gp_Pnt &, gp_Pnt2d &) const) &HLRAlgo_Projector::Project, "Transform and apply perspective if needed.", py::arg("P"), py::arg("Pout"));
cls_HLRAlgo_Projector.def("Project", [](HLRAlgo_Projector &self, const gp_Pnt & P, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Project(P, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Transform and apply perspective if needed.", py::arg("P"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_HLRAlgo_Projector.def("Project", (void (HLRAlgo_Projector::*)(const gp_Pnt &, const gp_Vec &, gp_Pnt2d &, gp_Vec2d &) const) &HLRAlgo_Projector::Project, "Transform and apply perspective if needed.", py::arg("P"), py::arg("D1"), py::arg("Pout"), py::arg("D1out"));
cls_HLRAlgo_Projector.def("Shoot", (gp_Lin (HLRAlgo_Projector::*)(const Standard_Real, const Standard_Real) const) &HLRAlgo_Projector::Shoot, "return a line going through the eye towards the 2d point <X,Y>.", py::arg("X"), py::arg("Y"));

// Enums

}