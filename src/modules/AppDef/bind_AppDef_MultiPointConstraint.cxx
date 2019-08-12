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
#include <AppParCurves_MultiPoint.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <AppDef_MultiPointConstraint.hxx>

void bind_AppDef_MultiPointConstraint(py::module &mod){

py::class_<AppDef_MultiPointConstraint, std::unique_ptr<AppDef_MultiPointConstraint, Deleter<AppDef_MultiPointConstraint>>, AppParCurves_MultiPoint> cls_AppDef_MultiPointConstraint(mod, "AppDef_MultiPointConstraint", "Describes a MultiPointConstraint used in a Multiline. MultiPointConstraints are composed of several two or three-dimensional points. The purpose is to define the corresponding points that share a common constraint in order to compute the approximation of several lines in parallel. Notes: - The order of points of a MultiPointConstraints is very important. Users must give 3D points first, and then 2D points. - The constraints for the points included in a MultiPointConstraint are always identical for all points, including the parameter. - If a MultiPointConstraint is a 'tangency' point, the point is also a 'passing' point.");

// Constructors
cls_AppDef_MultiPointConstraint.def(py::init<>());
cls_AppDef_MultiPointConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("NbPoints"), py::arg("NbPoints2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &>(), py::arg("tabP"), py::arg("tabP2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &>(), py::arg("tabP"), py::arg("tabP2d"), py::arg("tabVec"), py::arg("tabVec2d"), py::arg("tabCur"), py::arg("tabCur2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec2d &>(), py::arg("tabP"), py::arg("tabP2d"), py::arg("tabVec"), py::arg("tabVec2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfVec &, const TColgp_Array1OfVec &>(), py::arg("tabP"), py::arg("tabVec"), py::arg("tabCur"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfVec &>(), py::arg("tabP"), py::arg("tabVec"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec2d &>(), py::arg("tabP2d"), py::arg("tabVec2d"));
cls_AppDef_MultiPointConstraint.def(py::init<const TColgp_Array1OfPnt2d &, const TColgp_Array1OfVec2d &, const TColgp_Array1OfVec2d &>(), py::arg("tabP2d"), py::arg("tabVec2d"), py::arg("tabCur2d"));

// Fields

// Methods
// cls_AppDef_MultiPointConstraint.def_static("operator new_", (void * (*)(size_t)) &AppDef_MultiPointConstraint::operator new, "None", py::arg("theSize"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete_", (void (*)(void *)) &AppDef_MultiPointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MultiPointConstraint::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MultiPointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MultiPointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MultiPointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MultiPointConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MultiPointConstraint.def("SetTang", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec &)) &AppDef_MultiPointConstraint::SetTang, "sets the value of the tangency of the point of range Index. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Tang has an incorrect number of dimensions.", py::arg("Index"), py::arg("Tang"));
cls_AppDef_MultiPointConstraint.def("Tang", (gp_Vec (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Tang, "returns the tangency value of the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetTang2d", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec2d &)) &AppDef_MultiPointConstraint::SetTang2d, "sets the value of the tangency of the point of range Index. An exception is raised if Index <number of 3d points or if Index > total number of Points An exception is raised if Tang has an incorrect number of dimensions.", py::arg("Index"), py::arg("Tang2d"));
cls_AppDef_MultiPointConstraint.def("Tang2d", (gp_Vec2d (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Tang2d, "returns the tangency value of the point of range Index. An exception is raised if Index < number of 3d points or if Index > total number of points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetCurv", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec &)) &AppDef_MultiPointConstraint::SetCurv, "Vec sets the value of the normal vector at the point of index Index. The norm of the normal vector at the point of position Index is set to the normal curvature. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Curv has an incorrect number of dimensions.", py::arg("Index"), py::arg("Curv"));
cls_AppDef_MultiPointConstraint.def("Curv", (gp_Vec (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Curv, "returns the normal vector at the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("SetCurv2d", (void (AppDef_MultiPointConstraint::*)(const Standard_Integer, const gp_Vec2d &)) &AppDef_MultiPointConstraint::SetCurv2d, "Vec sets the value of the normal vector at the point of index Index. The norm of the normal vector at the point of position Index is set to the normal curvature. An exception is raised if Index <0 or if Index > number of 3d points. An exception is raised if Curv has an incorrect number of dimensions.", py::arg("Index"), py::arg("Curv2d"));
cls_AppDef_MultiPointConstraint.def("Curv2d", (gp_Vec2d (AppDef_MultiPointConstraint::*)(const Standard_Integer) const) &AppDef_MultiPointConstraint::Curv2d, "returns the normal vector at the point of range Index. An exception is raised if Index < 0 or if Index > number of 3d points.", py::arg("Index"));
cls_AppDef_MultiPointConstraint.def("IsTangencyPoint", (Standard_Boolean (AppDef_MultiPointConstraint::*)() const) &AppDef_MultiPointConstraint::IsTangencyPoint, "returns True if the MultiPoint has a tangency value.");
cls_AppDef_MultiPointConstraint.def("IsCurvaturePoint", (Standard_Boolean (AppDef_MultiPointConstraint::*)() const) &AppDef_MultiPointConstraint::IsCurvaturePoint, "returns True if the MultiPoint has a curvature value.");
cls_AppDef_MultiPointConstraint.def("Dump", (void (AppDef_MultiPointConstraint::*)(Standard_OStream &) const) &AppDef_MultiPointConstraint::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}