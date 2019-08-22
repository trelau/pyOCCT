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
#include <Bnd_Box.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <HLRBRep_ThePolygonToolOfInterCSurf.hxx>

void bind_HLRBRep_ThePolygonToolOfInterCSurf(py::module &mod){

py::class_<HLRBRep_ThePolygonToolOfInterCSurf> cls_HLRBRep_ThePolygonToolOfInterCSurf(mod, "HLRBRep_ThePolygonToolOfInterCSurf", "None");

// Constructors

// Fields

// Methods
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolygonToolOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Bounding_", (const Bnd_Box & (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Bounding, "Give the bounding box of the polygon.", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::DeflectionOverEstimation, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Closed_", (Standard_Boolean (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Closed, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("NbSegments_", (Standard_Integer (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::NbSegments, "None", py::arg("thePolygon"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("BeginOfSeg_", (const gp_Pnt & (*)(const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Integer)) &HLRBRep_ThePolygonToolOfInterCSurf::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("EndOfSeg_", (const gp_Pnt & (*)(const HLRBRep_ThePolygonOfInterCSurf &, const Standard_Integer)) &HLRBRep_ThePolygonToolOfInterCSurf::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_HLRBRep_ThePolygonToolOfInterCSurf.def_static("Dump_", (void (*)(const HLRBRep_ThePolygonOfInterCSurf &)) &HLRBRep_ThePolygonToolOfInterCSurf::Dump, "None", py::arg("thePolygon"));

// Enums

}