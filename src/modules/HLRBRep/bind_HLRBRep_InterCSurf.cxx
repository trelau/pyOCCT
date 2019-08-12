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
#include <IntCurveSurface_Intersection.hxx>
#include <Standard.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <HLRBRep_InterCSurf.hxx>

void bind_HLRBRep_InterCSurf(py::module &mod){

py::class_<HLRBRep_InterCSurf, std::unique_ptr<HLRBRep_InterCSurf, Deleter<HLRBRep_InterCSurf>>, IntCurveSurface_Intersection> cls_HLRBRep_InterCSurf(mod, "HLRBRep_InterCSurf", "None");

// Constructors
cls_HLRBRep_InterCSurf.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_InterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_InterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_InterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_InterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_InterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_InterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_InterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_InterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_InterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_InterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const Standard_Address &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface", py::arg("Curve"), py::arg("Surface"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given.", py::arg("Curve"), py::arg("Polygon"), py::arg("Surface"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"), py::arg("BndBSB"));
cls_HLRBRep_InterCSurf.def("Perform", (void (HLRBRep_InterCSurf::*)(const gp_Lin &, const Standard_Address &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_InterCSurf::Perform, "Compute the Intersection between the curve and the surface. The Surface is already sampled and its polyhedron : <Polyhedron> is given.", py::arg("Curve"), py::arg("Surface"), py::arg("Polyhedron"));

// Enums

}