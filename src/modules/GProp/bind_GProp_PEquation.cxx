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
#include <TColgp_Array1OfPnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <gp_Lin.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GProp_EquaType.hxx>
#include <GProp_PEquation.hxx>

void bind_GProp_PEquation(py::module &mod){

py::class_<GProp_PEquation, std::unique_ptr<GProp_PEquation>> cls_GProp_PEquation(mod, "GProp_PEquation", "A framework to analyze a collection - or cloud - of points and to verify if they are coincident, collinear or coplanar within a given precision. If so, it also computes the mean point, the mean line or the mean plane of the points. If not, it computes the minimal box which includes all the points.");

// Constructors
cls_GProp_PEquation.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real>(), py::arg("Pnts"), py::arg("Tol"));

// Fields

// Methods
// cls_GProp_PEquation.def_static("operator new_", (void * (*)(size_t)) &GProp_PEquation::operator new, "None", py::arg("theSize"));
// cls_GProp_PEquation.def_static("operator delete_", (void (*)(void *)) &GProp_PEquation::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PEquation::operator new[], "None", py::arg("theSize"));
// cls_GProp_PEquation.def_static("operator delete[]_", (void (*)(void *)) &GProp_PEquation::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PEquation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PEquation::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PEquation.def("IsPlanar", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsPlanar, "Returns true if, according to the given tolerance, the points analyzed by this framework are coplanar. Use the function Plane to access the computed result.");
cls_GProp_PEquation.def("IsLinear", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsLinear, "Returns true if, according to the given tolerance, the points analyzed by this framework are colinear. Use the function Line to access the computed result.");
cls_GProp_PEquation.def("IsPoint", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsPoint, "Returns true if, according to the given tolerance, the points analyzed by this framework are coincident. Use the function Point to access the computed result.");
cls_GProp_PEquation.def("IsSpace", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsSpace, "Returns true if, according to the given tolerance value, the points analyzed by this framework are neither coincident, nor collinear, nor coplanar. Use the function Box to query the smallest box that includes the collection of points.");
cls_GProp_PEquation.def("Plane", (gp_Pln (GProp_PEquation::*)() const) &GProp_PEquation::Plane, "Returns the mean plane passing near all the points analyzed by this framework if, according to the given precision, the points are considered to be coplanar. Exceptions Standard_NoSuchObject if, according to the given precision value, the points analyzed by this framework are considered to be: - coincident, or - collinear, or - not coplanar.");
cls_GProp_PEquation.def("Line", (gp_Lin (GProp_PEquation::*)() const) &GProp_PEquation::Line, "Returns the mean line passing near all the points analyzed by this framework if, according to the given precision value, the points are considered to be collinear. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are considered to be: - coincident, or - not collinear.");
cls_GProp_PEquation.def("Point", (gp_Pnt (GProp_PEquation::*)() const) &GProp_PEquation::Point, "Returns the mean point of all the points analyzed by this framework if, according to the given precision, the points are considered to be coincident. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are not considered to be coincident.");
cls_GProp_PEquation.def("Box", (void (GProp_PEquation::*)(gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GProp_PEquation::Box, "Returns the definition of the smallest box which contains all the points analyzed by this framework if, according to the given precision value, the points are considered to be neither coincident, nor collinear and nor coplanar. This box is centered on the barycenter P of the collection of points. Its sides are parallel to the three vectors V1, V2 and V3, the length of which is the length of the box in the corresponding direction. Note: Vectors V1, V2 and V3 are parallel to the three axes of principal inertia of the system composed of the collection of points where each point is of equal mass. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are considered to be coincident, collinear or coplanar.", py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));

// Enums

}