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
#include <AppParCurves_Array1OfMultiPoint.hxx>
#include <AppParCurves_MultiPoint.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfMultiPoint.hxx>
#include <AppParCurves_MultiCurve.hxx>

void bind_AppParCurves_MultiCurve(py::module &mod){

py::class_<AppParCurves_MultiCurve, std::unique_ptr<AppParCurves_MultiCurve>> cls_AppParCurves_MultiCurve(mod, "AppParCurves_MultiCurve", "This class describes a MultiCurve approximating a Multiline. As a Multiline is a set of n lines, a MultiCurve is a set of n curves. These curves are Bezier curves. A MultiCurve is composed of m MultiPoint. The approximating degree of these n curves is the same for each one.");

// Constructors
cls_AppParCurves_MultiCurve.def(py::init<>());
cls_AppParCurves_MultiCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
cls_AppParCurves_MultiCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &>(), py::arg("tabMU"));

// Fields

// Methods
// cls_AppParCurves_MultiCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiCurve.def("SetNbPoles", (void (AppParCurves_MultiCurve::*)(const Standard_Integer)) &AppParCurves_MultiCurve::SetNbPoles, "The number of poles of the MultiCurve will be set to <nbPoles>.", py::arg("nbPoles"));
cls_AppParCurves_MultiCurve.def("SetValue", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const AppParCurves_MultiPoint &)) &AppParCurves_MultiCurve::SetValue, "sets the MultiPoint of range Index to the value <MPoint>. An exception is raised if Index <0 or Index >NbMPoint.", py::arg("Index"), py::arg("MPoint"));
cls_AppParCurves_MultiCurve.def("NbCurves", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::NbCurves, "Returns the number of curves resulting from the approximation of a MultiLine.");
cls_AppParCurves_MultiCurve.def("NbPoles", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::NbPoles, "Returns the number of poles on curves resulting from the approximation of a MultiLine.");
cls_AppParCurves_MultiCurve.def("Degree", (Standard_Integer (AppParCurves_MultiCurve::*)() const) &AppParCurves_MultiCurve::Degree, "returns the degree of the curves.");
cls_AppParCurves_MultiCurve.def("Dimension", (Standard_Integer (AppParCurves_MultiCurve::*)(const Standard_Integer) const) &AppParCurves_MultiCurve::Dimension, "returns the dimension of the CuIndex curve. An exception is raised if CuIndex<0 or CuIndex>NbCurves.", py::arg("CuIndex"));
cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 2d.", py::arg("CuIndex"), py::arg("TabPnt"));
cls_AppParCurves_MultiCurve.def("Curve", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, TColgp_Array1OfPnt2d &) const) &AppParCurves_MultiCurve::Curve, "returns the Pole array of the curve of range CuIndex. An exception is raised if the dimension of the curve is 3d.", py::arg("CuIndex"), py::arg("TabPnt"));
cls_AppParCurves_MultiCurve.def("Value", (const AppParCurves_MultiPoint & (AppParCurves_MultiCurve::*)(const Standard_Integer) const) &AppParCurves_MultiCurve::Value, "returns the Index MultiPoint. An exception is raised if Index <0 or Index >Degree+1.", py::arg("Index"));
cls_AppParCurves_MultiCurve.def("Pole", (const gp_Pnt & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const) &AppParCurves_MultiCurve::Pole, "returns the Nieme pole of the CuIndex curve. the curve must be a 3D curve.", py::arg("CuIndex"), py::arg("Nieme"));
cls_AppParCurves_MultiCurve.def("Pole2d", (const gp_Pnt2d & (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Integer) const) &AppParCurves_MultiCurve::Pole2d, "returns the Nieme pole of the CuIndex curve. the curve must be a 2D curve.", py::arg("CuIndex"), py::arg("Nieme"));
cls_AppParCurves_MultiCurve.def("Transform", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform, "Applies a transformation to the curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve. newz = z + dz*oldz", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"), py::arg("z"), py::arg("dz"));
cls_AppParCurves_MultiCurve.def("Transform2d", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AppParCurves_MultiCurve::Transform2d, "Applies a transformation to the Curve of range <CuIndex>. newx = x + dx*oldx newy = y + dy*oldy for all points of the curve.", py::arg("CuIndex"), py::arg("x"), py::arg("dx"), py::arg("y"), py::arg("dy"));
cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiCurve.def("Value", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const) &AppParCurves_MultiCurve::Value, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiCurve.def("D1", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &AppParCurves_MultiCurve::D1, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiCurve.def("D2", (void (AppParCurves_MultiCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &AppParCurves_MultiCurve::D2, "returns the value of the point with a parameter U on the Bezier curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiCurve.def("Dump", (void (AppParCurves_MultiCurve::*)(Standard_OStream &) const) &AppParCurves_MultiCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}