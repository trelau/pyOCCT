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
#include <gp_Pnt.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Convert_ElementarySurfaceToBSplineSurface.hxx>

void bind_Convert_ElementarySurfaceToBSplineSurface(py::module &mod){

py::class_<Convert_ElementarySurfaceToBSplineSurface, std::unique_ptr<Convert_ElementarySurfaceToBSplineSurface, Deleter<Convert_ElementarySurfaceToBSplineSurface>>> cls_Convert_ElementarySurfaceToBSplineSurface(mod, "Convert_ElementarySurfaceToBSplineSurface", "Root class for algorithms which convert an elementary surface (cylinder, cone, sphere or torus) into a BSpline surface (CylinderToBSplineSurface, ConeToBSplineSurface, SphereToBSplineSurface, TorusToBSplineSurface). These algorithms all work on elementary surfaces from the gp package and compute all the data needed to construct a BSpline surface equivalent to the cylinder, cone, sphere or torus. This data consists of the following: - degrees in the u and v parametric directions, - periodic characteristics in the u and v parametric directions, - a poles table with associated weights, - a knots table (for the u and v parametric directions) with associated multiplicities. The abstract class ElementarySurfaceToBSplineSurface provides a framework for storing and consulting this computed data. This data may then be used to construct a Geom_BSplineSurface surface, for example. All those classes define algorithmes to convert an ElementarySurface into a B-spline surface. This abstract class implements the methods to get the geometric representation of the B-spline surface. The B-spline representation is computed at the creation time in the sub classes. The B-spline surface is defined with its degree in the parametric U and V directions, its control points (Poles), its weights, its knots and their multiplicity. KeyWords : Convert, ElementarySurface, BSplineSurface.");

// Constructors

// Fields

// Methods
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator new_", (void * (*)(size_t)) &Convert_ElementarySurfaceToBSplineSurface::operator new, "None", py::arg("theSize"));
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator delete_", (void (*)(void *)) &Convert_ElementarySurfaceToBSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &Convert_ElementarySurfaceToBSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &Convert_ElementarySurfaceToBSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_ElementarySurfaceToBSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_ElementarySurfaceToBSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &Convert_ElementarySurfaceToBSplineSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_ElementarySurfaceToBSplineSurface.def("UDegree", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::UDegree, "None");
cls_Convert_ElementarySurfaceToBSplineSurface.def("VDegree", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::VDegree, "Returns the degree for the u or v parametric direction of the BSpline surface whose data is computed in this framework.");
cls_Convert_ElementarySurfaceToBSplineSurface.def("NbUPoles", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::NbUPoles, "None");
cls_Convert_ElementarySurfaceToBSplineSurface.def("NbVPoles", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::NbVPoles, "Returns the number of poles for the u or v parametric direction of the BSpline surface whose data is computed in this framework.");
cls_Convert_ElementarySurfaceToBSplineSurface.def("NbUKnots", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::NbUKnots, "None");
cls_Convert_ElementarySurfaceToBSplineSurface.def("NbVKnots", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::NbVKnots, "Returns the number of knots for the u or v parametric direction of the BSpline surface whose data is computed in this framework .");
cls_Convert_ElementarySurfaceToBSplineSurface.def("IsUPeriodic", (Standard_Boolean (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::IsUPeriodic, "None");
cls_Convert_ElementarySurfaceToBSplineSurface.def("IsVPeriodic", (Standard_Boolean (Convert_ElementarySurfaceToBSplineSurface::*)() const) &Convert_ElementarySurfaceToBSplineSurface::IsVPeriodic, "Returns true if the BSpline surface whose data is computed in this framework is periodic in the u or v parametric direction.");
cls_Convert_ElementarySurfaceToBSplineSurface.def("Pole", (gp_Pnt (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::Pole, "Returns the pole of index (UIndex,VIndex) to the poles table of the BSpline surface whose data is computed in this framework. Exceptions Standard_OutOfRange if, for the BSpline surface whose data is computed in this framework: - UIndex is outside the bounds of the poles table in the u parametric direction, or - VIndex is outside the bounds of the poles table in the v parametric direction.", py::arg("UIndex"), py::arg("VIndex"));
cls_Convert_ElementarySurfaceToBSplineSurface.def("Weight", (Standard_Real (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::Weight, "Returns the weight of the pole of index (UIndex,VIndex) to the poles table of the BSpline surface whose data is computed in this framework. Exceptions Standard_OutOfRange if, for the BSpline surface whose data is computed in this framework: - UIndex is outside the bounds of the poles table in the u parametric direction, or - VIndex is outside the bounds of the poles table in the v parametric direction.", py::arg("UIndex"), py::arg("VIndex"));
cls_Convert_ElementarySurfaceToBSplineSurface.def("UKnot", (Standard_Real (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::UKnot, "Returns the U-knot of range UIndex. Raised if UIndex < 1 or UIndex > NbUKnots.", py::arg("UIndex"));
cls_Convert_ElementarySurfaceToBSplineSurface.def("VKnot", (Standard_Real (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::VKnot, "Returns the V-knot of range VIndex. Raised if VIndex < 1 or VIndex > NbVKnots.", py::arg("UIndex"));
cls_Convert_ElementarySurfaceToBSplineSurface.def("UMultiplicity", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::UMultiplicity, "Returns the multiplicity of the U-knot of range UIndex. Raised if UIndex < 1 or UIndex > NbUKnots.", py::arg("UIndex"));
cls_Convert_ElementarySurfaceToBSplineSurface.def("VMultiplicity", (Standard_Integer (Convert_ElementarySurfaceToBSplineSurface::*)(const Standard_Integer) const) &Convert_ElementarySurfaceToBSplineSurface::VMultiplicity, "Returns the multiplicity of the V-knot of range VIndex. Raised if VIndex < 1 or VIndex > NbVKnots.", py::arg("VIndex"));

// Enums

}