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
#include <Intf_Interference.hxx>
#include <Standard.hxx>
#include <HLRBRep_ThePolygonOfInterCSurf.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>
#include <gp_Lin.hxx>
#include <Intf_Array1OfLin.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <HLRBRep_TheInterferenceOfInterCSurf.hxx>

void bind_HLRBRep_TheInterferenceOfInterCSurf(py::module &mod){

py::class_<HLRBRep_TheInterferenceOfInterCSurf, std::unique_ptr<HLRBRep_TheInterferenceOfInterCSurf, Deleter<HLRBRep_TheInterferenceOfInterCSurf>>, Intf_Interference> cls_HLRBRep_TheInterferenceOfInterCSurf(mod, "HLRBRep_TheInterferenceOfInterCSurf", "None");

// Constructors
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<>());
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("thePolyg"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("theLin"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &>(), py::arg("theLins"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def(py::init<const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &>(), py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));

// Fields

// Methods
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_TheInterferenceOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_TheInterferenceOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_TheInterferenceOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_TheInterferenceOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Polygon and the Polyhedron.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const gp_Lin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Line and the Polyhedron.", py::arg("theLin"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Perform", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const Intf_Array1OfLin &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Perform, "Computes an interference between the Straight Lines and the Polyhedron.", py::arg("theLins"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Interference", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &, Bnd_BoundSortBox &)) &HLRBRep_TheInterferenceOfInterCSurf::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"), py::arg("theBoundSB"));
cls_HLRBRep_TheInterferenceOfInterCSurf.def("Interference", (void (HLRBRep_TheInterferenceOfInterCSurf::*)(const HLRBRep_ThePolygonOfInterCSurf &, const HLRBRep_ThePolyhedronOfInterCSurf &)) &HLRBRep_TheInterferenceOfInterCSurf::Interference, "Compares the boundings between the segment of <thePolyg> and the facets of <thePolyh>.", py::arg("thePolyg"), py::arg("thePolyh"));

// Enums

}