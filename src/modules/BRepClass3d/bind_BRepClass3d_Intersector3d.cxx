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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <TopAbs_State.hxx>
#include <BRepClass3d_Intersector3d.hxx>

void bind_BRepClass3d_Intersector3d(py::module &mod){

py::class_<BRepClass3d_Intersector3d, std::unique_ptr<BRepClass3d_Intersector3d>> cls_BRepClass3d_Intersector3d(mod, "BRepClass3d_Intersector3d", "None");

// Constructors
cls_BRepClass3d_Intersector3d.def(py::init<>());

// Fields

// Methods
// cls_BRepClass3d_Intersector3d.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d_Intersector3d::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d_Intersector3d.def_static("operator delete_", (void (*)(void *)) &BRepClass3d_Intersector3d::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d_Intersector3d.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d_Intersector3d::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d_Intersector3d.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d_Intersector3d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d_Intersector3d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d_Intersector3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d_Intersector3d.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d_Intersector3d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d_Intersector3d.def("Perform", (void (BRepClass3d_Intersector3d::*)(const gp_Lin &, const Standard_Real, const Standard_Real, const TopoDS_Face &)) &BRepClass3d_Intersector3d::Perform, "Perform the intersection between the segment L(0) ... L(Prm) and the Shape <Sh>.", py::arg("L"), py::arg("Prm"), py::arg("Tol"), py::arg("F"));
cls_BRepClass3d_Intersector3d.def("IsDone", (Standard_Boolean (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::IsDone, "True is returned when the intersection have been computed.");
cls_BRepClass3d_Intersector3d.def("HasAPoint", (Standard_Boolean (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::HasAPoint, "True is returned if a point has been found.");
cls_BRepClass3d_Intersector3d.def("UParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::UParameter, "Returns the U parameter of the intersection point on the surface.");
cls_BRepClass3d_Intersector3d.def("VParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::VParameter, "Returns the V parameter of the intersection point on the surface.");
cls_BRepClass3d_Intersector3d.def("WParameter", (Standard_Real (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::WParameter, "Returns the parameter of the intersection point on the line.");
cls_BRepClass3d_Intersector3d.def("Pnt", (const gp_Pnt & (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::Pnt, "Returns the geometric point of the intersection between the line and the surface.");
cls_BRepClass3d_Intersector3d.def("Transition", (IntCurveSurface_TransitionOnCurve (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::Transition, "Returns the transition of the line on the surface.");
cls_BRepClass3d_Intersector3d.def("State", (TopAbs_State (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::State, "Returns the state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).");
cls_BRepClass3d_Intersector3d.def("Face", (const TopoDS_Face & (BRepClass3d_Intersector3d::*)() const) &BRepClass3d_Intersector3d::Face, "Returns the significant face used to determine the intersection.");

// Enums

}