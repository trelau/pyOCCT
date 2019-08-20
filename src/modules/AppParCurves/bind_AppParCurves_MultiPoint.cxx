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
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <AppParCurves_MultiPoint.hxx>

void bind_AppParCurves_MultiPoint(py::module &mod){

py::class_<AppParCurves_MultiPoint, std::unique_ptr<AppParCurves_MultiPoint>> cls_AppParCurves_MultiPoint(mod, "AppParCurves_MultiPoint", "This class describes Points composing a MultiPoint. These points can be 2D or 3D. The user must first give the 3D Points and then the 2D Points. They are Poles of a Bezier Curve. This class is used either to define data input or results when performing the approximation of several lines in parallel.");

// Constructors
cls_AppParCurves_MultiPoint.def(py::init<>());
cls_AppParCurves_MultiPoint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("NbPoints"), py::arg("NbPoints2d"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("tabP"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("tabP2d"));
cls_AppParCurves_MultiPoint.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &>(), py::arg("tabP"), py::arg("tabP2d"));

// Fields

// Methods
// cls_AppParCurves_MultiPoint.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiPoint::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiPoint.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiPoint::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiPoint::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiPoint.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiPoint.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiPoint.def("SetPoint", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt &)) &AppParCurves_MultiPoint::SetPoint, "the 3d Point of range Index of this MultiPoint is set to <Point>. An exception is raised if Index < 0 or Index > number of 3d Points.", py::arg("Index"), py::arg("Point"));
cls_AppParCurves_MultiPoint.def("Point", (const gp_Pnt & (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Point, "returns the 3d Point of range Index. An exception is raised if Index < 0 or Index < number of 3d Points.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("SetPoint2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const gp_Pnt2d &)) &AppParCurves_MultiPoint::SetPoint2d, "The 2d Point of range Index is set to <Point>. An exception is raised if Index > 3d Points or Index > total number of Points.", py::arg("Index"), py::arg("Point"));
cls_AppParCurves_MultiPoint.def("Point2d", (const gp_Pnt2d & (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Point2d, "returns the 2d Point of range Index. An exception is raised if index <= number of 3d Points or Index > total number of Points.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("Dimension", (Standard_Integer (AppParCurves_MultiPoint::*)(const Standard_Integer) const) &AppParCurves_MultiPoint::Dimension, "returns the dimension of the point of range Index. An exception is raised if Index <0 or Index > NbCurves.", py::arg("Index"));
cls_AppParCurves_MultiPoint.def("NbPoints", (Standard_Integer (AppParCurves_MultiPoint::*)() const) &AppParCurves_MultiPoint::NbPoints, "returns the number of points of dimension 3D.");
cls_AppParCurves_MultiPoint.def("NbPoints2d", (Standard_Integer (AppParCurves_MultiPoint::*)() const) &AppParCurves_MultiPoint::NbPoints2d, "returns the number of points of dimension 2D.");
cls_AppParCurves_MultiPoint.def("Transform", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
cls_AppParCurves_MultiPoint.def("Transform2d", (void (AppParCurves_MultiPoint::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiPoint::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
cls_AppParCurves_MultiPoint.def("Dump", (void (AppParCurves_MultiPoint::*)(Standard_OStream &) const) &AppParCurves_MultiPoint::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}